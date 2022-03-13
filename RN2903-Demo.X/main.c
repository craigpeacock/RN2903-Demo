
#include "mcc_generated_files/mcc.h"

// Sample code supports both methods of activation
//  * OTAA - Over The Air Activation (Preferred)
//  * ABP  - Activation by Personalisation
// See the following link for further information:
// https://www.thethingsnetwork.org/docs/lorawan/addressing/#activation
#define ACTIVATE_OTAA
//#define ACTIVATE_ABP

static uint16_t seconds = 0;

void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status) { }
void RxJoinResponse(bool status) { }

#ifdef ACTIVATE_OTAA
    // OTAA Keys:
    uint8_t applicationEuiNew[8]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    uint8_t deviceEuiNew[8]       = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    uint8_t applicationKeyNew[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
#endif

#ifdef ACTIVATE_ABP
    // ABP Keys:
    uint8_t nwkSKey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    uint8_t appSKey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };        
    uint32_t devAddr = 0x26000000;
#endif

void TTN_SetUp(void)
{
    // The Things Network (TTN) uses the 2nd Sub-Band Only.
    // Channels 8 to 15 and 65
    // https://www.thethingsnetwork.org/docs/lorawan/frequency-plans/#au915-928
    // We disable unused channels.
    
    uint32_t freq;
    int8_t enable;
    
    for (uint8_t ch = 0; ch <= 7; ch++)
        enable = LORAWAN_SetChannelIdStatus(ch, 0);

    for (uint8_t ch = 16; ch <= 64; ch++)
        enable = LORAWAN_SetChannelIdStatus(ch, 0);
    
    for (uint8_t ch = 66; ch <= 71; ch++)
        enable = LORAWAN_SetChannelIdStatus(ch, 0);
    
    // Print list of enabled channels
    for (uint8_t ch = 0; ch <= 71; ch++){
        enable = LORAWAN_GetChannelIdStatus(ch);
        freq = LORAWAN_GetFrequency(ch);
        if (enable) printf("Channel %02d Enabled: %ldHz\r\n",ch, freq);
    } 
}

void TMR3_1SecInterruptHandler(void)
{
    // The LoRaWAN Stack uses TMR1 for timing. While we could piggy back of 
    // TMR1, we set up our own, TMR3. This allows the stack to be updated 
    // without effecting our code. 
    
    // This ISR is called ever 1 second and can be used for sending LoRa Messages 
    seconds++;
    
    if (seconds >= 60) {
        // Sending message as Unconfirmed Transmission (UNCNF). Change to CNF 
        // for Confirmed Transmission.
        LorawanError_t result = LORAWAN_Send(UNCNF, 2, "Hello World", 11);
        if (result == OK)     
            printf("Sent message\r\n");
        else if (result == NETWORK_NOT_JOINED)
            printf("Unable to send message. No network\r\n");
        else 
            printf("Error %d sending message\r\n", result);
        seconds = 0;
    }
}

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    printf("\r\n");
    __delay_ms(1000);
    printf("\r\nRN2903 Test Program\r\nBeyondlogic.org\r\n");
   
    LORAWAN_Reset();
    LORAWAN_Init(RxData, RxJoinResponse);
    TTN_SetUp();

#ifdef ACTIVATE_ABP
    LORAWAN_SetNetworkSessionKey(nwkSKey);
    LORAWAN_SetApplicationSessionKey(appSKey);
    LORAWAN_SetDeviceAddress(devAddr);
    LORAWAN_Join(ABP);
#endif
    
#ifdef ACTIVATE_OTAA
    LORAWAN_SetApplicationEui(applicationEuiNew);
    LORAWAN_SetDeviceEui(deviceEuiNew);
    LORAWAN_SetApplicationKey(applicationKeyNew);    
    LORAWAN_Join(OTAA);
#endif
    
    while (1)
    {
        LORAWAN_Mainloop();
        // All other function calls of the user-defined
        // application must be made here
    }
}
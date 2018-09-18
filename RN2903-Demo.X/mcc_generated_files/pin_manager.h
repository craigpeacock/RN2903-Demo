/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF46K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()               do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()                do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()                do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()       do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()      do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()               do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()                do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()                do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()       do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()      do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()               do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()                do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()                do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()       do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()      do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()               do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()                do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()                do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()       do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()      do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()               do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()                do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()                do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()       do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()      do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()               do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()                do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()                do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()       do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()      do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()               do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()                do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()                do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()       do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()      do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS                 TRISDbits.TRISD0
#define SCK2_LAT                  LATDbits.LATD0
#define SCK2_PORT                 PORTDbits.RD0
#define SCK2_ANS                  ANSELDbits.ANSD0
#define SCK2_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SCK2_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SCK2_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SCK2_GetValue()           PORTDbits.RD0
#define SCK2_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SCK2_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define SCK2_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set SDI2 aliases
#define SDI2_TRIS                 TRISDbits.TRISD1
#define SDI2_LAT                  LATDbits.LATD1
#define SDI2_PORT                 PORTDbits.RD1
#define SDI2_ANS                  ANSELDbits.ANSD1
#define SDI2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SDI2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SDI2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SDI2_GetValue()           PORTDbits.RD1
#define SDI2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SDI2_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define SDI2_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RD3 procedures
#define RD3_SetHigh()               do { LATDbits.LATD3 = 1; } while(0)
#define RD3_SetLow()                do { LATDbits.LATD3 = 0; } while(0)
#define RD3_Toggle()                do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RD3_GetValue()              PORTDbits.RD3
#define RD3_SetDigitalInput()       do { TRISDbits.TRISD3 = 1; } while(0)
#define RD3_SetDigitalOutput()      do { TRISDbits.TRISD3 = 0; } while(0)
#define RD3_SetAnalogMode()         do { ANSELDbits.ANSD3 = 1; } while(0)
#define RD3_SetDigitalMode()        do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set SDO2 aliases
#define SDO2_TRIS                 TRISDbits.TRISD4
#define SDO2_LAT                  LATDbits.LATD4
#define SDO2_PORT                 PORTDbits.RD4
#define SDO2_ANS                  ANSELDbits.ANSD4
#define SDO2_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define SDO2_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define SDO2_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define SDO2_GetValue()           PORTDbits.RD4
#define SDO2_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define SDO2_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define SDO2_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define SDO2_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCB4 pin functionality
 * @Example
    IOCB4_ISR();
 */
void IOCB4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCB4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCB4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCB4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCB4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_InterruptHandler);

*/
extern void (*IOCB4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCB4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_DefaultInterruptHandler);

*/
void IOCB4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
# RN2903-Demo

Source code for the [Microchip RN2903 Module](https://www.beyondlogic.org/microchip-rn2903-lora-transceiver-breakout-board/).

The RN2903 Module includes a:
* [Microchip PIC18LF46K22 MCU](https://www.microchip.com/stellent/groups/picmicro_sg/documents/devicedoc/cn547043.pdf)
* [Semtech SX1276 Radio Transceiver](https://semtech--c.na98.content.force.com/sfc/dist/version/download/?oid=00DE0000000JelG&ids=0682R000006TQEPQA4&d=%2Fa%2F2R0000001Rbr%2F6EfVZUorrpoKFfvaF_Fkpgp5kzjiNyiAbqcpqh9qSjE&operationContext=DELIVERY&asPdf=true&viewId=05H2R000002WGmXUAW&dpt=)
* [Microchip 24AA02E64T 2Kb I2C Serial EEPROM with Pre-Programmed EUI-64™ MAC ID](https://ww1.microchip.com/downloads/en/DeviceDoc/24AA02E48-24AA025E48-24AA02E64-24AA025E64-Data-Sheet-20002124H.pdf)

This is a demo project using the Microchip LoRaWAN Library v01.10.00_beta Stack on the RN2903A Module. For more information, please visit:
* [RN2903: Using the LoRaWAN™ Library Plug-in for MPLAB® Code Configurator and customising for the AU915 Frequency Plan](https://www.beyondlogic.org/rn2903-using-the-lorawan-library-plug-in-for-mplab-code-configurator-and-customising-for-the-au915-frequency-plan/)

mcc_generated_files/LoRaWAN/lorawan_defs.h had been modified to support the AU915 Frequency Plan. Channels 8 to 15 (Sub Band 2) are enabled for use with The Things Network or Helium. The example uses OTAA and sends "Hello World" every 60 seconds.

# March 2022 Update

While Microchip has never updated the LoRaWAN Library in MPLAB Code Configurator (MCC), recently they released the source code for 'UART Modules' and this uses the same stack. We have copied/updated to the mature stack that is running on the RN2903 SA AU915 v1.0.3 modules. 
* https://github.com/MicrochipTech/RN2xx3_LORAWAN_FIRMWARE

Please note the project requires the XC8 V1.45 Cross Compiler. Using V2.x of the compiler appears to result in timing issues, i.e. the Receive Window 1 and 2 can be either increased four fold, or fails to operate at all. 


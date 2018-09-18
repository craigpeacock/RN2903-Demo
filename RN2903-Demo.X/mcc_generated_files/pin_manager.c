/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF46K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"




void (*IOCB4_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xBE;
    TRISD = 0xE6;

    /**
    ANSELx registers
    */
    ANSELD = 0xE4;
    ANSELC = 0xB8;
    ANSELB = 0x28;
    ANSELE = 0x07;
    ANSELA = 0x2F;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    INTCON2bits.nRBPU = 1;

    /**
    ODx registers
    */


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCB - flag
    IOCBbits.IOCB4 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCB4_SetInterruptHandler(IOCB4_DefaultInterruptHandler);
   
    // Enable RBI interrupt 
    INTCONbits.RBIE = 1; 
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCB4
    if(IOCBbits.IOCB4 == 1)
    {
        IOCB4_ISR();  
    }	
	// Clear global Interrupt-On-Change flag
    INTCONbits.RBIF = 0;
}

/**
   IOCB4 Interrupt Service Routine
*/
void IOCB4_ISR(void) {

    // Add custom IOCB4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCB4_InterruptHandler)
    {
        IOCB4_InterruptHandler();
    }
}

/**
  Allows selecting an interrupt handler for IOCB4 at application runtime
*/
void IOCB4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCB4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCB4
*/
void IOCB4_DefaultInterruptHandler(void){
    // add your IOCB4 interrupt custom code
    // or set custom function using IOCB4_SetInterruptHandler()
}

/**
 End of File
*/
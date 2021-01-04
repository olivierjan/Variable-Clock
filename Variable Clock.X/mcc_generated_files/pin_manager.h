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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SWITCH_UP aliases
#define SWITCH_UP_TRIS                 TRISAbits.TRISA0
#define SWITCH_UP_LAT                  LATAbits.LATA0
#define SWITCH_UP_PORT                 PORTAbits.RA0
#define SWITCH_UP_WPU                  WPUAbits.WPUA0
#define SWITCH_UP_OD                   ODCONAbits.ODCA0
#define SWITCH_UP_ANS                  ANSELAbits.ANSELA0
#define SWITCH_UP_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SWITCH_UP_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SWITCH_UP_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SWITCH_UP_GetValue()           PORTAbits.RA0
#define SWITCH_UP_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SWITCH_UP_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SWITCH_UP_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SWITCH_UP_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SWITCH_UP_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SWITCH_UP_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SWITCH_UP_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define SWITCH_UP_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set SWITCH_DOWN aliases
#define SWITCH_DOWN_TRIS                 TRISAbits.TRISA1
#define SWITCH_DOWN_LAT                  LATAbits.LATA1
#define SWITCH_DOWN_PORT                 PORTAbits.RA1
#define SWITCH_DOWN_WPU                  WPUAbits.WPUA1
#define SWITCH_DOWN_OD                   ODCONAbits.ODCA1
#define SWITCH_DOWN_ANS                  ANSELAbits.ANSELA1
#define SWITCH_DOWN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SWITCH_DOWN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SWITCH_DOWN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SWITCH_DOWN_GetValue()           PORTAbits.RA1
#define SWITCH_DOWN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SWITCH_DOWN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SWITCH_DOWN_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SWITCH_DOWN_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SWITCH_DOWN_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SWITCH_DOWN_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SWITCH_DOWN_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define SWITCH_DOWN_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSELD1 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/
/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F46K42
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "Variable_Clock.h"
#include "OLED_I2C.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define BUTTONDELAY 32
#define STEPVALUE 0x8ff

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    OLED_Init();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    //TRISA=0x00;
    
    // Initialize a few variables
    const unsigned long long xtalfreq = _XTAL_FREQ/1000;
    __uint24 ncocounter=0;
    unsigned long long freqvalue = 0;
    bool automaticclock = true ; 
    char frequencytext[48];
    
    __delay_ms(1000);
    
    
    // Move the SFRs value into our own counter.
    
    ncocounter = NCO1INCU;
    ncocounter = ncocounter << 8;
    ncocounter = (ncocounter | NCO1INCH) << 8;
    ncocounter = ncocounter | NCO1INCL ;
    
    // Compute the actual Frequency value as 
    // (FOSC x ncocounter)/2?20
    
    freqvalue=xtalfreq*ncocounter;
    freqvalue=freqvalue>>21;
    
    // Initial display of frequency
    
    sprintf(frequencytext, "Speed: %0u kHz\n\nPress + and -\nfor manual mode", freqvalue);
    OLED_ClearDisplay();
    OLED_Write_Text(0,0,&frequencytext);
    OLED_Update();
    
    while (1)
    {
        
        
        // Both buttons are pressed ?
        
        if (SWITCH_UP_GetValue() && SWITCH_DOWN_GetValue()) {
            
            // Toggle Automatic / Manual
            
            automaticclock = !automaticclock;
            
            // We were actually in automatic -> Switch to Manual
            if (RD1PPS){
                // Disable NCO
                NCO1CONbits.EN = 0;
                // Remove NCO mapping to RD1
                RD1PPS = 0x00;
                
                // Display Manual mode banner
                
                OLED_ClearDisplay();
                OLED_Write_Text(CENTER,0,"Manual Mode");
                OLED_Write_Text(0,24,"Press any button\nto Toggle Clock");
                OLED_Update();
            } else { // We were in manual mode -> go back to automatic
                // Remap NCO peripheral to PIN RD1
                RD1PPS = 0x26;
                // Re-enable NCO peripheral
                NCO1CONbits.EN = 1;
                
                // Display current frequency
                
                freqvalue=xtalfreq*ncocounter;
                freqvalue=freqvalue>>21;
                sprintf(frequencytext, "Speed: %0u kHz\n\nPress + and -\nfor manual mode", freqvalue);
                OLED_ClearDisplay();
                OLED_Write_Text(0,0,&frequencytext);
                OLED_Update();
            }
            __delay_ms(500);
        }
        
        // If we're in manual mode and any button is pressed.
        if (!automaticclock && (SWITCH_DOWN_GetValue() || SWITCH_UP_GetValue())){
            
            // Toggle state of RD1
            RD1_Toggle();
            
            // Display current state (HIGH or LOW)
            OLED_ClearDisplay();
            if (RD1_GetValue()) {            
                OLED_Write_Text(CENTER,0,"HIGH");
            } else {
                OLED_Write_Text(CENTER,0,"LOW");
            }
            OLED_Write_Text(0,24,"Press + and -\nfor automatic mode");
            OLED_Update();
            __delay_ms(250);
        }
        
        // Automatic and DOWN button pressed
        if (SWITCH_DOWN_GetValue() && (ncocounter > STEPVALUE) && automaticclock) {
            
            // Decrease the NCO counter 
            
            savecounter(ncocounter -= STEPVALUE);
            
            // Display the new value.
            
            freqvalue=xtalfreq*ncocounter;
            freqvalue=freqvalue>>21;
            sprintf(frequencytext, "Speed: %0u kHz\n\nPress + and -\nfor manual mode", freqvalue);
            OLED_ClearDisplay();
            OLED_Write_Text(0,0,&frequencytext);
            OLED_Update();
        }
        
        // Automatic and UP button pressed 
        
        if (SWITCH_UP_GetValue() && (ncocounter < (0x40000-STEPVALUE)) && automaticclock) {
            
            // Increase NCO Counter value
            
            savecounter(ncocounter += STEPVALUE);
            
            //Display new value
            
            freqvalue=xtalfreq*ncocounter;
            freqvalue=freqvalue>>21;
            sprintf(frequencytext, "Speed: %0u kHz\n\nPress + and -\nfor manual mode", freqvalue);
            OLED_ClearDisplay();
            OLED_Write_Text(0,0,&frequencytext);
            OLED_Update();
        }
        
    }
    
}

void savecounter (__uint24 Counter) {
    NCO1CONbits.EN = 0;
    NCO1INCL = (uint8_t) (Counter) ; 
    NCO1INCH = (uint8_t) (Counter >> 8);
    NCO1INCU = (uint8_t) (Counter >> 16);
    NCO1CONbits.EN = 1;
    __delay_ms(BUTTONDELAY);
}
/**
 End of File
*/
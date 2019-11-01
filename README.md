## Variable Clock

PIC Based Clock device for use with Homebrew Computers.
This is intended to replace the Oscillator for debugging and testing purposes. 

Based on a PIC18F, it provides the following features: 
- Frequency adjustment (40khz-8Mhz)
- Manual mode to single step the CPU
- (Optional) OLED Display

Project requires : 

 - PIC 18F46K42 (can be adapted for other models with NCO)
 - 2x Buttons
 - 3x 10k Ohm resistor 
 - 2x '104' Ceramic Capacitor
 - 1x 470 Ohm resistor
 - (Optional) 1x '128x64' I2C SSD1306 OLED display.



Usage: 

 - After initialisation, clock starts at 1.023khz.
 - Pressing "UP" button increase the frequency.
 - Pressing "DOWN" button decrease the frequency.
 - Pressing **both** buttons simultaneously switch to manual mode.
 - In manual mode, pressing either button toggle the clock signal. 
 - Pressing again **both** buttons will switch back to automatic mode. 

The PIC has been programmed with MPLAB X.

> Written with [StackEdit](https://stackedit.io/).
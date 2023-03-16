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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC10F322
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef DIO_H
#define DIO_H

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

/* get/set PWM_INPUT aliases */
#define PWM_INPUT_TRIS                 TRISAbits.TRISA0
#define PWM_INPUT_LAT                  GPIObits.GPIO0
#define PWM_INPUT_PORT                 GPIObits.GPIO0
#define PWM_INPUT_WPU                  WPUAbits.WPUA0
#define PWM_INPUT_ANS                  ANSELAbits.ANSA0
#define PWM_INPUT_SetHigh()            do { GPIObits.GPIO0 = 1; } while(0)
#define PWM_INPUT_SetLow()             do { GPIObits.GPIO0 = 0; } while(0)
#define PWM_INPUT_Toggle()             do { GPIObits.GPIO0 = ~GPIObits.GPIO0; } while(0)
#define PWM_INPUT_GetValue()           GPIObits.GPIO0
#define PWM_INPUT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PWM_INPUT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PWM_INPUT_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PWM_INPUT_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PWM_INPUT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define PWM_INPUT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

/* get/set PWM_OUTPUT aliases */
#define PWM_OUTPUT_TRIS                 TRISAbits.TRISA1
#define PWM_OUTPUT_LAT                  GPIObits.GPIO1
#define PWM_OUTPUT_PORT                 GPIObits.GPIO1
#define PWM_OUTPUT_WPU                  WPUAbits.WPUA1
#define PWM_OUTPUT_ANS                  ANSELAbits.ANSA1
#define PWM_OUTPUT_SetHigh()            do { GPIObits.GPIO1 = 1; } while(0)
#define PWM_OUTPUT_SetLow()             do { GPIObits.GPIO1 = 0; } while(0)
#define PWM_OUTPUT_Toggle()             do { GPIObits.GPIO1 = ~GPIObits.GPIO1; } while(0)
#define PWM_OUTPUT_GetValue()           GPIObits.GPIO1
#define PWM_OUTPUT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PWM_OUTPUT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PWM_OUTPUT_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PWM_OUTPUT_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PWM_OUTPUT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define PWM_OUTPUT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

/* get/set PWM_LIMIT aliases */
#define PWM_LIMIT_TRIS                 TRISAbits.TRISA2
#define PWM_LIMIT_LAT                  GPIObits.GPIO2
#define PWM_LIMIT_PORT                 GPIObits.GPIO2
#define PWM_LIMIT_WPU                  WPUAbits.WPUA2
#define PWM_LIMIT_ANS                  ANSELAbits.ANSA2
#define PWM_LIMIT_SetHigh()            do { GPIObits.GPIO2 = 1; } while(0)
#define PWM_LIMIT_SetLow()             do { GPIObits.GPIO2 = 0; } while(0)
#define PWM_LIMIT_Toggle()             do { GPIObits.GPIO2 = ~GPIObits.GPIO2; } while(0)
#define PWM_LIMIT_GetValue()           GPIObits.GPIO2
#define PWM_LIMIT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PWM_LIMIT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PWM_LIMIT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PWM_LIMIT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PWM_LIMIT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define PWM_LIMIT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

/* get/set BUTTON aliases */
#define BUTTON_PORT                 GPIObits.GPIO3
#define BUTTON_WPU                  WPUAbits.WPUA3
#define BUTTON_GetValue()           GPIObits.GPIO3
#define BUTTON_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

#define PWM_OUTPUT_PIN 1
#define PWM_OUTPUT_INREG GPIO
#define PWM_OUTPUT_OUTREG GPIO

#define Dio_ChannelRead(CHANNEL) CHANNEL##_GetValue()
#define Dio_ChannelWrite(CHANNEL, STATE) CHANNEL##_LAT = STATE
#define Dio_ChannelToggle(CHANNEL)  CHANNEL##_OUTREG ^= 1u << CHANNEL##_PIN

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
void Dio_Init(void);

#endif /* DIO_H */


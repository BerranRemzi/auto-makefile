/**
  TMR0 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr.h

  @Summary
    This is the generated header file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC10F322
        Driver Version    :  2.01
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

#ifndef TMR_H
#define TMR_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

#define Tmr_ClkDivSet(PRESCALER, CHANNEL) OPTION_REGbits.PS = PRESCALER
#define Tmr_Init(CHANNEL) CHANNEL##_Initialize()
#define Tmr_WriteTimer(CHANNEL, VALUE) CHANNEL##_WriteTimer(VALUE)
#define Tmr_Reload(CHANNEL) CHANNEL##_Reload()
#define Tmr_ReadTimer(CHANNEL) CHANNEL
#define Tmr_HasOverflowOccured(CHANNEL) CHANNEL##_HasOverflowOccured()

/**
  Section: TMR0 APIs
*/

/**
  @Summary
    Initializes the TMR0 module.

  @Description
    This function initializes the TMR0 Registers.
    This function must be called before any other TMR0 function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR0 module
        TMR0_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR0_Initialize(void);

/**
  @Summary
    Writes the TMR0 register.

  @Description
    This function writes the TMR0 register.
    This function must be called after the initialization of TMR0.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    timerVal - Value to write into TMR0 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR0 register
        if(ZERO == TMR0_ReadTimer())
        {
            // Do something else...

            // Write the TMR0 register
            TMR0_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR0_WriteTimer(uint8_t timerVal);

/**
  @Summary
    Reload the TMR0 register.

  @Description
    This function reloads the TMR0 register.
    This function must be called to write initial value into TMR0 register.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    while(1)
    {
        if(TMR0IF)
        {
            // Do something else...

            // clear the TMR0 interrupt flag
            TMR0IF = 0;

            // Reload the initial value of TMR0
            TMR0_Reload();
        }
    }
    </code>
*/
void TMR0_Reload(void);

/**
  @Summary
    Boolean routine to poll or to check for the overflow flag on the fly.

  @Description
    This function is called to check for the timer overflow flag.
    This function is usd in timer polling method.

  @Preconditions
    Initialize  the TMR0 module before calling this routine.

  @Param
    None

  @Returns
    true - timer overflow has occured.
    false - timer overflow has not occured.

  @Example
    <code>
    while(1)
    {
        //check the overflow flag
        if(TMR0_HasOverflowOccured())
        {
            // Do something else...

            // clear the TMR0 interrupt flag
            TMR0IF = 0;

            // Reload the TMR0 value
            TMR0_Reload();
        }
    }
    </code>
*/
bool TMR0_HasOverflowOccured(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR0_H
/**
 End of File
*/

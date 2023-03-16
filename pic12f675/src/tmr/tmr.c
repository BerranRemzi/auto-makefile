/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
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

/**
  Section: Included Files
*/

#include "tmr.h"
#include <xc.h>

/**
  Section: Global Variables Definitions
*/

volatile uint8_t timer0ReloadVal = 0u;
volatile uint8_t timer0PrescalerVal = 7u;

/**
  Section: TMR0 APIs
*/

void TMR0_Initialize(void)
{
    /* Set TMR0 to the options selected in the User Interface  */
	
    /* PSAassigned; PS 1:256; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits */
    OPTION_REG = 0b00000111;  /* Prescaler1:256, TMR0 clock source is Fosc/4 */

    OPTION_REGbits.PS = timer0PrescalerVal;

    /* TMR0 */ 0; 
    TMR0 = timer0ReloadVal;
	
    /* Clearing IF flag */
    INTCONbits.TMR0IF = 0;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    timer0ReloadVal = timerVal;
    /* Write to the Timer0 register */
    TMR0 = timer0ReloadVal;
}

void TMR0_Reload(void)
{
    /* Write to the Timer0 register */
    TMR0 = timer0ReloadVal;
}

bool TMR0_HasOverflowOccured(void)
{
    /* check if overflow has occurred by checking the TMRIF bit */
    return(INTCONbits.TMR0IF);
}
/**
  End of File
*/

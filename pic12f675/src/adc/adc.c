/**
  ADC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.c

  @Summary
    This is the generated driver implementation file for the ADC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC10F322
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB             :  MPLAB X 6.00
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

#include <xc.h>
#include "adc.h"
#include "device_config.h"

/**
  Section: Macro Declarations
*/

#define ACQ_US_DELAY 20

void (*ADC_InterruptHandler)(void);

/**
  Section: ADC Module APIs
*/

void Adc_Init(void)
{
    /* Set the ADC clock source to FOSC/8 */
    ANSELbits.ADCS = 1;
    
    /* Set the ADC to left-justified mode */
    ADCON0bits.ADFM = 0;
    
    /* Enable the ADC module */
    ADCON0bits.ADON = 1;   
}

Adc_Result_t Adc_GetConversion(adc_channel_t channel)
{
    /* select the A/D channel */
    ADCON0bits.CHS = channel;    
    
    /* Turn on the ADC module */
    ADCON0bits.ADON = 1;

    /* Acquisition time delay */
    __delay_us(ACQ_US_DELAY);

    /* Start the conversion */
    ADCON0bits.GO_nDONE = 1;

    /* Wait for the conversion to finish */
    while (ADCON0bits.GO_nDONE)
    {
    }

    /* Conversion finished, return the result */
	return ((Adc_Result_t)(ADRESH));
}

/**
 End of File
*/

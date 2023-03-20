/**
 MEMORY Generated Driver File

 @Company
 Microchip Technology Inc.

 @File Name
 flash.c

 @Summary
 This is the generated driver implementation file for the MEMORY driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

 @Description
 This file provides implementations of driver APIs for MEMORY.
 Generation Information :
 Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
 Device            :  PIC10F322
 Driver Version    :  2.0.2
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

#include "../flash/flash.h"

#include <xc.h>

/**
 Section: Flash Module APIs
 */

void Flash_Read(uint16_t const address, uint8_t *data, uint8_t const size) {
    /* Read each byte of data from the EEPROM */
    for (uint8_t i = 0; i < size; i++) {
        /* Set up the address to read from */
        EEADR = address + i;

        /* Set up the read control register */
        EECON1bits.RD = 1;

        /* Read the data byte from the EEPROM */
        data[i] = EEDATA;

        /* Clear the read control bit */
        EECON1bits.RD = 0;

        /* Increment the EEPROM address */
        EEADR++;
    }
}

void FLASH_WriteWord(uint16_t flashAddr, uint16_t *ramBuf, uint16_t word) {
#if 0
    uint16_t blockStartAddr = (uint16_t) (flashAddr & ((END_FLASH - 1) ^ (ERASE_FLASH_BLOCKSIZE - 1)));
    uint8_t offset = (uint8_t) (flashAddr & (ERASE_FLASH_BLOCKSIZE - 1));
    uint8_t i;

    /* Entire row will be erased, read and save the existing data */
    for (i = 0; i < ERASE_FLASH_BLOCKSIZE; i++) {
        ramBuf[i] = FLASH_ReadWord((blockStartAddr + i));
    }

    /* Write at offset */
    ramBuf[offset] = word;
    
    /* Writes ramBuf to current block */
    FLASH_WriteBlock(blockStartAddr, ramBuf);
    #endif
}

void Flash_Write(uint16_t address, uint8_t const *data, uint8_t const size) {
    /* Wait for any previous EEPROM write to complete */
    while (EECON1bits.WR)
        ;

    /* Write each byte of data to the EEPROM */
    for (uint8_t i = 0; i < size; i++) {
        /* Set up the address to write to */
        EEADR = address + i;

        /* Load data byte into the data buffer */
        EEDATA = data[i];

        /* Set up the write control register */
        EECON1bits.WREN = 1;

        /* Enable interrupts (if desired) */
        INTCONbits.GIE = 1;

        /* Perform the write operation */
        EECON2 = 0x55;
        EECON2 = 0xAA;
        EECON1bits.WR = 1;

        /* Disable interrupts (if enabled) */
        INTCONbits.GIE = 0;

        /* Wait for the write operation to complete */
        while (EECON1bits.WR)
            ;

        /* Disable write enable after each write operation */
        EECON1bits.WREN = 0;
    }
}

void Flash_EraseBlock(uint16_t startAddr) {
#if 0
    uint8_t GIEBitValue = INTCONbits.GIE;   /* Save */ interrupt enable

    INTCONbits.GIE = 0; /* Disable */ interrupts
    /* Load */ lower 8 bits of erase address boundary
    PMADRL = (startAddr & 0xFF);
    /* Load */ upper 6 bits of erase address boundary
    PMADRH = ((startAddr & 0xFF00) >> 8);

    /* Block */ erase sequence
    PMCON1bits.CFGS = 0;    /* Deselect */ Configuration space
    PMCON1bits.FREE = 1;    /* Specify */ an erase operation
    PMCON1bits.WREN = 1;    /* Allows */ erase cycles

    /* Start */ of required sequence to initiate erase
    PMCON2 = 0x55;
    PMCON2 = 0xAA;
    PMCON1bits.WR = 1;      /* Set */ WR bit to begin erase
    NOP();
    NOP();

    PMCON1bits.WREN = 0;       /* Disable */ writes
    INTCONbits.GIE = GIEBitValue;	/* Restore */ interrupt enable
    #endif
}
/**
 End of File
 */

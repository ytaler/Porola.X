/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
    RP0 = 0x01;     // Cambiamos al banco 1
    CMCON = 0x07;   //
    TRISA = 0xFE;   // Establecemos todo como entrada menos RA0
    TRISB = 0xFF;   // Todo como entrada. Nos interesa RB3
    PIE1 = 0x00;    // Deshabilitamos las interrupciones de los perifericos
    RP0 = 0x00;     // Cambiamos al banco 0

    // Inicializacion de perifericos
        // Captura
    CCP1CON = 0x00; // Desactiva el modulo ccp
    CCPR1L = 0;     // Inicializa el contador, 8 bits menos significantes
    CCPR1H = 0;     // Inicializa el contador, 8 bits mas significantes
        // Interrupciones
    INTCON = 0x00;  // Deshabilitamos irq
    PIR1 = 0x00;    // Borramos bandera de interrupcion del periferico
        // Captura
    CCP1CON = 0x04; // Habilita el modo captura por cada flanco descendente
    T1CON = 0x00;   // Configura el timer 1
    T2CON = 0x00;   // Apaga el timer 2
    TMR1L = 0x00;
}


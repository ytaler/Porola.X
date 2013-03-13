/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"

/* Refer to the device datasheet for information about available
oscillator configurations. */
void ConfigureOscillator(void)
{
    PCON |= 0x08;       // Configuramos el osc interno a 4mhz
    RP0 = 0x01;         // Cambiamos de banco al banco 1
    OPTION_REG = 0x80;  // Configuramos el timer
    RP0 = 0x00;         // Volvemos al banco 0
}

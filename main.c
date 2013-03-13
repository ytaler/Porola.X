/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include "system.h"        // Parametros / Funciones de sistema
#include "user.h"          // Funciones de usuario
#include "delays.h"        // Funcion que incluye retardos

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    bool clave=false;
    int cont_delay=0;
    // Configura el oscilador interno
    ConfigureOscillator();
    // Inicializa perifericos y/o aplicaciones
    InitApp();
    // Bucle principal
    while(1){
        cont_delay++;
        if(cont_delay >= 50){
            cont_delay = 0;
            clave=~clave;
            if(clave){
                Enciende();
            }
            else{
                Apaga();
            }
        }
        __delay_ms(10);
    }
}


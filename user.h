/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

#define Enciende() RA0 = 0x01;
#define Apaga() RA0 = 0x00;

void InitApp(void);         /* I/O and Peripheral Initialization */
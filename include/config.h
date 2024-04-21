// ########################## DEFINES ##########################

#define AREF_VOLTAGE 3300 // Tie ARef to 3.3V
#define ADC_RES 12        // Resolution of ADC (0 - 4095)
#define ADC_RES_VAL 4095  // Resolution of ADC (0 - 4095)

#define SERIAL_BAUD 57600 // Baud rate for built-in Serial (used for the Serial Monitor)

#if defined(STM32F401CC) || defined(STM32F411CE)
#define LED_PIN PC13
#endif

#if defined(STM32F103C8)
#define LED_PIN PB2
#endif

#define USERBTN_PIN PA0

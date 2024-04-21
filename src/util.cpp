#include "util.h"
#include "config.h"

extern "C" char *sbrk(int incr);
int freeMemory()
{
  char stack_dummy = 0;
  return &stack_dummy - reinterpret_cast<char *>(sbrk(0));
}

float readVdd()
{
  return (1.20 * 4096.0 / analogRead(AVREF));
}

float readTempSensor()
{
  float vdd = readVdd();

#if defined(STM32F401CC) || defined(STM32F411CE)
#define V25 0.76
#define AVG_SLOPE 0.0025

    // Temperature (in °C) = {(V25 - VSENSE) / Avg_Slope} + 25.
    return (((analogRead(ATEMP) * vdd / 4096.0) - V25) / AVG_SLOPE) + 25;
#endif

#if defined(STM32F103C8)
#define V25 1.43
#define AVG_SLOPE 0.0043

    // Temperature (in °C) = {(V25 - VSENSE) / Avg_Slope} + 25.
    return ((V25 - (analogRead(ATEMP) * vdd / 4096.0)) / AVG_SLOPE) + 25;
#endif
}
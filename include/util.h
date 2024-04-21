#pragma once

#include <Arduino.h>

// Get a free memory on the MCU
int freeMemory();

// Read V REF
float readVdd();

// Read TempSensor in celsius 
float readTempSensor();
#pragma once

#include <Arduino.h>

#define SERIAL_DEBUG true

extern void SN_host_system_init(bool serial_en);

#define IND_LED_PIN PIN_SPI_MOSI // LED

extern void SN_host_pin_init(void);

enum IND_LED_STATE {
  IND_LED_OFF = LOW,
  IND_LED_ON  = HIGH
};

extern void IND_LED(IND_LED_STATE led_state);

extern void SN_host_tst_func(void);
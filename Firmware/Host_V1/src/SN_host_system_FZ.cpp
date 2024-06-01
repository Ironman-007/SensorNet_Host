// Author: Fangzheng Liu
// Created: 2024-05-24
// This file is used for the system control, like serialport initialization etc.

#include "SN_host_system_FZ.h"

void SN_host_system_init(bool serial_en) {
  if (serial_en) {
    Serial.begin(115200);
    while (!Serial) {
      delay(10); // wait for serial port to connect. Needed for native USB port only
    }
  }
}

void SN_host_pin_init(void) {
  pinMode(IND_LED_PIN, OUTPUT);
  digitalWrite(IND_LED_PIN, LOW);
}

void IND_LED(IND_LED_STATE led_state) {
  digitalWrite(IND_LED_PIN, led_state);
}

void SN_host_tst_func(void) {
  digitalWrite(IND_LED_PIN, LOW);
  delay(100);
  digitalWrite(IND_LED_PIN, HIGH);
  delay(100);
}




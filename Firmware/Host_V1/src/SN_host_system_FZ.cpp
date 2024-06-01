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

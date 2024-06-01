#include <Arduino.h>

#include "SN_host_system_FZ.h"
#include "SN_host_comm_FZ.h"

void setup() {
  SN_host_system_init(SERIAL_DEBUG);
  SN_host_pin_init();
  SN_host_BLE_init();
  delay(100);
  SN_host_BLE_startAdv();
}

void loop() {
  if (ble_connnected) {
    // SN_host_comm_tst_func();
    // delay(2000);
  }
}

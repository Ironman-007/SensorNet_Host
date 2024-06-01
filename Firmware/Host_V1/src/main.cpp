#include <Arduino.h>

#include "SN_host_system_FZ.h"
#include "SN_host_comm_FZ.h"

void setup() {
  SN_host_system_init(SERIAL_DEBUG);
}

void loop() {
  update();
}

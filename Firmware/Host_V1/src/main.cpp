#include <Arduino.h>

#include "SN_host_system_FZ.h"
#include "SN_host_comm_FZ.h"
#include "SN_host_node_FZ.h"

#include "NRF52TimerInterrupt.h"
#include "NRF52_ISR_Timer.h"

NRF52Timer ITimer(NRF_TIMER_1);
NRF52_ISR_Timer ISR_Timer;

volatile bool timer4Interrupt_1s = false;

// ===================== Interrupt functions =====================
void TimerHandler() {
  ISR_Timer.run();
}

void timer_handler_1s() {
  timer4Interrupt_1s = true;
}

void interrupt_setup() {
  ITimer.attachInterruptInterval(HW_TIMER_INTERVAL_MS * 1000, TimerHandler);
  ISR_Timer.setInterval(TIMER_INTERVAL_1s, timer_handler_1s);
}

void setup() {
  SN_host_system_init(SERIAL_DEBUG);
  SN_host_pin_init();
  SN_host_BLE_init();
  delay(100);
  SN_host_BLE_startAdv();
}

void loop() {
  // scan the whole network and update the SN_node_addr every 1s.
  if (timer4Interrupt_1s) {
    timer4Interrupt_1s = false;
    SN_update_addr_net();
  }

  if (ble_connnected) {
    SN_update_addr_net();
  }
}

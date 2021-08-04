#include <Arduino.h>
#include "STM32LowPower.h"

#define HW_UART_TX D1
#define HW_UART_RX D0

HardwareSerial SerialAT(HW_UART_RX, HW_UART_TX);

void setup() {
  // put your setup code here, to run once
  SerialAT.begin(9600);
  LowPower.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialAT.println("ATZ");
  delay(1000);
  SerialAT.println("AT+BAND=8");
  delay(1000);
  SerialAT.println("AT+JOIN=0"); 
  delay(3000);
  SerialAT.println("AT+SEND=1:0:ABCDEF");
  delay(500);
  LowPower.shutdown(20000);
}
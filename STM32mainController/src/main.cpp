#include <Arduino.h>
#define HW_UART_TX D1
#define HW_UART_RX D0

HardwareSerial SerialAT(HW_UART_RX, HW_UART_TX);

void setup() {
  // put your setup code here, to run once
  SerialAT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialAT.println("AT+JOIN=0");
  delay(200);
  SerialAT.println("AT+SEND=1:0:ABCDEF");
  delay(200);
}
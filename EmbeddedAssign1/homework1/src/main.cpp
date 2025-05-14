#include <Arduino.h>

// 定义引脚数组
const int ledPins[] = {18, 19, 21, 22, 26, 27}; // 替换后两个引脚
const int numPins = 6; 

void setup() {
  // 初始化引脚为输出
  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // 确保初始状态为熄灭
  }
  Serial.begin(115200); 
}

void loop() {
  // 正向流水灯
  for (int i = 0; i < numPins; i++) {
    digitalWrite(ledPins[i], HIGH); // 点亮当前 LED
    Serial.print("Pin ");
    Serial.print(ledPins[i]);
    Serial.println(" ON");
    delay(500);
    digitalWrite(ledPins[i], LOW); // 熄灭当前 LED
    Serial.print("Pin ");
    Serial.print(ledPins[i]);
    Serial.println(" OFF");
  }

  // 反向流水灯
  for (int i = numPins - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH); // 点亮当前 LED
    Serial.print("Pin ");
    Serial.print(ledPins[i]);
    Serial.println(" ON");
    delay(500);
    digitalWrite(ledPins[i], LOW); // 熄灭当前 LED
    Serial.print("Pin ");
    Serial.print(ledPins[i]);
    Serial.println(" OFF");
  }
}
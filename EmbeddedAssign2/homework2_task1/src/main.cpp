/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-04-28 18:09:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-04-28 19:12:09
 * @FilePath: \homework2_task1\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Arduino.h>

int LED_BUILTIN = 2;
int LED1 = 4;  // GPIO4
int LED2 = 5;  // GPIO5
int LED3 = 12; // GPIO12
int LED4 = 13; // GPIO13
int LED5 = 14; // GPIO14
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0)
  {
    char c = Serial.read();
    switch (c)
    {
    case '0': 
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      delay(50); // 确保状态稳定
      if(digitalRead(LED_BUILTIN))
      {
      Serial.println("LED_BUILTIN switched on.");
      }
      else
      {
      Serial.println("LED_BUILTIN switched off.");
      }
      delay(1000);
      break;
    case '1': 
      digitalWrite(LED1, !digitalRead(LED1));
      delay(50); // 确保状态稳定
      if(digitalRead(LED1))
      {
      Serial.println("LED1 switched on.");
      }
      else
      {
      Serial.println("LED1 switched off.");
      }
      delay(1000);
      break;
    case '2': 
      digitalWrite(LED2, !digitalRead(LED2));
      delay(50); // 确保状态稳定
      if(digitalRead(LED2))
      {
      Serial.println("LED2 switched on.");
      }
      else
      {
      Serial.println("LED2 switched off.");
      }
      delay(1000);
      break;
    case '3':
      digitalWrite(LED3, !digitalRead(LED3));
      delay(50); // 确保状态稳定
      if(digitalRead(LED3))
      {
      Serial.println("LED3 switched on.");
      }
      {
      Serial.println("LED3 switched off.");
      }
      delay(1000);
      break;
    case '4':
      digitalWrite(LED4, !digitalRead(LED4));
      delay(50); // 确保状态稳定
      if(digitalRead(LED4))
      {
      Serial.println("LED4 switched on.");
      }
      else
      {
      Serial.println("LED4 switched off.");
      }
      delay(1000);
      break;
    case '5':
      digitalWrite(LED5, !digitalRead(LED5));
      delay(50); // 确保状态稳定
      if(digitalRead(LED5))
      {
      Serial.println("LED5 switched on.");
      }
      else
      {
      Serial.println("LED5 switched off.");
      }
      delay(1000);
    default:
      Serial.println("Invalid input!");
      break;
    }
  }
  else
  {
    Serial.println("Press the number of LED to switch on/off (0-5):");
    delay(1000);
  }
}

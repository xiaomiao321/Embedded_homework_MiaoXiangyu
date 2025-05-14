// 修复后的代码
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  static int flag = 0; // 状态标志，使用静态变量保持状态
  String input = "";
  char c;

  // 读取串口数据
  while (Serial.available() > 0) {
    c = (char)Serial.read();
    if (c == '\r' || c == '\n') { // 检测到换行符，认为一次输入结束
      delay(10); // 短暂延迟，确保所有数据接收完成
      break;
    }
    input += c;
    delay(10);
  }

  if (input.length() == 2) { // 确保输入的字符串长度为2
    switch (flag) {
      case 0:
        if (input == "AA") {
          flag = 1;
          //Serial.println("Next: BB");
        } else {
          flag = 0;
          Serial.println("Password Error"); 
        }
        break;
      case 1:
        if (input == "BB") {
          flag = 2;
          //Serial.println("Next: CC");
        } else {
          flag = 0;
          Serial.println("Password Error");
        }
        break;
      case 2:
        if (input == "CC") {
          flag = 3;
          //Serial.println("Next: DD");
        } else {
          flag = 0;
          Serial.println("Password Error");
        }
        break;
      case 3:
        if (input == "DD") {
          flag = 0; // 重置状态
          Serial.println("Password Correct"); 
        }
        break;
    }
  } else if(input.length() > 0) { // 如果输入不是两个字符但有内容
    flag = 0;
    Serial.println("Password Error");
  }
  input = ""; // 清空输入字符串，准备下一次读取
  delay(100); // 短暂延迟，防止重复触发
}
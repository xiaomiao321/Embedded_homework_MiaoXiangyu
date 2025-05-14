#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "frames.h" // 包含动图帧数据的头文件

// 定义OLED屏幕参数
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // 如果OLED没有RESET引脚，设为-1
#define SCREEN_ADDRESS 0x3C // OLED的I2C地址，通常为0x3C或0x3D，可通过I2C扫描程序确认

// 初始化OLED对象
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.display();
  //delay(1000); // 调试
}

void loop() {
  // 循环播放每一帧
  for (int i = 0; i < FRAME_COUNT; i++) {
    display.clearDisplay(); 
    // 从PROGMEM中读取帧数据并显示
    display.drawBitmap(32, 0, frames[i], 64, 64, BLACK, WHITE);
    display.display(); 
    delay(50); // 每帧延迟50ms，调整播放速度
  }
}
//
// Created by Kurosu Chan on 2024/5/8.
//
#include <air001xx_hal.h>

extern "C" {
[[noreturn]] int main() {
  HAL_Init();
  for (;;) {
    __NOP();
  }
}
}

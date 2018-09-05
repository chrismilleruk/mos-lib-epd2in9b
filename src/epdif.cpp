/**
 *  @filename   :   epdif.cpp
 *  @brief      :   Implements EPD interface functions
 *                  Users have to implement all the functions in epdif.cpp
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "epdif.h"
#include <SPI.h>
#include "mgos_system.h"
#include "mgos_event.h"
#include "mgos_gpio.h"



EpdIf::EpdIf() {
};

EpdIf::~EpdIf() {
};

void EpdIf::DigitalWrite(int pin, int value) {
    digitalWrite(pin, value);
}

int EpdIf::DigitalRead(int pin) {
    return digitalRead(pin);
}

void EpdIf::DelayMs(unsigned int delaytime) {
    delay(delaytime);
}

void EpdIf::SpiTransfer(unsigned char data) {
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(data);
    digitalWrite(CS_PIN, HIGH);
}

void handle_busy_int(int pin, void *arg) {
  if (pin != BUSY_PIN) return;
  int busy = digitalRead(BUSY_PIN);
  if (busy) {
    mgos_event_trigger(MGOS_EVENT_BUSY, NULL);
  } else {
    mgos_event_trigger(MGOS_EVENT_IDLE, NULL);
  }
}

int EpdIf::IfInit(void) {
    pinMode(CS_PIN, OUTPUT);
    pinMode(RST_PIN, OUTPUT);
    pinMode(DC_PIN, OUTPUT);
    pinMode(BUSY_PIN, INPUT); 
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    SPI.begin();

    mgos_event_register_base(MGOS_EVENT_EPD, "E-Paper Display");
    mgos_gpio_set_int_handler(BUSY_PIN, MGOS_GPIO_INT_EDGE_ANY,
                               handle_busy_int, NULL);
    mgos_gpio_enable_int(BUSY_PIN);
    return 0;
}


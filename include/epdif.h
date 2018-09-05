/**
 *  @filename   :   epdif.h
 *  @brief      :   Header file of epdif.cpp providing EPD interface functions
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

#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>
#include "mgos_config.h"
#include "mgos_event.h"

// Pin definition
#define RST_PIN         mgos_sys_config_get_epd_rst_gpio()
#define DC_PIN          mgos_sys_config_get_epd_dc_gpio()
#define CS_PIN          mgos_sys_config_get_epd_cs_gpio()
#define BUSY_PIN        mgos_sys_config_get_epd_busy_gpio()

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
    // static void WaitUntilIdle(void);
};

/*
 * These events are registered by the MGOS core.
 * Other events could be registered by the external libraries.
 */
#define MGOS_EVENT_EPD MGOS_EVENT_BASE('E', 'P', 'D')

/*
 * System mos events
 */
enum mgos_event_epd {
  /*
   * Fired when the EPD starts the render cycle (upto 15 secs)
   * ev_data: NULL
   */
  MGOS_EVENT_BUSY = MGOS_EVENT_EPD,

  /*
   * Fired when the EPD has finished rendering.
   * ev_data: NULL
   */
  MGOS_EVENT_IDLE
};

#endif

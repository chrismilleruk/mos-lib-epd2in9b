# Mongoose OS Demo app for the Waveshare E-paper display 2.9in (B)

## Overview

This is a skeleton app to demonstrate how to integrate the Waveshare EPD Demo code with Mongoose OS.

<img style="float: right; padding-left: 1rem;"
  src="assets/2.9inch-e-paper-module-b-4.jpg"
  width="25%">
  
- EPD Module:
https://www.waveshare.com/wiki/2.9inch_e-Paper_Module_(B)
- Demo code: https://www.waveshare.com/wiki/File:2.9inch_e-paper_module_b_code.7z

## Pin configuration

### ESP32 (Espressif)

| EPD Module | | ESP32 |
|-|-|-|
| BUSY | ![purple](https://placehold.it/15/a3a/a3a) | 4 |
| RST | ![white](https://placehold.it/15/fff/fff) | 16 |
| DC | ![green](https://placehold.it/15/3d3/3d3) | 17 |
| CS | ![orange](https://placehold.it/15/f93/f93) | 5 |
| CLK | ![yellow](https://placehold.it/15/fd3/fd3) | 18 |
| DIN | ![blue](https://placehold.it/15/33f/33f) | 23 |
| GND | ![black](https://placehold.it/15/000/000) | GND |
| 3.3V | ![red](https://placehold.it/15/f33/f33) | 3V3 |

## How to install this app

- Install and start [mos tool](https://mongoose-os.com/software.html)
- Switch to the Project page, find and import this app, build and flash it:

<p align="center">
  <img src="https://mongoose-os.com/images/app1.gif" width="75%">
</p>

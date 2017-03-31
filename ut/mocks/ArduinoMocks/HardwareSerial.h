/*
  HardwareSerial.h - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 28 September 2010 by Mark Sproul
  Modified 8 Mach 2017 by Lukasz Drozdz
*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include "GlobalObjectMockTemplate.h"
#include "WString.h"
#include "Stream.h"
#include "gmock/gmock.h"

GLOBAL_MOCK_OBJECT_DEFINISION_H(
    Serial,
    {
      MOCK_METHOD1(write, size_t(const char *str));
      MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));
      MOCK_METHOD2(print, size_t(double, int));
      MOCK_METHOD2(println, size_t(int, int));
      MOCK_METHOD0(println, size_t(void));
      MOCK_METHOD1(begin, uint8_t(uint16_t));
      MOCK_METHOD0(end, void());
      MOCK_METHOD0(available, uint8_t());
      MOCK_METHOD0(read, uint8_t());
      MOCK_METHOD0(flush, void());
      // inherited from Stream
      STREAM_MOCK_METHODS();
    },
    {
      MOCK_OBJECT_GLOBAL_METHOD(write);
      MOCK_OBJECT_GLOBAL_METHOD(flush);
      MOCK_OBJECT_GLOBAL_METHOD(end);
      MOCK_OBJECT_GLOBAL_METHOD(begin);
      MOCK_OBJECT_GLOBAL_METHOD(read);
      MOCK_OBJECT_GLOBAL_METHOD(available);
      // inherited from Stream
      STREAM_MOCK_OBJECT_GLOBAL_METHODS();
    })


// Define config for Serial.begin(baud, config);
#define SERIAL_5N1 0x00
#define SERIAL_6N1 0x02
#define SERIAL_7N1 0x04
#define SERIAL_8N1 0x06
#define SERIAL_5N2 0x08
#define SERIAL_6N2 0x0A
#define SERIAL_7N2 0x0C
#define SERIAL_8N2 0x0E
#define SERIAL_5E1 0x20
#define SERIAL_6E1 0x22
#define SERIAL_7E1 0x24
#define SERIAL_8E1 0x26
#define SERIAL_5E2 0x28
#define SERIAL_6E2 0x2A
#define SERIAL_7E2 0x2C
#define SERIAL_8E2 0x2E
#define SERIAL_5O1 0x30
#define SERIAL_6O1 0x32
#define SERIAL_7O1 0x34
#define SERIAL_8O1 0x36
#define SERIAL_5O2 0x38
#define SERIAL_6O2 0x3A
#define SERIAL_7O2 0x3C
#define SERIAL_8O2 0x3E

#endif

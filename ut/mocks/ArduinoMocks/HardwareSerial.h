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

#include "GlobalMockTemplate.h"
#include "WString.h"
#include "gmock/gmock.h"


class HardwareSerial
{
public:

  void begin(unsigned long);
  void begin(unsigned long, uint8_t);
  void end();
  virtual int available(void);
  virtual int peek(void);
  virtual int read(void);
  virtual void flush(void);
  virtual size_t write(uint8_t);
  inline size_t write(unsigned long n) { return write((uint8_t)n); }
  inline size_t write(long n) { return write((uint8_t)n); }
  inline size_t write(unsigned int n) { return write((uint8_t)n); }
  inline size_t write(int n) { return write((uint8_t)n); }

  void setTimeout(unsigned long timeout);  // sets maximum milliseconds to wait for stream data, default is 1 second

  bool find(char *target);   // reads data from the stream until the target string is found
  // returns true if target string is found, false if timed out (see setTimeout)

  bool find(char *target, size_t length);   // reads data from the stream until the target string of given length is found
  // returns true if target string is found, false if timed out

  bool findUntil(char *target, char *terminator);   // as find but search ends if the terminator string is found

  bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen);   // as above but search ends if the terminate string is found


  long parseInt(); // returns the first valid (long) integer value from the current position.
  // initial characters that are not digits (or the minus sign) are skipped
  // integer is terminated by the first character that is not a digit.

  float parseFloat();               // float version of parseInt

  size_t readBytes( char *buffer, size_t length); // read chars from stream into buffer
  // terminates if length characters have been read or timeout (see setTimeout)
  // returns the number of characters placed in the buffer (0 means no valid data found)

  size_t readBytesUntil( char terminator, char *buffer, size_t length); // as readBytes with terminator character
  // terminates if length characters have been read, timeout, or if the terminator character  detected
  // returns the number of characters placed in the buffer (0 means no valid data found)

  // Arduino String functions to be added here
  String readString();
  String readStringUntil(char terminator);

  protected:
  long parseInt(char skipChar); // as above but the given skipChar is ignored
  // as above but the given skipChar is ignored
  // this allows format characters (typically commas) in values to be ignored

  float parseFloat(char skipChar);  // as above but the given skipChar is ignored
};

class SerialMock {
  public:
    MOCK_METHOD0(getWriteError, int());
    MOCK_METHOD0(clearWriteError, void());
    MOCK_METHOD1(write, size_t(uint8_t));
    MOCK_METHOD1(write, size_t(const char *str));
    MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));

    MOCK_METHOD1(print, size_t(const char[]));
    MOCK_METHOD1(print, size_t(char));
    MOCK_METHOD2(print, size_t(unsigned char, int));
    MOCK_METHOD2(print, size_t(int, int));
    MOCK_METHOD2(print, size_t(unsigned int, int));
    MOCK_METHOD2(print, size_t(long, int));
    MOCK_METHOD2(print, size_t(unsigned long, int));
    MOCK_METHOD2(print, size_t(double, int));

    MOCK_METHOD1(println, size_t(const char[]));
    MOCK_METHOD1(println, size_t(char));
    MOCK_METHOD2(println, size_t(int, int));
    MOCK_METHOD0(println, size_t(void));

    MOCK_METHOD1(begin, uint8_t(uint16_t));

    MOCK_METHOD0(available, uint8_t());
    MOCK_METHOD0(read, uint8_t());

    MOCK_METHOD0(flush, void());

    /* Not implemented yet
    MOCK_METHOD2(println, size_t(unsigned char, int));
    MOCK_METHOD2(println, size_t(unsigned int, int));
    MOCK_METHOD2(println, size_t(long, int));
    MOCK_METHOD2(println, size_t(unsigned long, int));
    MOCK_METHOD2(println, size_t(double, int));
    */
};

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

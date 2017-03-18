#ifndef PRINT_H
#define PRINT_H

#include <stdio.h> // for size_t

#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

#define PRINT_MOCK_METHODS()\
MOCK_METHOD0(getWriteError, int());\
MOCK_METHOD0(clearWriteError, void());\
MOCK_METHOD1(print, size_t(const String&));\
MOCK_METHOD1(println, size_t(const String&));\

#define PRINT_MOCK_GLOBAL_METHODS()\
MOCK_GLOBAL_METHOD(getWriteError, int);\
MOCK_GLOBAL_METHOD(clearWriteError, void);\
MOCK_GLOBAL_METHOD(print, size_t);\
MOCK_GLOBAL_METHOD(println, size_t);\


/*class Print
{
  public:
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str);
    virtual size_t write(const uint8_t *buffer, size_t size);

    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
};*/

#endif //PRINT_H

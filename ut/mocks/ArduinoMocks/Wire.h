#ifndef __Wire_h__
#define __Wire_h__

#include <stdint.h>
#include <gmock/gmock.h>

#define BUFFER_LENGTH 32

class WireMockImplementation
{

public:
  MOCK_METHOD0(begin, void());
  MOCK_METHOD1(begin, void(uint8_t));
  MOCK_METHOD1(begin, void(int));
  MOCK_METHOD1(beginTransmission, void(uint8_t));
  MOCK_METHOD0(endTransmission, uint8_t(void));
  MOCK_METHOD1(endTransmission, uint8_t(uint8_t));
  MOCK_METHOD2(requestFrom, uint8_t(uint8_t, uint8_t));
  MOCK_METHOD3(requestFrom, uint8_t(uint8_t, uint8_t, uint8_t));
  MOCK_METHOD2(requestFrom, uint8_t(int, int));
  MOCK_METHOD3(requestFrom, uint8_t(int, int, int));
  MOCK_METHOD1(write, size_t(uint8_t));
  MOCK_METHOD1(write, size_t(unsigned long));
  MOCK_METHOD1(write, size_t(unsigned int));
  MOCK_METHOD1(write, size_t(long));
  MOCK_METHOD1(write, size_t(int));
  MOCK_METHOD2(write, size_t(const uint8_t *, size_t));
  MOCK_METHOD0(available, int());
  MOCK_METHOD0(read, int());
  MOCK_METHOD0(peek, int());
  MOCK_METHOD0(flush, void());
  MOCK_METHOD1(onReceive, void( void (*)(int) ));
  MOCK_METHOD1(onRequest, void( void (*)(int) ));

};

class WireMockInstanceWrapper
{

};

WireMockImplementation* WireMockInstance();
void releaseWireMock();

#endif

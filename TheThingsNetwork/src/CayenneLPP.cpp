// Adapted from https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/

// Copyright © 2017 The Things Network
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.

#include "CayenneLPP.h"


CayenneLPP::CayenneLPP(uint8_t size) : maxsize(size)
{
  buffer = (uint8_t *)malloc(size);
  reset();
}

CayenneLPP::~CayenneLPP(void)
{
  free(buffer);
}

void CayenneLPP::reset(void)
{
  cursor = 0;
}

uint8_t CayenneLPP::getSize(void)
{
  return cursor;
}

uint8_t *CayenneLPP::getBuffer(void)
{
  //    uint8_t[cursor] result;
  //    memcpy(result, buffer, cursor);
  //    return result;
  return buffer;
}

uint8_t CayenneLPP::copy(uint8_t *dst)
{
  memcpy(dst, buffer, cursor);
  return cursor;
}


uint8_t CayenneLPP::addDigital(uint8_t value)
{

    buffer[cursor++] = value;

	return cursor;
}



uint8_t CayenneLPP::addAnalog( uint8_t value){
	
	int16_t val = value * 100;
	
    buffer[cursor++] = val >> 8;
    buffer[cursor++] = val;
	
	return cursor;
	
}

uint8_t CayenneLPP::addLuminosity( uint16_t lux)
{
 
 
  buffer[cursor++] = lux >> 8;
  buffer[cursor++] = lux;

  return cursor;
}

uint8_t CayenneLPP::addPresence( uint8_t value)
{
 
  buffer[cursor++] = value;

  return cursor;
}

uint8_t CayenneLPP::addTemperature( float celsius)
{
 
  int16_t val = celsius * 10;
 
  buffer[cursor++] = val >> 8;
  buffer[cursor++] = val;

  return cursor;
}

uint8_t CayenneLPP::addRelativeHumidity( float rh)
{

  buffer[cursor++] = rh * 2;

  return cursor;
}

uint8_t CayenneLPP::addAccelerometer( float x, float y, float z)
{

  int16_t vx = x * 1000;
  int16_t vy = y * 1000;
  int16_t vz = z * 1000;
  buffer[cursor++] = vx >> 8;
  buffer[cursor++] = vx;
  buffer[cursor++] = vy >> 8;
  buffer[cursor++] = vy;
  buffer[cursor++] = vz >> 8;
  buffer[cursor++] = vz;

  return cursor;
}




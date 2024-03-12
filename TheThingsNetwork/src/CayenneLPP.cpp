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
//deze functie is mogelijk ook overbodig dus kijken of deze ook weg kan


uint8_t CayenneLPP::addDigital(uint8_t channel, uint8_t value, uint8_t mode)
{
//if((cursor + LPP_DIGITAL_SIZE) > maxsize){
//		return 0;
//	}
//	buffer[cursor++] = channel;
//	switch (mode){
//	case 0:
//	buffer[cursor++] = LPP_DIGITAL_INPUT;
//	break;
//	case 1:
//	buffer[cursor++] = LPP_DIGITAL_OUTPUT;
//	break;
//	}
    buffer[cursor++] = value;

	return cursor;
}
//aa


uint8_t CayenneLPP::addAnalog(uint8_t channel, uint8_t value, uint8_t mode){
	//if((cursor + LPP_ANALOG_SIZE) > maxsize){ 
	//	return 0;
	//}
	int16_t val = value * 100;
	//buffer[cursor++] = channel;
	//switch (mode){
	//case 2:
	//buffer[cursor++] = LPP_ANALOG_INPUT;
	//break;
	
	//case 3:
	//buffer[cursor++] = LPP_ANALOG_OUTPUT;
	//break;
	//}
    buffer[cursor++] = val >> 8;
    buffer[cursor++] = val;
	
	return cursor;
	
}

uint8_t CayenneLPP::addLuminosity(uint8_t channel, uint16_t lux)
{
 // if ((cursor + LPP_LUMINOSITY_SIZE) > maxsize)
 // {
 //   return 0;
 // }
  ///buffer[cursor++] = channel;
 // buffer[cursor++] = LPP_LUMINOSITY;
  buffer[cursor++] = lux >> 8;
  buffer[cursor++] = lux;

  return cursor;
}

uint8_t CayenneLPP::addPresence(uint8_t channel, uint8_t value)
{
 // if ((cursor + LPP_PRESENCE_SIZE) > maxsize)
 // {
 //   return 0;
 // }
 // buffer[cursor++] = channel;
 // buffer[cursor++] = LPP_PRESENCE;
  buffer[cursor++] = value;

  return cursor;
}

uint8_t CayenneLPP::addTemperature(uint8_t channel, float celsius)
{
 // if ((cursor + LPP_TEMPERATURE_SIZE) > maxsize){ 
  //  return 0;
  //}
  int16_t val = celsius * 10;
 // buffer[cursor++] = channel;
 // buffer[cursor++] = LPP_TEMPERATURE;
  buffer[cursor++] = val >> 8;
  buffer[cursor++] = val;

  return cursor;
}
//aa
uint8_t CayenneLPP::addRelativeHumidity(uint8_t channel, float rh)
{
 // if ((cursor + LPP_RELATIVE_HUMIDITY_SIZE) > maxsize)
 // {
 //   return 0;
  //}
  //buffer[cursor++] = channel;
  //buffer[cursor++] = LPP_RELATIVE_HUMIDITY;
  buffer[cursor++] = rh * 2;

  return cursor;
}

uint8_t CayenneLPP::addAccelerometer(uint8_t channel, float x, float y, float z)
{
  //if ((cursor + LPP_ACCELEROMETER_SIZE) > maxsize)
  //{
  //  return 0;
  //}
  int16_t vx = x * 1000;
  int16_t vy = y * 1000;
  int16_t vz = z * 1000;

  //buffer[cursor++] = channel;
  //buffer[cursor++] = LPP_ACCELEROMETER;
  buffer[cursor++] = vx >> 8;
  buffer[cursor++] = vx;
  buffer[cursor++] = vy >> 8;
  buffer[cursor++] = vy;
  buffer[cursor++] = vz >> 8;
  buffer[cursor++] = vz;

  return cursor;
}

//void CayenneLPP::makepayload2(){
//
//
//
//
//
//}


// Adapted from https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/

// Copyright © 2017 The Things Network
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.



#ifndef _CAYENNE_LPP_H_
#define _CAYENNE_LPP_H_

#include <Arduino.h>

//LPP_BATTERY = // TODO Unsupported in IPSO Smart Object
//LPP_PROXIMITY = // TODO Unsupported in IPSO Smart Object


/// denotes how large the values are and what types.
//#define LPP_DIGITAL_INPUT 0         // 1 byte
//#define LPP_DIGITAL_OUTPUT 1        // 1 byte
//#define LPP_ANALOG_INPUT 2          // 2 bytes, 0.01 signed
//#define LPP_ANALOG_OUTPUT 3         // 2 bytes, 0.01 signed
//#define LPP_LUMINOSITY 101          // 2 bytes, 1 lux unsigned
//#define LPP_PRESENCE 102            // 1 byte, 1
//#define LPP_TEMPERATURE 103         // 2 bytes, 0.1°C signed
//#define LPP_RELATIVE_HUMIDITY 104   // 1 byte, 0.5% unsigned
//#define LPP_ACCELEROMETER 113       // 2 bytes per axis, 0.001G
//#define LPP_BAROMETRIC_PRESSURE 115 // 2 bytes 0.1 hPa Unsigned
//#define LPP_GYROMETER 134           // 2 bytes per axis, 0.01 °/s
//#define LPP_GPS 136                 // 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter

// Data ID + Data Type + Data Size

//#define LPP_DIGITAL_SIZE 3		     //2 byes unsigned
//#define LPP_ANALOG_INPUT_SIZE 4        // 2 bytes, 0.01 signed
//#define LPP_ANALOG_OUTPUT_SIZE 4       // 2 bytes, 0.01 signed
//#define LPP_ANALOG_SIZE 4			     //
//#define LPP_LUMINOSITY_SIZE 4          // 2 bytes, 1 lux unsigned
//#define LPP_PRESENCE_SIZE 3            // 1 byte, 1
//#define LPP_TEMPERATURE_SIZE 4          // 2 bytes, 0.1°C signed
//#define LPP_RELATIVE_HUMIDITY_SIZE 3   // 1 byte, 0.5% unsigned
//#define LPP_ACCELEROMETER_SIZE 8       // 2 bytes per axis, 0.001G
//#define LPP_BAROMETRIC_PRESSURE_SIZE 4 // 2 bytes 0.1 hPa Unsigned
//#define LPP_GYROMETER_SIZE 8           // 2 bytes per axis, 0.01 °/s
//#define LPP_GPS_SIZE 11                // 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter

class CayenneLPP
{
public:
  CayenneLPP(uint8_t size);
  ~CayenneLPP();

///	\param resets the cursor to 0 so that all the elements can be rewritten again
  void reset(void);
///	\param checks and returns the length of the array
/// \return length of the array
  uint8_t getSize(void);
  
///	\param checks and returns buffer values
/// \return buffer values
  uint8_t *getBuffer(void);
  
/// \param copies block of memory
  uint8_t copy(uint8_t *buffer);

///	\param adds a digital sensor value to the array for transmitting
/// \return uses an uint8_t value
  uint8_t addDigital(uint8_t value);
///	\param adds a analog sensor value to the array for transmitting
/// \return uses an uint8_t value
  uint8_t addAnalog( uint8_t value);
///	\param adds a luminosity sensor value to the array for transmitting
/// \return uses an uint16_t value
  uint8_t addLuminosity( uint16_t lux);
///	\param adds a precense sensor value to the array for transmitting
/// \return uses an uint8_t value
  uint8_t addPresence( uint8_t value);
///	\param adds a temperature sensor value to the array for transmitting
/// \return uses an float value
  uint8_t addTemperature( float celsius);
///	\param adds a humidity sensor value to the array for transmitting
/// \return uses an float value
  uint8_t addRelativeHumidity(float rh);
///	\param adds accelermotere sensor values to the array for transmitting
/// \return uses 3 float values
  uint8_t addAccelerometer(float x, float y, float z);


	

private:
  uint8_t *buffer; ///< allocsates bytes of memory to storing variables
  uint8_t maxsize; ///< maximum length the array can be. defined in the ino file
  uint8_t cursor;  ///< pointer to the locations in the array
};

#endif

//********************************************************************
// BH1750Lib for Spark
// http://github.com/davidegironi/spark-bh1750lib
// Copyright (c) Davide Gironi, 2014 
//
// References:
//   https://github.com/claws/BH1750/
//
// Released under GPLv3.
// Please refer to LICENSE file for licensing information.
//********************************************************************

#ifndef __BH1750LIB_H
#define __BH1750LIB_H

//I2C address of the device
#define BH1750LIB_I2CADDR 0x23

//Start measurement at 1lx resolution. Measurement time is approx 120ms.
#define BH1750LIB_MODE_CONTINUOUSHIGHRES  0x10
//Start measurement at 0.5lx resolution. Measurement time is approx 120ms.
#define BH1750LIB_MODE_CONTINUOUSHIGHRES2  0x11
//Start measurement at 4lx resolution. Measurement time is approx 16ms.
#define BH1750LIB_MODE_CONTINUOUSLOWRES  0x13
//Start measurement at 1lx resolution. Measurement time is approx 120ms.
//Device is automatically set to Power Down after measurement.
#define BH1750LIB_MODE_ONETIMEHIGHRES  0x20
//Start measurement at 0.5lx resolution. Measurement time is approx 120ms.
//Device is automatically set to Power Down after measurement.
#define BH1750LIB_MODE_ONETIMEHIGHRES2  0x21
//Start measurement at 1lx resolution. Measurement time is approx 120ms.
//Device is automatically set to Power Down after measurement.
#define BH1750LIB_MODE_ONETIMELOWRES  0x23

#include "application.h"

class BH1750Lib {
    public:
        // Instantiate without initialisation, call begin to initialise
        BH1750Lib();
	
	// Instantiate and initialise
	BH1750Lib(uint8_t mode);
	
	void begin(uint8_t mode);
	
        uint16_t lightLevel();
	
    private:
        void configure(uint8_t mode);
};

#endif

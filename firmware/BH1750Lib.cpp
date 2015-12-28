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

#include "BH1750Lib.h"

/**
 * Create instance without initialisation, need to call begin later
 */
BH1750Lib::BH1750Lib() {
}

/**
 * Setup mode and start BH1750
 */
BH1750Lib::BH1750Lib(uint8_t mode) {
  Wire.begin();
  configure(mode);
}

/**
 * Setup mode and start BH1750
 */
void BH1750Lib::begin(uint8_t mode) {
    Wire.begin();
    configure(mode);
}

/**
 * Setup BH1750 working mode
 */
void BH1750Lib::configure(uint8_t mode) {
    switch (mode) {
        case BH1750LIB_MODE_CONTINUOUSHIGHRES:
        case BH1750LIB_MODE_CONTINUOUSHIGHRES2:
        case BH1750LIB_MODE_CONTINUOUSLOWRES:
        case BH1750LIB_MODE_ONETIMEHIGHRES:
        case BH1750LIB_MODE_ONETIMEHIGHRES2:
        case BH1750LIB_MODE_ONETIMELOWRES:
            Wire.beginTransmission(BH1750LIB_I2CADDR);
            Wire.write(mode);
            Wire.endTransmission();
            delay(10);
            break;
        default:
            break;
    }
}

/**
 * Get the light level (in lux
 */
uint16_t BH1750Lib::lightLevel() {
    uint16_t level;
    
    Wire.beginTransmission(BH1750LIB_I2CADDR);
    Wire.requestFrom(BH1750LIB_I2CADDR, 2);
    level = Wire.read();
    level <<= 8;
    level |= Wire.read();
    Wire.endTransmission();
    
    level = level/1.2; // convert to lux
    return level;
}

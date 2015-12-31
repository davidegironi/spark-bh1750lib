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

#include "BH1750Lib/BH1750Lib.h"

//debug to serial port
#define UARTDEBUG 1

//initialize device
BH1750Lib bh1750();

void setup() {
    bh1750.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
  
#if UARTDEBUG == 1
    Serial.begin(9600);
    Serial.println("Starting...");
#endif
}

void loop() {
    uint16_t luxvalue = bh1750.lightLevel();

    char szEventInfo[64];
    sprintf(szEventInfo, "Light = %d lux", luxvalue);

    Spark.publish("bh1750info", szEventInfo);
    
#if UARTDEBUG == 1
    //read
    Serial.print("Light: ");
    Serial.print(luxvalue);
    Serial.println("lux");
#endif
    
    //wait for the next reading
    delay(2000);
}

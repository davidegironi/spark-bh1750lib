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

//initialize devide
BH1750Lib bh1750(BH1750LIB_MODE_CONTINUOUSHIGHRES);

void setup() {
    #if UARTDEBUG == 1
    Serial.begin(9600);
    Serial.println("Starting...");
    #endif
}

void loop() {
    //read 
    Serial.print("Light: ");
    Serial.print(bh1750.lightLevel());
    Serial.println("lux");
    
    //wait for the next reading
    delay(2000);
}
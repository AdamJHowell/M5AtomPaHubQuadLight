/**
 * M5AtomPaHubQuadLight.ino - Read light values from four M5Stack DLIGHT sensors.
 */
#include <M5_DLight.h>
#include "Wire.h"


unsigned long lastLoop = 0;                      // The time when the most recent loop completed.
const unsigned long loopDelay = 10;              // The maximum value of 4,294,967,295 allows for a delay of about 49.7 days.
const char *sketchName = "M5AtomPaHubQuadLight"; // The name of this sketch.
const int PCA_ADDRESS = 0x70;                    // The I2C address of the Pa.HUB.
const unsigned int numSensors = 4;               // The number of sensors.
uint16_t luxValues[4];                            // An array to hold light values.
M5_DLight sensorArray[4];                        // An array to hold sensors.
unsigned int sensorAddresses[4];                 // An array of sensor port numbers {0, 1, 4, 5};


/*
 * The channelSelect function changes the current active channel of the PaHUB I2C multiplexer.
 */
void channelSelect( uint8_t i )
{
   if( i > 7 )
      return;
   Wire.beginTransmission( PCA_ADDRESS );
   Wire.write( 1 << i );
   Wire.endTransmission();
} // End of channelSelect()


void setup()
{
   Serial.begin( 115200 );
   if( !Serial )
      delay( 1000 );

   Wire.begin();

   sensorAddresses[0] = 0;
   sensorAddresses[1] = 1;
   sensorAddresses[2] = 4;
   sensorAddresses[3] = 5;
   /*
   * Sensor modes:
   * CONTINUOUSLY_H_RESOLUTION_MODE
   * CONTINUOUSLY_H_RESOLUTION_MODE2
   * CONTINUOUSLY_L_RESOLUTION_MODE
   * ONE_TIME_H_RESOLUTION_MODE
   * ONE_TIME_H_RESOLUTION_MODE2
   * ONE_TIME_L_RESOLUTION_MODE
   */
   for( uint8_t i = 0; i < numSensors; i++ )
   {
      channelSelect( sensorAddresses[i] );
      sensorArray[i].begin();
      sensorArray[i].setMode( CONTINUOUSLY_H_RESOLUTION_MODE );
   }
   Serial.println( "\nI2C scanner and lux sensor are ready!" );
}


void loop()
{
   if( ( lastLoop == 0 ) || ( millis() - lastLoop ) > loopDelay )
   {
      // Read all sensors before acting on the values.
      for( uint8_t i = 0; i < numSensors; i++ )
      {
         channelSelect( sensorAddresses[i] );
         luxValues[i] = sensorArray[i].getLUX();
      }
      // Print values in a format the Arduino Serial Plotter can use.
      Serial.printf( "TopLeft:%d TopRight:%d BottomLeft:%d BottomRight:%d\n", luxValues[0], luxValues[1], luxValues[2], luxValues[3] );
      lastLoop = millis();
   }
}

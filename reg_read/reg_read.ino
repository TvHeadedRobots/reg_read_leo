/**
 * Pins:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 *
 * Configurable:
 * CE -> 8
 * CSN -> 7
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

// Read and print RF_SETUP
byte rf_setup = 0;
byte reg_val = 0;
byte reg_wr = 01;

void setup() {
  Serial.begin(9600);
  Serial.println( "Starting wireless..." );

  // Setup
  //Mirf.cePin = 9;
  //Mirf.csnPin = 10;  
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
  
  delay(5000);
  Serial.println("test");
 
  //Mirf.writeRegister(RF_PWR, &reg_wr, sizeof(reg_wr));
  Mirf.configRegister(RF_PWR, 2);
  
  Mirf.readRegister( RF_SETUP, &rf_setup, sizeof(rf_setup) );
  Mirf.readRegister( RF_PWR, &reg_val, sizeof(reg_val) );
  Serial.print( "rf_setup = " );
  Serial.println( rf_setup, BIN );
  Serial.print("Register Value: ");
  Serial.println(reg_val, BIN);

  Serial.println( "Wireless initialized!" );
}

void loop() {
  
  Serial.print( "rf_setup = " );
  Serial.println( rf_setup, BIN );
  Serial.print("Register Value: ");
  Serial.println(reg_val, BIN);
  delay(5000);
}

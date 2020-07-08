/*
 * This sketch is an expample of recieving commands from the DUMBORC-X6 2.4Ghz 6 Channel RC Transmitter.
 * Using the pulseIn() function isn't the best way to do this but it works for demonstraiting the connection and reading the pulse widths.
 * Using interups is the more efficient use of the cpu in real life.
 */
#include <Wire.h>
//set up on a Teensy 3.5 
const int CH1_RADIO_PIN   =  2;//steering
const int CH2_RADIO_PIN   =  3;//throttle with reverse
const int CH3_RADIO_PIN   =  5;//2 state toggle button 
const int CH4_RADIO_PIN   =  4;//three position switch
const int CH5_RADIO_PIN   =  6;//top left potentiometer
const int CH6_RADIO_PIN   =  7;//top right potentiometer

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  rcInit();
  
  delay(100); // For switches? 

}

void loop() {
  systemTest1();
  delay(500);
  Serial.println();
}

//Read pw of reciever pins in micros()
void systemTest1() {

  Serial.print("Ch1 = ");
  Serial.print(pulseIn(CH1_RADIO_PIN,HIGH));
  Serial.print("\t");

  Serial.print("Ch2 = ");
  Serial.print(pulseIn(CH2_RADIO_PIN,HIGH));
  Serial.print("\t");

  Serial.print("Ch3 = ");
  Serial.print(pulseIn(CH3_RADIO_PIN,HIGH));
  Serial.print("\t");

  Serial.print("Ch4 = ");
  Serial.print(pulseIn(CH4_RADIO_PIN,HIGH));
  Serial.print("\t");

  Serial.print("Ch5 = ");
  Serial.print(pulseIn(CH5_RADIO_PIN,HIGH));
  Serial.print("\t");

  Serial.print("Ch6 = ");
  Serial.print(pulseIn(CH6_RADIO_PIN,HIGH));
  Serial.print("\t");

  
}


/*****************************************************************************-
 *  rcInit()
 *****************************************************************************/
void rcInit() {
  pinMode(CH1_RADIO_PIN, INPUT);
  pinMode(CH2_RADIO_PIN, INPUT);
  pinMode(CH3_RADIO_PIN, INPUT);
  pinMode(CH4_RADIO_PIN, INPUT);
  pinMode(CH5_RADIO_PIN, INPUT);
  pinMode(CH6_RADIO_PIN, INPUT);
}

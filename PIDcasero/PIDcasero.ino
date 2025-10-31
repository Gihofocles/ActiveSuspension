#include <ESP32Servo.h>
#include <Wire.h> 

float med;
Servo myservo;
int i = 0;
float distance = 0.0;


void setup() {
  
  myservo.attach(13);
  myservo.write(80);
  delay(100);
  myservo.write(160);
  delay(100);
  myservo.write(90);
  Serial.begin(115200);
  pinMode()
  

}

void loop() {
  
  VL53L0X_RangingMeasurementData_t measure;
    //Serial.print("Reading a measurement... ");
        lox.rangingTest(&measure, false);
        if (measure.RangeStatus != 4) {  // phase failures have incorrect data
         med = measure.RangeMilliMeter;
          //med = med/10;
        Serial.print("Distance (mm): "); Serial.println(med);
        } else {
          //Serial.println(" out of range ");
      }  
  if(med<=distance_setpoint){
    i=i-10;
    Serial.println("a");
  }
  if(med>distance_setpoint){
    i=i+10;
    Serial.println("b");
  }

  if(i<80){
    i=80;
  }
  if(i>160){
    i=160;
  }
  Serial.print("Angulo acutal: ");Serial.println(i);
  myservo .write(i);
}

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to use the Menu Widget.

  App project setup:
    Menu widget attached to V1 (put 3 items in it)
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Z_TBzZMtZ7ozMdqtFVMFUV3kb1sVsWuZ";
char ssidblynk[] = "*=* dP *=*";
char passblynk[] = "djfa1953";

#define echoPin 8 // Echo Pin
#define trigPin 1 // Trigger Pin
long duration, distance; // Duration used to calculate distance

Ticker Triger;
void changeState()
{
  digitalWrite(trigPin, !(digitalRead(trigPin)));  //Invert Current State of LED
}
Ticker Blink;
void staticBlink() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
WidgetLCD lcd(V2);


BLYNK_WRITE(V1) {
  switch (param.asInt())
  {
    case 1: // Item 1
      
      Serial.println("Long Duration");
      lcd.clear(); //Use it to clear the LCD Widget
      lcd.print(0, 0, "Long Duration");
      Serial.println("Long Duration");
      Blink.attach(0.2, staticBlink); //Use attach_ms if you need time in ms
      break;
    
     
    case 2: // Item 2
    
      Serial.println("Short Duration"); 
      lcd.clear(); //Use it to clear the LCD Widget
      lcd.print(0, 0, "Short Duration");
      Serial.println("Short Duration");
      Blink.attach_ms(2, staticBlink); //Use attach_ms if you need time in ms
      break;
  
    case 3: // Item 3
      Serial.println("Item 3 selected");
     

        /* The following trigPin/echoPin cycle is used to determine the
       distance of the nearest object by bouncing soundwaves off of it. */ 
       digitalWrite(trigPin, LOW); 
       Triger.attach_ms(0.002, changeState); 
        Triger.detach();
       digitalWrite(trigPin, HIGH);
       Triger.attach_ms(0.01, changeState); 
       Triger.detach();
       digitalWrite(trigPin, LOW);
       duration = pulseIn(echoPin, HIGH);
       
        // Calculating the distance
      distance= duration*0.035/2;//in Chlef 350*0.0001=0.035:in cm/micros
      //LCD BLYNK
      lcd.clear(); //Use it to clear the LCD Widget
      lcd.print(0, 0, "DISTANCE IN CM");
      lcd.print(0, 1, distance "Cm");
      
       Serial.println(distance);
      
      break;
    default:
      Serial.println("Unknown item selected");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssidblynk, passblynk);
 
  }

void loop()
{
  Blynk.run();
//  timer.run(); // Initiates SimpleTimer
}

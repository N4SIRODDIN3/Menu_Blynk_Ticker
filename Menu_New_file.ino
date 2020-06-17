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
char auth[] = "))))))))))))";
char ssidblynk[] = "*=* dP *=*";
char passblynk[] = "_è-('è_çà";

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
  int value = param.asInt();
//Create menu list items from hardwar
  BlynkParamAllocated items(128); // list length, in bytes
    items.add("RPA");//value=1
    items.add("EC8");//value=2
    items.add("ASCE");//value=3
    Blynk.setProperty(V1, "labels", items);
  if (value == 1) {
    Serial.println("RPA");
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "RPA");
    //Create new menu list items from hardwar
    BlynkParamAllocated items(128); // list length, in bytes
    items.add("voile L");
    items.add("voile U");
    items.add("voile T");
    items.add("Back");//value=4 to return to the main menu
    Blynk.setProperty(V1, "labels", items);
  } else if (value == 2) {
    Serial.println("EC8");
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "Eurocode 8"); 
    // If item 2 is selected, change menu items...
    BlynkParamAllocated items(128); // list length, in bytes
    items.add("voile L");
    items.add("voile U");
    items.add("voile T");
    items.add("Back");
    Blynk.setProperty(V1, "labels", items);
  } 
  else if(value==3){
    Serial.println("ASCE");    
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "ASCE");
    // If item 2 is selected, change menu items...
    BlynkParamAllocated items(128); // list length, in bytes
    items.add("voile L");
    items.add("voile U");
    items.add("voile T");
    items.add("Back");
    Blynk.setProperty(V1, "labels", items);
  }
  else {
    BlynkParamAllocated items(128); // list length, in bytes
    items.add("RPA");
    items.add("EC8");
    items.add("ASCE");
    Blynk.setProperty(V1, "labels", items);
  }
}
  /*if (value == 1) {
    Serial.println("RPA99v2003");
    // If item 1 is selected, change menu items...
    BlynkParamAllocated items(128); // list length, in bytes
    items.add("VOile L");
    //Do what do you want here
    Serial.println("VOile L Selected Yessssss");
    lcd.clear(); //Use it to clear the LCD Widget
    int i=2465768;
    lcd.print(0, 0, i);
    Serial.println(i);
    //---------end----------- 
    items.add("Voile U");
    Serial.println("VOile UUU Selected Yessssss");
    lcd.clear(); //Use it to clear the LCD Widget
    int s=111;
    lcd.print(0, 0, s);
    Serial.println(s);
    items.add("Retour au menu principal");
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "Choisir le reglement");
    value=0;
    Blynk.setProperty(V1, "labels", items);
    
    // You can also use it like this:
    //Blynk.setProperty(V1, "labels", "item 1", "item 2", "item 3");

  } else if (value == 2) {
      Serial.println("Eurocode 8"); 
      lcd.clear(); //Use it to clear the LCD Widget
      lcd.print(0, 0, "Eurocode 8");
      Serial.println("Eurocode 8");
      Blink.attach(1, staticBlink); //Use attach_ms if you need time in ms
     
  } else {
    Serial.println("Unknown item selected");
  }
}
*/ 
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

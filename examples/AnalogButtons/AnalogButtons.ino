
/* Personalized example tested on ESP8266 and touch sensor multiswitch
Wiring

                         GND
			 ---
                        -----  
                          |
                          |
                          | 
                          <
                          < R=100K
                          <
       3xTouch TTP223                 |
         (L)Sw1    R=2K   |
VCC 3,3v ---/ ---^^^^^----|
                          |
         (C)Sw2    R=5K   |           ESP
VCC 3,3v ---/ ---^^^^^----|-----------A0 (input)
	                  |
         (R)Sw3    R=10K  |
VCC 3,3v ---/ ---^^^^^----|
*/

#include <AnalogButtons.h>


#define ANALOG_PIN A0

// A call back function that you pass into the constructor of AnalogButtons, see example
// below. Alternativly you could extend the Button class and re-define the methods pressed() 
// or held() which are called 
void b1Click() {  
    Serial.println("button L clicked"); 
}

void b2Click() {  
    Serial.println("button C clicked"); 
}
void b2Hold() {  
    Serial.println("button C held"); 
}

void b3Click() {  
    Serial.println("button R clicked"); 
}
void b3Hold() {  
    Serial.println("button R held"); 
}

void b4Click() {  
    Serial.println("button L+C clicked"); 
}
void b4Hold() {  
    Serial.println("button L+C held"); 
}

void b5Click() {  
    Serial.println("button C+R clicked"); 
}
void b5Hold() {  
    Serial.println("button C+R held"); 
}

AnalogButtons analogButtons(ANALOG_PIN, INPUT);
Button b1 = Button(674, &b1Click);
Button b2 = Button(276, &b2Click, &b2Hold);
Button b3 = Button(148, &b3Click, &b3Hold);
// Default hold activation frequency of 250ms is overriden for button 4 so to 
// get it activated (hold function invoked) only every 500ms
Button b4 = Button(951, &b4Click, &b4Hold, 1000, 500);
// Default hold duration is 1 second, lets make it 5 seconds for button5
Button b5 = Button(413, &b5Click, &b5Hold, 5000);

void setup() {
  Serial.begin(9600); 
  Serial.println("Testing your Analog buttons");
  
  analogButtons.add(b1);
  analogButtons.add(b2);
  analogButtons.add(b3);
  analogButtons.add(b4);
  analogButtons.add(b5);  
 }
 
void loop() {  
  // To check values when button are pressed
  analogButtons.check();
  
  // To configure the MAX/Min values for each button: 
  // uncomment the following line and make sure you've called Serial.begin(9600) 
  // Then in turn hold down each button, noting down the max/min values
  
  //configure();
}

void configure() {
  unsigned int value = analogRead(ANALOG_PIN);
  Serial.println(value);
  delay(250);
}

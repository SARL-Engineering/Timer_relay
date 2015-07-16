
/* This code controlls a relay box that can engage for a desired time selected by a knob.
 * The time parameters can be changed in the "shake" function. 
 * Author: Aaron Rito
 * Date 7/10/15
 */
int onswitch = 2;
int LED = 4;
int relay = 6;

void setup() {

    //Serial.begin(9600); //debug line
    pinMode (LED, OUTPUT);
    pinMode (relay, OUTPUT);
    pinMode (onswitch, INPUT_PULLUP);

}

void loop() {
    
    int sensor = analogRead (A0);
    sensor = map(sensor, 0, 1023, 0, 10);
    int button = digitalRead (onswitch);
    
       if (button == LOW) {

            shake();
       }
}

void shake() {
  
    int i =0;
    int sensor = analogRead (A0);
    sensor = map(sensor, 0, 1023, 0, 10);
    Serial.println (sensor);

        for (i=0; i < sensor; i++) {   // this loops flashes the button lamp accroding to selected value

            digitalWrite (LED, HIGH);
            delay (500);
            digitalWrite (LED, LOW);
            delay (500);
        }

     delay(3000);                 // enough time to abort if wrong setting selected 
     digitalWrite (LED, HIGH);
     digitalWrite (relay, HIGH);
     delay (sensor * 1000);     // change this value to change time the relay is energized
     digitalWrite (LED, LOW);
     digitalWrite (relay, LOW);
     delay (5000);            // prevents restarting the machine unintentionally

        for (i=0; i < 8; i++) {  // this loop flashes the light to let the user know the relay is ready to use again 
            
            digitalWrite (LED, HIGH);
            delay (200);
            digitalWrite (LED, LOW);
            delay (200);
        }          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  }
  


//Constants: 
const int glassesID = 1;
const int buttonPin = 2;
const int ledPin =  13;

//Variables:
int buttonState; //Value from pot

void setup() {
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module

}

void loop() {
    
    //Read the value from switch
    buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);  
    Serial.print("On");
  }
  else
  {
    digitalWrite(ledPin, LOW);  
    Serial.print("Off");
  }
  Serial.print(" Glasses ID: 0");
  Serial.print(glassesID);
  Serial.println();
  
  delay(1000);
}
  

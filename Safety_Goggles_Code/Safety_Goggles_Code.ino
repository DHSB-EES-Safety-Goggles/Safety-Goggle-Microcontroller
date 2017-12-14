/*   ~ Simple Arduino - xBee Transmitter sketch ~

  Read an analog value from potentiometer, then convert it to PWM and finally send it through serial port to xBee.
  The xBee serial module will send it to another xBee (resiver) and an Arduino will turn on (fade) an LED.
  The sending message starts with '<' and closes with '>' symbol. 
  
  Dev: Michalis Vasilakis // Date:2/3/2016 // Info: www.ardumotive.com // Licence: CC BY-NC-SA                    */

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
    Serial.print("Off");
  }
  else
  {
    digitalWrite(ledPin, LOW);  
    Serial.print("On");
  }
  Serial.print(" Glasses ID: 0");
  Serial.print(glassesID);
  Serial.println();
  
  delay(1000);
}
  

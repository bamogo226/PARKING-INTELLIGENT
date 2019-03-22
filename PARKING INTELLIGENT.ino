#include <Servo.h>
Servo DBT;

const int  buttonPin = A0;         //IN Button for cars entering
const int  buttonPin1 = A1;       //OUT Button for cars leaving

int OUT= A4;        //SWITCH OUT to activate the OUT Button
int IN= A5;        //SWITCH IN to activate the IN Button

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses on IN button
int buttonState = 0;         // current state of the IN button 
int lastButtonState = 0;     // previous state of the IN button

int buttonPushCounter1 = 0;   // counter for the number of button presses on OUT button
int buttonState1 = 0;         // current state of the OUT button
int lastButtonState1 = 0;     // previous state of the OUT button

int numb=9;               //Number of park places

void setup() {
   
  //SERVO
  
  DBT.attach(9); 

// initialize serial communication:
  Serial.begin(9600);
  
 // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);

//initialize the switch pin as a input:
  pinMode(OUT, INPUT);  
  pinMode(IN, INPUT);       
  
  // 7-SEGMENT DISPLAY
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
}

void loop() {
  //Button functioning will be activated by the position of the switch or potentiometer
  if(digitalRead(OUT)==HIGH){
  int R= analogRead(A0);
int M= map(R, 0, 1023, 0, 180);
DBT.write(M);
delay(50); 
}

else if(digitalRead(IN)==HIGH){
int R1= analogRead(A1);
int M1= map(R1, 0, 1023, 0, 180);
DBT.write(M1);
delay(50); 
}

  //read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {

    buttonPushCounter++; 

     numb=numb-1;
    
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
    
  
else if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {

    buttonPushCounter1++; 

     numb=numb+1;
    
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter1);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  lastButtonState1 = buttonState1;
 
  // 7-SEVEN SEGMENT DISPLAY
switch(numb)
{
  case 0:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  break;

  
  case 1:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  break;

  
  case 2:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  break;

  
 case 3:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  break;
  

 case 4:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
   break;

 case 5:
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
 break;


  case 6:
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  break;

  case 7:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
   break;

  case 8:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
   break;

  case 9:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  break;
  break;
  }
 


}

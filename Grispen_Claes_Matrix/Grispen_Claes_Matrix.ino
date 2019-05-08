/*
* Auteur 1: Claes Ferre
* Auteur 2: Grispen Bart
* Link naar github repository: https://github.com/Nightwolve/C-Programming/tree/master/Grispen_Claes_Matrix
*/

int IMAGE[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,}};

//Definiëren van de uitganspinnen
const int shiftClockPin = 3;  //SH
const int latchClockPin = 4;  //ST
const int serialInputPin = 9; //DS
const int button = 2; //Button

int button_push_counter = 0;   // counter for the number of button presses
int button_state = 0;         // current state of the button
int last_button_state = 0;     // previous state of the button

//R1 - 1
//R2 - 2
//K2 - 3
//R8 - 4
//K4 - 5
//R3 - 6
//R5 - 7
//K1 - 8
//K5 - 9
//K3 - 10
//K6 - 11
//R4 - 12
//K8 - 13
//R6 - 14
//R7 - 15
//K7 - 16

word bericht1  = 0b1001000001000000;
word bericht2  = 0b1101110000000110;
word bericht3  = 0b1101001010010010;
word bericht4  = 0b1001011000110100;

word bericht5  = 0x9040;

word bericht6  = 0b0000111000001011;
word bericht7  = 0b0100010001111000;


boolean shiftLeftRight = false;

void setup() {
  //Instelen van de uitgangspinnen
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
/*button_state = digitalRead(button); //reading from button switch
  delay(100);
  if (button_state != last_button_state)
   {
       button_push_counter++;
   }
  else
   {
   }
   last_button_state = button_state;
   
   switch (button_push_counter) 
   {
    case 0:
      displayData(bericht1);
      delay(1);
      displayData(bericht2);
      delay(1);
      displayData(bericht3);
      delay(1);
      displayData(bericht4);
      delay(1);
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
    case 1:
      displayData(bericht5);
      delay(1);
      displayData(bericht6);
      delay(1);
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
    case 2:
      displayData(bericht1);
      delay(1);
      displayData(bericht2);
      delay(1);
      displayData(bericht3);
      delay(1);
      displayData(bericht4);
      delay(1);
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
      case 3:
      button_push_counter = 0;
      break;  
   }*/
   displayData(bericht5);
      //delay(1);
      //displayData(bericht6);
      //delay(1);
  }

void displayData(word message) 
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 15; i++) 
  {
    digitalWrite(serialInputPin, bitRead(message, i));
    digitalWrite(shiftClockPin, HIGH);
    digitalWrite(shiftClockPin, LOW);
  }
  digitalWrite(latchClockPin, HIGH);
  digitalWrite(latchClockPin, LOW);
}

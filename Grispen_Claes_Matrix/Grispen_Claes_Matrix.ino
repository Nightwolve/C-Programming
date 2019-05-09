/*
* Auteur 1: Claes Ferre
* Auteur 2: Grispen Bart
* Link naar github repository: https://github.com/Nightwolve/C-Programming/tree/master/Grispen_Claes_Matrix
*/

//Defining outputs
const int shiftClockPin = 3;  //SH
const int latchClockPin = 4;  //ST
const int serialInputPin = 9; //DS
const int button = 2; //Button

int button_push_counter = 0;   // counter for the number of button presses
int button_state = 0;         // current state of the button
int last_button_state = 0;     // previous state of the button

//creating the characters withing the shift register
word b1  = 0x8040;
word b2  = 0x8C96;
word b3  = 0xD220;

word a1  = 0xC040;
word a2  = 0x9CB6;
word a3  = 0xC001;

word r1  = 0x8040;
word r2  = 0x9C12;
word r3  = 0x9494;
word r4  = 0xC226;

word t1  = 0x9EF7;
word t2  = 0x8080;

word en1  = 0xB200;
word en2  = 0x4456;
word en3  = 0x4E02;
word en4  = 0x9294;
word en5  = 0xC632;

word f1  = 0x8040;
word f2  = 0x9C96;
word f3  = 0x9636;

word e1  = 0x8040;
word e2  = 0x8C96;
word e3  = 0x8636;

word smiley1  = 0xD10A;
word smiley2  = 0xB615;
word smiley3  = 0x4076;
word smiley4  = 0x4E92;

word leeg  = 0xD616;

boolean shiftLeftRight = false;

void setup() {
  //Setting the output pins
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
   button_state = digitalRead(button); //reading from button switch

  if (button_state ==LOW && button_state != last_button_state)//only reading button once per push
   {
       button_push_counter++;
   }
  else{}
   last_button_state = button_state;
   
   switch (button_push_counter) //creating a switch so you get a character after every button press
   {
    case 0: //show the character B on the matrix
      letterB();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
    case 1:
      letterA();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
    case 2:
      letterR();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 3:
      letterT();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 4:
      ampersant();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 5:
      letterF();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break; 
      
     case 6:
      letterE();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 7:
      letterR();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 8:
      letterR();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 9:
      letterE();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 10:
      smiley();
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;

     case 11:
      displayData(leeg);
      Serial.print(button_push_counter);
      Serial.print('\n');
      break;
      
     case 12:
      button_push_counter = 0;
      break;  
   }
}

void displayData(word message) //creating the shift register so your text will show correctly
{
  for (int i = 0; i <= 15; i++) //8x8 matrix = 16 rows and coloms combined
  {
    digitalWrite(serialInputPin, bitRead(message, i));
    digitalWrite(shiftClockPin, HIGH);
    digitalWrite(shiftClockPin, LOW);
  }
  digitalWrite(latchClockPin, HIGH);
  digitalWrite(latchClockPin, LOW);
}

void letterB() //functions that will show you the character B
{
  displayData(b1);
  displayData(b2);
  displayData(b3);
  delay(1);
}

void letterA()
{
 displayData(a1);
 displayData(a2);
 displayData(a3);
 delay(1);
}

void letterR()
{
 displayData(r1);
 displayData(r2);
 displayData(r3);
 displayData(r4);
 delay(1);
}

void letterT()
{
 displayData(t1);
 displayData(t2);
 delay(1);
}

void ampersant()
{
 displayData(en1);
 displayData(en2);
 displayData(en3);
 displayData(en4);
 displayData(en5);
 delay(1);
}

void letterF()
{
 displayData(f1);
 displayData(f2);
 displayData(f3);
 delay(1);
}

void letterE()
{
 displayData(e1);
 displayData(e2);
 displayData(e3);
 delay(1);
}

void smiley()
{
 displayData(smiley1);
 displayData(smiley2);
 displayData(smiley3);
 displayData(smiley4);
 delay(1); 
}

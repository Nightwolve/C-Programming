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


boolean shiftLeftRight = false;

void setup() {
  //Instelen van de uitgangspinnen
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
}

void loop()
{

 displayData(bericht1);
 delay(1);
 displayData(bericht2);
 delay(1);
 displayData(bericht3);
 delay(1);
 displayData(bericht4);
 delay(1);

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

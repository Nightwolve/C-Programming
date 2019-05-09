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

word b1  = 0b1000000001000000;
word b2  = 0b1000110010010110;
word b3  = 0b1101001000100000;

word a1  = 0b1100000001000000;
word a2  = 0b1001110010110110;
word a3  = 0b1100000000000001;

word r1  = 0b1000000001000000;
word r2  = 0b1001110000010010;
word r3  = 0b1001010010010100;
word r4  = 0b1100001000100110;

word t1  = 0b1001111011110111;
word t2  = 0b1000000010000000;

word en1  = 0b1011001000000000;
word en2  = 0b0100010001010110;
word en3  = 0b0100111000000010;
word en4  = 0b1001001010010100;
word en5  = 0b1100011000110010;

word f1  = 0b1000000001000000;
word f2  = 0b1001110010010110;
word f3  = 0b1001011000110110;

word e1  = 0b1000000001000000;
word e2  = 0b1000110010010110;
word e3  = 0b1000011000110110;

word leeg  = 0b1101011000010110;


boolean shiftLeftRight = false;

void setup() {
  //Instelen van de uitgangspinnen
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
}

void loop()
{
for(int i=0; i<1000; i++)
{
 displayData(b1);
 displayData(b2);
 displayData(b3);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(a1);
 displayData(a2);
 displayData(a3);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(r1);
 displayData(r2);
 displayData(r3);
 displayData(r4);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(t1);
 displayData(t2);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(en1);
 displayData(en2);
 displayData(en3);
 displayData(en4);
 displayData(en5);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(f1);
 displayData(f2);
 displayData(f3);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(e1);
 displayData(e2);
 displayData(e3);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(r1);
 displayData(r2);
 displayData(r3);
 displayData(r4);
 delay(1);
}
for(int i=0; i<250; i++)
{
 displayData(leeg);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(r1);
 displayData(r2);
 displayData(r3);
 displayData(r4);
 delay(1);
}
for(int i=0; i<1000; i++)
{
 displayData(e1);
 displayData(e2);
 displayData(e3);
 delay(1);
}

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

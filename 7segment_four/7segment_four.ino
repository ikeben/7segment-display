#define DATA 6
#define LATCH 8
#define CLOCK 10
int dat[]={252,96,218,242,102,182,190,224,254,246,238,62,156,122,148,142}; //array numbers and letters in base10 for the register

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

}

void displaynumber(int n){
  int tens=0;
  int units=0;
  int hun=0;
  int tht=0;
   if(n<10){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[n]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    digitalWrite(LATCH, HIGH);
  }
  else if(n>=0 && n<=99){
    units=n%10;
    tens=n/10;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[units]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[tens]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    digitalWrite(LATCH, HIGH);
  }
  else if(n>=99 && n<=999){
    units=n%10;
    tens=(n/10)%10;
    hun=n/100;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[units]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[tens]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[hun]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[0]);
    digitalWrite(LATCH, HIGH);
  }
   else if(n>=100 && n<=9999){
    units=n%10; //units
    tens=(n/10)%10; //tens
    hun=(n/100)%10; //hundrends
    tht=n/1000;      //thousands
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[units]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[tens]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[hun]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[tht]);
    digitalWrite(LATCH, HIGH);
}
}


void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<1500; i++){ //code to count to 1500
    displaynumber(i);
    delay(60);
  }
}

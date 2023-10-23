#define DATA 6
#define LATCH 8
#define CLOCK 10
int dat[]={252,96,218,242,102,182,190,224,254,246,238,62,156,122,148,142};

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

}

void displaynumber(int n){
  //leds
  int leftmost=0; 
  int left=0;
  int right=0;
  int rightmost=0;
  if(n<10){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[n]);// runs through the array till 10
    shiftOut(DATA, CLOCK, LSBFIRST, 0); // push 0bit
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
  else if(n>=10 && n<100){// comndtion for 10-99
    leftmost=n%10; //modulo operation still counts 1-9
    left=n/10; //int operation on a float, it holds the number in the second LED (from the right) and increses only when the first LED counts to 9
    digitalWrite(LATCH, LOW); //open the latch
    shiftOut(DATA, CLOCK, LSBFIRST, dat[leftmost]); //send the data 
    shiftOut(DATA, CLOCK, LSBFIRST, dat[left]);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
   else if(n>=100 && n<1000){ //condtion for 100-999
    leftmost=(n%100)%10;
    left=(n%100)/10;
    right=n/100;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[leftmost]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[left]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[right]);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
   else if(n>=100 && n<10000){
    leftmost=((n%1000)%100)%10;
    left=((n%1000)%100)/10;
    right=(n%1000)/100;
    rightmost=n/10000;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[leftmost]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[left]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[right]);
    shiftOut(DATA, CLOCK, LSBFIRST, dat[rightmost]);
    digitalWrite(LATCH, HIGH);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<1000; i++){
    displaynumber(i);
    delay(30);
  }
}
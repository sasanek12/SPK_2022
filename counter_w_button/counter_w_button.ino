/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 Most Arduinos have an on-board LED you can control. On the Uno and
 Leonardo, it is attached to digital pin 13. If you're unsure what
 pin the on-board LED is connected to on your Arduino model, check
 the documentation at http://arduino.cc
 
 This example code is in the public domain.
 
 modified 8 May 2014
 by Scott Fitzgerald
 */
int LED1[3]= {
  7,6,2};
int LED2[5]= {
  8,7,2,4,5};                
int LED3[5]= {
  8,7,2,6,5};                
int LED4[4]= {
  7,6,2,3};                
int LED5[5]= {
  8,3,2,6,5};                
int LED6[5]= {
  6,5,4,3,2};                
int LED7[3]= {
  8,7,6};                
int LED8[7]= {
  8,7,6,5,4,3,2}; 
int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;
int counter = 0;
int direct = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // wybor cyfry
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  //wybor segmentu
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //przycisk
  pinMode(28,INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  int pressed = 0;
  for(int i=0; i< 9999; ){
    if(button() == 1 && pressed == 0){
      i++;
      pressed = 1;
    }
    if(button() == 0 && pressed == 1){
      pressed = 0;
    }
      intdisplay(i);
  }
}

int button(){
  int pressed = 0;
  for(int i=0; i < 100; i++){
    if(digitalRead(28) == 0){
      pressed++;
    }
  }
  if(pressed == 100){
    return 1;
  }
  else{
    return 0;
  }
}

void intdisplay(int input){
  int ones = input%10;
  int tens = (input/10)%10;
  int hundreds = (input/100)%10;
  int thousands = (input/1000);
  display(ones,1);
  delay(1);
  display(tens,2);
  delay(1);
  display(hundreds,3);  
  delay(1);
  display(thousands,4);  
  delay(1);
}



void one(){
  clean();
  digitalWrite(a, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void two(){
  clean();
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
}
void three(){
  clean();
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}
void four(){
  clean();
  digitalWrite(a, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}
void five(){
  clean();
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
}
void six(){
  clean();
  digitalWrite(b, HIGH);
}
void seven(){
  clean();
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void eight(){
  clean();
}
void nine(){
  clean();
  digitalWrite(e, HIGH);
}
void zero(){
  clean();
  digitalWrite(g, HIGH);
}



void clean(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void display(int i, int j){
  switch(j){
  case 1:
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(27,HIGH);
    break;
  case 2:
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(27,HIGH);
    break;
  case 3:
    digitalWrite(24,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(27,HIGH);
    break;
  case 4:
    digitalWrite(24,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(27,LOW);
    break;

  }
  switch(i){
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4:
    four();
    break;
  case 5:
    five();
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9:
    nine();
    break;
  case 0:
    zero();
    break;
  }
}




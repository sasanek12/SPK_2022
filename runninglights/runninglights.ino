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

  int counter = 0;
  int direct = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(24,INPUT_PULLUP);
  pinMode(25,INPUT_PULLUP);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(24) == LOW){
    direct = 1;
  }
  if(digitalRead(25) == LOW){
    direct = 0;
  }
  digitalWrite(counter, LOW);
  delay(200);
  digitalWrite(counter, HIGH);
  if(direct == 0){
    if(counter == 7){
      counter = 0; 
    }
    else{
    counter ++;
    }
  }
  if(direct == 1){
    if(counter == 0){
      counter = 7;
    }
    else{
    counter --;
    }
  }
}

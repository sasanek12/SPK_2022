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
long int k = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  DDRA = 255;
  PORTA = 0;
  TCNT0 = 0;
//  OCR0 = 80; 
  SREG = 128;
  TCCR0 = B00001010;
  TIMSK = B00000011;
}
    ISR(TIMER0_COMP_vect){
      TCNT0=0;
      k++;
      if(k > 10000){
          PORTA = ~PORTA;
          k=0;
      }
    }
    
void loop(){}
// the loop function runs over and over again forever


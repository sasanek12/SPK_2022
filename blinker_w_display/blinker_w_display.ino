#include <LiquidCrystal.h>

long int k = 0;
LiquidCrystal lcd(0,1,2,3,4,5);
// the setup function runs once when you press reset or power the board
void setup() {
//  pinMode(0,INPUT);
  TCNT0 = 0;
  //  OCR0 = 80; 
  SREG = 128;
  TCCR0 = B00001010;
  TIMSK = B00000011;
  lcd.begin(16,2);
  Serial.begin(9600);
}
ISR(TIMER0_COMP_vect){
  k++;
  if(k > 2000){
    TCNT0=0;
    float voltage = (analogRead(0) * (5.0 / 1023.0));
    Serial.println(voltage);
    lcd.clear();
    lcd.print(voltage);
    lcd.setCursor(4,0);
    lcd.print("V");
    k=0;
  }
}

void loop(){
}
// the loop function runs over and over again forever



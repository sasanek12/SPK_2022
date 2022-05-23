#include <LiquidCrystal.h>

long int k = 0;
long int pomiar = 0;
long int proba = 0;
LiquidCrystal lcd(0,1,2,3,4,5);
// the setup function runs once when you press reset or power the board
void setup() {
//  pinMode(0,INPUT);
  TCNT1H = B11111111;
  TCNT1L = B00111000;
  DDRC =   B11111111;
  //  OCR0 = 80; 
  TCCR1A = 0;
  TCCR1B = B00000010; 
  
  TIMSK = B00100100; //TICIE1, OCIE1B i TOIE1 włączone
  
  SREG = SREG|128;
  lcd.begin(16,2);
  Serial.begin(9600);
}
ISR(TIMER1_OVF_vect){
  TCNT1H = B11111111; //65336
  TCNT1L = B00111000;
  k++;
  if(k > 5000){
    PORTC = ~PORTC;
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



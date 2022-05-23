#include <LiquidCrystal.h>

long int k = 0;
long int proba = 1;
double odleglosc = 0;
int trig = 24;
int echo = 25;
int button = 23;
LiquidCrystal lcd(0,1,2,3,4,5);

void setup() {

  DDRC = 0;
  PORTC = B11111111;

  TCNT1H = 255;
  TCNT1L = 198;
  pinMode(button,INPUT_PULLUP);
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT_PULLUP);
  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK = B00100100; //TICIE1, OCIE1B i TOIE1 włączone

  SREG = SREG|128;
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Start");
  delay(200);
}
ISR(TIMER1_OVF_vect){
  k++;
  TCNT1H = 255;
  TCNT1L = 198;
}

void loop(){
  if(digitalRead(button) == 0){
//    int pressed = 1;
    TCNT1H = 255;
    TCNT1L = 198;

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW); 

    while(digitalRead(echo)== 0){
    }
    TCCR1B = 1;

    while(digitalRead(echo)== 1){
    }
    TCCR1B = 0;
    while(digitalRead(button) == 0){
      delay(10);
    }

    if(k < 2941){
      odleglosc = k*0.0034*0.5;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(proba);
      lcd.setCursor(0, 1);
      lcd.print(odleglosc);
      lcd.print('m');
      Serial.println(odleglosc);
      k=0;
      //    pomiar = 0;
      proba++;
      delay(200);
    }
    else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(proba);
      lcd.setCursor(0, 1);
      lcd.print("Awaria");
      Serial.println("Awaria");
      k=0;
      proba++;
      delay(200);
    }
  }
}
// the loop function runs over and over again forever






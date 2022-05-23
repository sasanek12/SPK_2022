int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;
int counter = 0;
int direct = 0;
int set_microwave_pin = 28;
int start_microwave_pin = 29;
int stop_microwave_pin = 30;
int microwave_status = 0;
int microwave_time = 0;
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
  pinMode(29,INPUT_PULLUP);
  pinMode(30,INPUT_PULLUP);

}

// the loop function runs over and over again forever
void loop() {
  switch(microwave_status){
    case 0:
      set_time();
      run_microwave();
      intdisplay(microwave_time);
      break;
     case 1:
     int stop_status = 0;
       for(int i= 0; i < 230; i++){
         if(stop_microwave() == 1){
           stop_status = 1;
           microwave_time = 0;
           break;  
         }
           intdisplay(microwave_time);
       }
       if(stop_status == 1){
         break;
       }
       microwave_time--;
       if(microwave_time == 0){
         microwave_status = 0;
       }
       break;
  }
}

void set_time(){
  int pressed = 0;
    if(button(1) == 1 && pressed == 0){
      microwave_time = 150;
      pressed = 1;
    }
    if(button(1) == 0 && pressed == 1){
      pressed = 0;
    }
}

void run_microwave(){
   int pressed = 0;
     if(button(2) == 1 && pressed == 0){
      microwave_status = 1;
      pressed = 1;
    }
    if(button(2) == 0 && pressed == 1){
      pressed = 0;
    }
}

int stop_microwave(){
     if(button(3) == 1){
      microwave_status = 0;
      return 1;
     }
     else{
       return 0;
     }
}

int button(int number){
 int button_type = 0;
  switch(number){
    case 1:
      button_type = set_microwave_pin;
      break;
    case 2:
      button_type = start_microwave_pin;
      break;
    case 3:
      button_type = stop_microwave_pin;
      break;
    
  }
  int pressed = 0;
  for(int i=0; i < 100; i++){
    if(digitalRead(button_type) == 0){
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
    int minutes = input/60;
    int seconds = input % 60;

  int ones = seconds%10;
  int tens = (seconds/10)%10;
  int hundreds = minutes%10;
  int thousands = (minutes/10)%10;

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





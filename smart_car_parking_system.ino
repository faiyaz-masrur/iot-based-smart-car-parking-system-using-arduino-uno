  #include <Wire.h> 
  #include <NewPing.h>
  #include <LiquidCrystal_I2C.h>
  #include <Servo.h> 

  LiquidCrystal_I2C lcd(0x27,16,2);

  #define TRIG_PIN1 9
  #define ECHO_PIN1 8
  #define TRIG_PIN2 7
  #define ECHO_PIN2 6
  #define TRIG_PIN3 5
  #define ECHO_PIN3 4

  #define MAX_DISTANCE 10
  NewPing sonar1(TRIG_PIN1, ECHO_PIN1, MAX_DISTANCE);
  NewPing sonar2(TRIG_PIN2, ECHO_PIN2, MAX_DISTANCE);
  NewPing sonar3(TRIG_PIN3, ECHO_PIN3, MAX_DISTANCE);

  Servo myservo1;

  int IR1 = 11;
  int IR2 = 12;

  int Slot = 3;           //Enter Total number of parking Slots

  int flag1 = 0;
  int flag2 = 0;

  int s1 = 0, s2 = 0, s3 = 0;

  void setup() {
  lcd.init(); 
  lcd.backlight();
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
    
  myservo1.attach(2);
  myservo1.write(100);

  lcd.setCursor (0,0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor (0,1);
  lcd.print(" PARKING SYSTEM ");
  delay (2000);
  lcd.clear();  
  }

  void loop(){ 

  if(digitalRead(IR1)==LOW && flag1==0){
  if(Slot>0){flag1=1;
  if(flag2==0){myservo1.write(0); Slot = Slot-1;}
  }else{
  lcd.setCursor (0,0);
  lcd.print("    SORRY 🙁    ");  
  lcd.setCursor (0,1);
  lcd.print("  Parking Full  "); 
  delay (3000);
  lcd.clear(); 
  }
  }

  if(digitalRead(IR2)==LOW && flag2==0){
    flag2=1;
  if(flag1==0){myservo1.write(0); Slot = Slot+1;}
  }

  if(flag1==1 && flag2==1){
  delay (1000);
  myservo1.write(100);
  flag1=0, flag2=0;
  }

  if(sonar1.ping_cm()>0){
      s1 = 1;
    }
    else{
      s1 = 0;
    }
  if(sonar2.ping_cm()>0){
      s2 = 1;
    }
    else{
      s2 = 0;
    }
  if(sonar3.ping_cm()>0){
      s3 = 1;
    }
    else{
      s3 = 0;
    }


  lcd.setCursor (0,0);
  lcd.print("HI! Slot Left: ");
  lcd.print(Slot);
  lcd.setCursor (0,1);
  if(s1 == 0){
    lcd.print("S1=E, ");
  }
  else{
    lcd.print("S1=F, ");
  }
  lcd.setCursor (6,1);
  if(s2 == 0){
    lcd.print("S2=E, ");
  }
  else{
    lcd.print("S2=F, ");
  }
  lcd.setCursor (12,1);
  if(s3 == 0){
    lcd.print("S3=E");
  }
  else{
    lcd.print("S3=F");
  }

  }
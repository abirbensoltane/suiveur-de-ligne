#include <SoftwareSerial.h>// bib pour l'affichage en moniteur serie 
//pin arduino relié au pins du pont H

int ENA =10;
int ENB = 11;
int IN4 = 5;
int IN3 = 4;
int IN2 = 3;
int IN1 = 2;
//pin arduino relié au capteurs
int RT = 7;
int LT = 8;
int hrt=6;
int hlt=9;
//les valeurs des capteurs 
int val1,val2,val11,val22;

void setup() {
  Serial.begin(9600);// moniteur serie fonctionne en frequence 9600
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(RT, INPUT);
  pinMode(LT, INPUT);
  pinMode(hrt, INPUT);
  pinMode(hlt, INPUT);
  analogWrite(ENA,100);
  analogWrite(ENB,100);
 
  //Define inputs and outputs

}

void loop() {
  
   val1 = digitalRead(RT); 
   val2 = digitalRead(LT); 
   val11 = digitalRead(hrt); 
   val22 = digitalRead(hlt); 
  
  //Serial.print(val1);//affichage valeur du capteur à droite
  // Serial.println(val2); //affichage valeur du capteur à gauche 
    //Serial.print(val11);//affichage valeur du capteur  hard right
  // Serial.println(val22); //affichage valeur du capteur hard left

  
   if((val1==0 && val2==1 && val11==1 && val22==1)||(val1==1 && val2==0 && val11==1 && val22==1))
      Fwd(); 
    if(((val22==0)&&(val2==1)&& val11==1 )|| ( val22==1 && val2==1 && val11==1 && val1==1 ))
      Left();
    if((val1==0 &&  val11==0 && val22==1)||( val22==1 && val2==0 && val11==1 && val1==0))
      Right();


  
}
void Fwd(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

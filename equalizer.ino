#define datapin 3
#define latchpin 4
#define shiftpin 5
#define soundin A0
#define invalue analogRead(soundin)
#include <FrequencyTimer2.h>
boolean pin[16] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(datapin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(shiftpin,OUTPUT); 
  pinMode(soundin,INPUT);
 
FrequencyTimer2::disable();
FrequencyTimer2::setPeriod(2000);
FrequencyTimer2::setOnOverflow(writepins);
}

int temp =18;
void loop() {
  // put your main code here, to run repeatedly:

Serial.println(analogRead(A0));
delay(5);
valuetest();

}

void valuetest(){
 

 if(invalue<=520+temp && invalue>514+temp){
  clearpin();
}else if((invalue>520+temp && invalue<=523+temp) || (invalue>511+temp && invalue<=514+temp)){
  clearpin();
  setpin(1);
}else if((invalue>523+temp && invalue<=526+temp) || (invalue>508+temp && invalue<=511+temp)){
  clearpin();
  setpin(2);
}else if((invalue>526+temp && invalue<=529+temp) || (invalue>505+temp && invalue<=508+temp)){
  clearpin();
  setpin(3);
}else if((invalue>529+temp && invalue<=532+temp) || (invalue>502+temp && invalue<=505+temp)){
  clearpin();
  setpin(4);
}else if((invalue>532+temp && invalue<=535+temp) || (invalue>499+temp && invalue<=502+temp)){
  clearpin();
  setpin(5);
}else if((invalue>535+temp && invalue<=538+temp) || (invalue>496+temp && invalue<=499+temp)){
  clearpin();
  setpin(6);
}else if((invalue>538+temp && invalue<=541+temp) || (invalue>493+temp && invalue<=496+temp)){
  clearpin();
  setpin(7);
}else if((invalue>541+temp && invalue<=544+temp) || (invalue>490+temp && invalue<=493+temp)){
  clearpin();
  setpin(8);
}else if((invalue>544+temp && invalue<=547+temp) || (invalue>487+temp && invalue<=490+temp)){
  clearpin();
  setpin(9);
}else if((invalue>547+temp && invalue<=550+temp) || (invalue>484+temp && invalue<=487+temp)){
  clearpin();
  setpin(10);
}else if((invalue>550+temp && invalue<=553+temp) || (invalue>481+temp && invalue<=484+temp)){
  clearpin();
  setpin(11);
}else if((invalue>553+temp && invalue<=556+temp) || (invalue>478+temp && invalue<=481+temp)){
  clearpin();
  setpin(12);
}else if((invalue>556+temp && invalue<=559+temp) || (invalue>475+temp && invalue<=478+temp)){
  clearpin();
  setpin(13);
}else if((invalue>559+temp && invalue<=562+temp) || (invalue>472+temp && invalue<=475+temp)){
  clearpin();
  setpin(14);
}else if((invalue>562+temp && invalue<=565+temp) || (invalue>469+temp && invalue<=472+temp)){
  clearpin();
  setpin(15);
}else if(invalue>565+temp || invalue<=469+temp){
  clearpin();
  setpin(16);
}

}

void writepins(){

  digitalWrite(latchpin,LOW);

  for(int i=0; i<16; i++){
  digitalWrite(shiftpin,LOW);
  digitalWrite(datapin,pin[i]);
  digitalWrite(shiftpin,HIGH);

  }
  digitalWrite(latchpin,HIGH);

}
void clearpin(){
  for(int i=0; i<16; i++){
    pin[i]=0;
  }
}
void setpin(int k){
  for(int j=0;j<k;j++){
    pin[j]=1;
  }

}
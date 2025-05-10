const int led1=3;
const int led2=5;
const int soundpin=A2;
const int threshold =200;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(soundpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int soundsense = analogRead(soundpin);
  if(soundsense>= 400 ){
    digitalWrite(led1,HIGH );
   // digitalWrite(led2,HIGH );
delay(100); 
//digitalWrite(led1,LOW );
}
else{
  digitalWrite(led1,LOW );//digitalWrite(led2,LOW);
 }
}

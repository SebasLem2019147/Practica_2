/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 07/16/2024
   
*/

#include <Wire.h>                  
#include <SparkFun_ADXL345.h>       
#include <SoftwareSerial.h>        
#include <DFRobotDFPlayerMini.h>  

ADXL345 accSebasLem = ADXL345();

SoftwareSerial mp3SebasLem(A0, A1); 

DFRobotDFPlayerMini reproductor_MP3;

unsigned int acc_X;         
unsigned int acc_Y;         
unsigned int acc_Z;       

float magnitud_acc;

const int PinSegmentos[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int NumSegmentos = 10;

void setup() {
  Serial.begin(9600);            
  mp3SebasLem.begin(9600);        
  accSebasLem.powerOn();           
  accSebasLem.setRangeSetting(16); 

  for (int i = 0; i < NumSegmentos; i++){
    pinMode(PinSegmentos[i], OUTPUT);
  }

  if(!reproductor_MP3.begin(mp3SebasLem))
  { 
    Serial.println("No he podido comunicarme con el modulo MP3");

    while (1);
  }
  reproductor_MP3.volume(10);      
  delay(100);
}

void loop() {
  for (int i = 0; i < NumSegmentos; i++) {
    digitalWrite(PinSegmentos[i], LOW);
  }
  
  accSebasLem.readAccel(&acc_X,&acc_Y,&acc_Z);
  Serial.print("Aceleracion en X: ");
  Serial.println(acc_X);
  Serial.print("Aceleracion en Y: ");
  Serial.println(acc_Y);
  Serial.print("Aceleracion en Z: ");
  Serial.println(acc_Z);
  
  magnitud_acc = sqrtf((acc_X*acc_X)+(acc_Y*acc_Y)+(acc_Z*acc_Z));
  
  Serial.print("La magnitud del vector aceleracion es de: ");
  Serial.println(magnitud_acc);
  
  int mapeo_intensidad = map(magnitud_acc,47, 75, 0, 10);

  
  Serial.print("El valor mapeo es de: ");
  Serial.println(mapeo_intensidad);

  if(mapeo_intensidad <= 1)
  {
    digitalWrite(2 , HIGH);
  }
  else if (mapeo_intensidad>=1 && mapeo_intensidad<2){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
    }
  }
  else if (mapeo_intensidad>=2 && mapeo_intensidad<3){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=3 && mapeo_intensidad<4){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=4 && mapeo_intensidad<5){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=5 && mapeo_intensidad<6){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=6 && mapeo_intensidad<7){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=7 && mapeo_intensidad<8){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else if (mapeo_intensidad>=8 && mapeo_intensidad<9){
    for (int i = 0; i <= 1; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  else (mapeo_intensidad<9){
    for (int i = 0; i <= 10; i++) {
      digitalWrite(PinSegmentos[i], HIGH); 
  }
  delay(1000);
}

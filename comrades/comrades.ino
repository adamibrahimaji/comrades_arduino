//#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

//SoftwareSerial BlueSer(8, 9); // RX, TX
File fileTime; 
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Ahad", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};

int led=13;
char BluetoothData;
String data;
 
void setup() {
  Serial.begin(9600);
  //BlueSer.begin(9600);
  
 // BlueSer.println("Helo World");
  pinMode(led,OUTPUT);

  Serial.println("Membuka Micro SD . . .");
  delay(1000);
  if (!SD.begin(4)){
    Serial.println("Gagal Membuka Micro SD!");
    return;
  }
  Serial.println("Berhasil Membuka Micro SD");
  delay(1000);

  Serial.println("Memerikasa Koneksi RTC . . .");
  delay(1000);
  if (! rtc.begin()){
    Serial.println("RTC tidak ditemukan");
    return;
  }
  Serial.println("Koneksi RTC Berhasil");
  delay(1000);
}
 
void loop() {
//  if (BlueSer.available() > 0){
//    BluetoothData=BlueSer.read();
//    data += BluetoothData;
//    Serial.println(data);

  if (Serial.available() > 0){
    BluetoothData = Serial.read();
      
    if (BluetoothData != '\n'){ 
      data += BluetoothData; 
    } else {
      Serial.print("Data : ");
      Serial.println(data);
      data = ""; 
    }        
    
  fileTime = SD.open("alarm.txt", FILE_WRITE); //Membuka File test.txt
  
  if (fileTime){
    fileTime.println(data); 
  }  
}
  
}

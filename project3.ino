
 
#include <Servo.h>;                                               // Menyertakan library servo pada program arduino
Servo myservo;                                                    // Variabel dengan nama myservo
int pos = 0;                                                      // Variabel untuk menyimpan posisi servo saat kondisi default
int buzzer = 13;                                                  // Variabel Buzzer, pin 13
int pinPIRleft = 4;                                               // Variabel PIR kiri, pin 4
int pinLEDleft = 8;                                               // Variabel LED Kiri, pin 8
int pinPIRright = 2;                                              // Variabel PIR kanan, pin 2
int pinLEDright = 10;                                             // Variabel LED kanan, pin 10
 
void setup() {
  pinMode(pinLEDleft, OUTPUT);                                    // Atur LED sebagai Output
  pinMode(pinLEDright, OUTPUT);
  pinMode(pinPIRleft, INPUT);                                     // Atur Sensor sebagai Input
  pinMode(pinPIRright, INPUT);
  pinMode(buzzer, OUTPUT);                                        // Atur Buzzer sebagai Output
  myservo.attach(9);                                              // Atur Servo di pin 9
}
 
void loop() {
 
  if (digitalRead(pinPIRleft) == LOW) {                           // Jika Sensor PIR Kiri tidak mendeteksi suatu pergerakan
    digitalWrite(pinLEDleft, LOW);                                // LED kiri tidak nyala
    digitalWrite(buzzer,LOW);                                     // Buzzer tidak bunyi
    if ((pos < 90) && (digitalRead(pinPIRright) == HIGH)) {       // jika kedua kondisi ini terpenuhi (posisi kurang dari 90 derajat dan PIR kanan statusnya aktif) maka akan menjalankan fungsi dibawah;
      pos += 1;                                                   // pos =pos+1 = True (benar) , selanjutnya;
      myservo.write(pos);                                         // servo tidak akan bergerak, dan akan tetap pada posisi 90 derajat 
      delay(9);
    }
  } else {                                                        // Jika tidak menjalankan kondisi If diatas, maka servo akan bergerak 90 derajat, di ikti oleh; 
    digitalWrite(pinLEDleft, HIGH);                               // LED kiri nyala
    digitalWrite(buzzer,HIGH);                                    // Buzzer bunyi
  }
 
  if (digitalRead(pinPIRright) == LOW) {
    digitalWrite(pinLEDright, LOW);
    if ((pos >= 1) && (digitalRead(pinPIRleft) == HIGH)) {
      pos -= 1;
      myservo.write(pos);
      delay(25);
    }
  } else {
    digitalWrite(pinLEDright, HIGH);
  }
 
  if ((digitalRead(pinPIRleft) == HIGH) && (digitalRead(pinPIRright) == HIGH)) {          // Jika kedua kondisi bernilai true maka servo akan tiba-tiba berhenti 
  }
}

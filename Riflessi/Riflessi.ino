#include <LiquidCrystal.h>
int LED = 13, pulsante = 12, buzzer = 11, d = 800, tempo=0, stampa=0;
const int pin1 = 2, pin2 = 3, pin3 = 4, pin4 = 5, pin5 = 6, pin6 = 7;
LiquidCrystal lcd(pin1, pin2, pin3, pin4, pin5, pin6);

void setup() {
  // put your setup code here, to run once
  pinMode(LED, OUTPUT);
  pinMode(pulsante, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
 delay(d);
 digitalWrite(LED, HIGH);
 while (digitalRead(pulsante) == LOW);
 digitalWrite(LED, LOW);
 while (digitalRead(pulsante) == HIGH);
 delay(d);
 tone(buzzer, 1000, 5000);
  tempo=millis();
 while (digitalRead(pulsante) == LOW);
 noTone(buzzer);
  stampa=millis()-tempo;
 lcd.setCursor(0,0);
 lcd.print(stampa);
 while (digitalRead(pulsante) == HIGH);
}
//premere la prima volta il pulsante per far partire la prova, al suono ripremere il pulsante per misurare i riflessi.

#include <LiquidCrystal.h>
#include "dht.h" 
#include <SoftwareSerial.h>

const int pinoDHT11 = A2; 
dht DHT;
char resposta;

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600); 
  SoftwareSerial bluetooth(11, 10);  
}

void loop() {
  DHT.read11(pinoDHT11); 
  resposta = Serial.read(); 

  if (resposta == 'U'){
    lcd.setCursor(0,0);
    lcd.print("Umidade:          ");
    lcd.setCursor(10,0);
    lcd.print(DHT.humidity);
    delay(200);
  }
  if (resposta == 'U'){

    lcd.setCursor(0,0);
    lcd.print("Temperatura:      ");
    lcd.setCursor(13,0);
    lcd.print(DHT.temperature, 0);
    
  }
}

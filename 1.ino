#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer = 4;
int smokeA0 = A1;
int INA = 10;
int sensorThres = 300;

void setup() {
 lcd.clear();
 lcd.init();
 lcd.backlight();
  pinMode(INA, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(smokeA0, INPUT);

}

void loop() {
  int analogSensor = analogRead(smokeA0);
  lcd.setCursor(0, 0);
  lcd.print("ASAP : ");
  Serial.println(analogSensor);
  lcd.setCursor(0,0);
  lcd.print("Kadar Asap = ");
  lcd.setCursor(12,0);
  lcd.print(analogSensor);

  if
  (analogSensor >=sensorThres)

  {
    
    digitalWrite(INA, HIGH);
    tone(buzzer, 1000, 6000);
    lcd.setCursor(0,1);
    lcd.print("Bahaya");
    delay(500);
    lcd.setCursor(6,1);
    lcd.print("Asap");
    delay(500);
    lcd.setCursor(11,1);
    lcd.print("Rokok");
    delay(500);
  }
else
{
    digitalWrite(INA, LOW);
    noTone(buzzer);
    lcd.setCursor(0,1);
    lcd.print("Udara");
    delay(500);
    lcd.setCursor(6,1);
    lcd.print("Ruang");
    delay(500);
    lcd.setCursor(12,1);
    lcd.print("Aman");
    delay(500);
  }
  delay(100);
  lcd.clear();
}

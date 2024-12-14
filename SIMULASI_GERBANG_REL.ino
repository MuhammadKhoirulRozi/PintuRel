#include <Servo.h> // Menyertakan library Servo
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define  LED_1 1
#define  LED_2 2
#define  LED_3 3
// cons int LED_PIN - 9;
#define I2C_SDA A4
#define I2C_SCL A5


Servo myservo; // Membuat objek servo
int pos = 0;   // Variabel untuk menyimpan posisi servo

//inisialisasi liquid crystal I2C
 LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Serial.begin(115200);

    myservo.attach(9); // Menghubungkan servo ke pin digital 9

      lcd.begin(16, 2); // Ukuran LCD 20x4
  lcd.backlight(); // Aktifkan backlight LCD

  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  {
  digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
        lcd.init();
          lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PINTU TERBUKA");
      {
            for (pos = 0; pos <=90; pos += 1);
    myservo.write(pos); // Mengatur posisi servo 
    delay (15);
}
  delay(2500);
}

  digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, LOW);
  delay(500);


    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, HIGH);
          lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("PINTU TERTUTUP");
      {
      for (pos = 90; pos >=0; pos -= 1);
    myservo.write(pos); // Mengatur posisi servo
  delay(3000);
      }

  // digitalWrite(LED_3, HIGH); // Menyalakan LED
  // myservo.write(90); // Menggerakkan servo ke posisi 90 derajat
  // // delay(2000); // Menunggu selama 2 detik
  
  // digitalWrite(LED_3, LOW); // Mematikan LED
  // myservo.write(0); // Mengembalikan servo ke posisi 0 derajat
  // // delay(2000); // Menunggu selama 2 detik


  //   digitalWrite(LED_1, LOW);
  //   digitalWrite(LED_2, LOW);
  //     digitalWrite(LED_3, LOW);
  // delay(500);
}

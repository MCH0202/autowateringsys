#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//PIN setting
int percentage;
int AM = A3;
int relayPin = 8;
int RainSen = A0;

//parameter setting
int soilMoisture;
int rain;
int rainThreshold = 10;

//lcd setting
LiquidCrystal_I2C lcd(0x27, 20, 4);

//setup code
void setup() {
  // PinMode setting
  pinMode(RainSen, INPUT);
  pinMode(AM, INPUT);
  pinMode(relayPin, OUTPUT);

  //Monitor baud setting
  Serial.begin(9600);

  //relay default status setting
  digitalWrite(relayPin, HIGH);

  //lcd default
  lcd.init(); // Initialising the LCD
  lcd.backlight();  // Turn on backlight

}

//main loop function
void loop() {
  delay(5000);
  Serial.println("---------------------");
  Rainfall(); // detect rainfall

  lcd.setCursor(0, 3);  //select lcd row 4
  lcd.print("                    "); // clear content of row 4
  delay(500);

  if (rain < rainThreshold) {
    // now is not raining
    Serial.println("not raining");
    lcd.print("NO rain right now");  // display the rain situation
    delay(2000);
    soilmoisture();  // detect soilmoisture
  } else {
    // it is raining now
    Serial.println("raining, stop auto irrigation sys for 1hr");
    lcd.print("Raining now"); // display rainfall
    delay(2000);
  }
  Serial.println("System paused for 1 hour...");
  lcd.clear();      //clear all content of lcd
  lcd.setCursor(0, 2);  // select lcd row 3
  lcd.print("Paused for 1 hour");
  delay(3600000); // let sys paused for an hour
}

void soilmoisture() {
  soilMoisture = analogRead(AM);
  int percentage = map(soilMoisture, 1023, 0, 0, 100); // transform analog result to percentage
  Serial.print("Moisture is :");
  Serial.print(soilMoisture );
  Serial.print(percentage);
  Serial.println("%");

  lcd.setCursor(0, 1); // select lcd row 2
  lcd.print("                    "); // clear the content
  delay(500);
  lcd.print("Moisture:");
  lcd.print(percentage);
  lcd.print("%"); 

  if (soilMoisture > 500) {
    // soil is dry, watering on
    lcd.setCursor(0, 2); // select lcd row 3
    delay(1000);
    lcd.print("pump on");
    delay(2000);
    digitalWrite(relayPin, LOW); // activate relay, turn on pump
    Serial.println("pump on");


    delay(5000); // pump working time
    digitalWrite(relayPin, HIGH); // turn on pump
    Serial.println("pump off");
    delay(2000);
    lcd.setCursor(0, 2); // select lcd row 3
    lcd.print("                    "); // clear content for row 3
    delay(1000);
    lcd.print("pump off");
  }else{
    // soil is sufficiently moist, no watering needed
    lcd.setCursor(0, 2); // select lcd row 3
    lcd.print("                    "); // clear the content
    delay(1000);
    lcd.print("No need to water");  // display no watering needed
    Serial.println("No need to water");
  }
  delay(5000);
}
// Function for detecting rainfall
void Rainfall() {
  rain = map(analogRead(A0), 0, 1023, 235, 0);
  Serial.print("Rainfall is ");
  Serial.println(rain);
}

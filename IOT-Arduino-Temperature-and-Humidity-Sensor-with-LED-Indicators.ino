#include <DHT.h>

DHT dht(2, DHT22);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();

  if (suhu<30){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
  if (suhu>=30){
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
  }
  if (suhu>50){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  }

  Serial.print("kelembaban: ");
  Serial.println(kelembaban);
  Serial.print("suhu: ");
  Serial.println(suhu);
  delay(1000);

}

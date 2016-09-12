#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600);
	Serial.println("Test del sensor de temperatura y humedad DHT11");

	dht.begin();
}

void loop() {

	delay(2000);

	float t = dht.readTemperature();
	float h = dht.readHumidity();

	if (isnan(h) || isnan(t)) {
		Serial.println("Falló la lectura del sensor!");
		return;
	}

	Serial.print("Temperatura Ambiente: ");
	Serial.print(t);
	Serial.println(" *C.");
	Serial.print("Humedad Relativa: ");
	Serial.print(h);
	Serial.println(" %.\n");
}
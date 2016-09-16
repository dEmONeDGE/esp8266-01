#include "RestClient.h"
#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//io.adafruit.com = 52.70.203.194
RestClient client = RestClient("io.adafruit.com", 80);
String grupo = "ambienteCuarto";
String feed1 = "temperatura";
String feed2 = "humedad";

char ssid[] = "Taller.Block";
char password[] = "2001057525287885Umss"; 
//Setup
void setup() {
	Serial.begin(9600);
	dht.begin();
	Serial.println("Conectando a la red local");
	client.begin(ssid, password);
	Serial.println("Listo!");
}

String response;
String pathS;

char path[70];

void loop(){

	float t = dht.readTemperature();
	float h = dht.readHumidity();	
	
	int val1 = int(t);
	int val2 = int(h);

	response = "";
	pathS = "/api/groups/"+grupo+"/send.json?"+feed1+"="+String(val1)+"&"+feed2+"="+String(val2);
	pathS.toCharArray(path, 70);
	client.setHeader("x-aio-key: 4a517959191b470d8d4e71a484fc1a17");	
	client.post(path, "POSDATA", &response);
	
	Serial.print("Temperatura: ");
	Serial.println(val1);
	Serial.print("Humedad: ");
	Serial.println(val2);
	delay(600000L);
}

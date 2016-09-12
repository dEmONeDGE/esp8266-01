#include "RestClient.h"

RestClient client = RestClient("www.dweet.io");
String nombreCosa = "iotUMSS";
int val1, val2;

char ssid[] = "tu red wifi";
char password[] = "tu password"; 
//Setup
void setup() {
	Serial.begin(115200);
	Serial.println("Conectando a la red local");
	client.begin(ssid, password);
	Serial.println("Listo!");
}

String response;
String pet;
char request[50];
void loop(){
	val1 = random(1, 100);
	val2 = random(1, 100);
	response = "";
	pet = "/dweet/for/"+nombreCosa+"?val1="+String(val1)+"&val2="+String(val2);
	pet.toCharArray(request, 50);
	
	int statusCode = client.get(request, &response);
	Serial.print("Codigo de cabecera: ");
	Serial.println(statusCode);
	Serial.print("Respuesta del servidor: ");
	Serial.println(response);
	delay(5000);
}

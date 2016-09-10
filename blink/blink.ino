#define led 2		//Led conectado al GPIO2 del esp8266-01

void setup(){
	pinMode(led, OUTPUT);
}

void loop(){
	digitalWrite(led, HIGH);
	delay(1000);
	digitalWrite(led, LOW);
	delay(1000);
}
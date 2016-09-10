
#define boton 2
#define led 0

boolean estadoLed = false;

void setup() {
	Serial.begin(115200);
	pinMode(boton, INPUT);
	pinMode(led, OUTPUT);
}

void loop() {
	if(!digitalRead(boton)){
		delay(200);
		if(estadoLed){
			digitalWrite(led, LOW);
			estadoLed = false;
			Serial.println("Led apagado...");
		}
		else{
			digitalWrite(led, HIGH);
			estadoLed = true;
			Serial.println("Led encendido...");
		}
	}
}
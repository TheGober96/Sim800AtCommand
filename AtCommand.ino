#define rxESP 26
#define txESP 27
#define relayGPRS 25
#define dtrGPRS 0

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, rxESP, txESP);
  Serial.setTimeout(200);
  Serial1.setTimeout(200);
  pinMode(dtrGPRS, OUTPUT);//LOW => WAKE UP ;HIGH => SLEEP
  pinMode(relayGPRS, OUTPUT);//HIGH => RESET ;LOW => NO RESET
  digitalWrite(dtrGPRS, LOW);
  digitalWrite(relayGPRS, HIGH);
  delay(1000);
  digitalWrite(relayGPRS, LOW);
  //profileGPRS(imeiGateway);
  Serial.println("Test Init");
}

void loop() {
  if(Serial.available()){
    /*while(Serial.available()){
      Serial1.write(Serial.read());
    }*/
    Serial1.print(Serial.readString());
  }
  if(Serial1.available()){
    /*while(Serial1.available()){
      Serial.write(Serial1.read());
    }*/
    Serial.print(Serial1.readString());
  }
}

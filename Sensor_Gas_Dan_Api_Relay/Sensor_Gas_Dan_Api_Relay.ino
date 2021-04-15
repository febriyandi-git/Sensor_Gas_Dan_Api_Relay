int Sensor_Gas = 34;
int Sensor_Api = 35;
int relay      = 22;
int relay2     = 23;
int LED_Hijau  = 19;
int LED_Red    = 18;
int t= 5000;

void setup() {
  pinMode(Sensor_Gas, INPUT);
  pinMode(Sensor_Api, INPUT);
  digitalWrite(relay,HIGH); 
  digitalWrite(relay2,HIGH);
  pinMode(relay, OUTPUT);  
  pinMode(relay2, OUTPUT);
  pinMode(LED_Red, OUTPUT);  
  pinMode(LED_Hijau, OUTPUT);
   Serial.begin(115200);
}
void loop() {
  //pembacaan sensor sebagai inpuanalog
  int sensor_gas = analogRead(Sensor_Gas);
  Serial.print("Sensor Gas:- ");
  Serial.println(sensor_gas);
  delay(1000);
  
  if (sensor_gas > 2890){
    Serial.println("Ada Gas Beracun");
    digitalWrite(LED_Hijau, LOW);
    digitalWrite(LED_Red, HIGH);
    digitalWrite(relay, HIGH);
    delay(t);
  }
  else{
  Serial.println("Ruangan AMAN!!!");
    digitalWrite(LED_Hijau, LOW);
    digitalWrite(LED_Red, HIGH);
    digitalWrite(relay, LOW);
  }
  
  //Sensor Api
   int sensor_api = digitalRead(Sensor_Api);
  Serial.print("Fire Class: ");
  Serial.print(sensor_api);
  Serial.print("\t");
  Serial.print("\t");
  if (sensor_api < 1) {
    Serial.println("Fire");
    digitalWrite(LED_Hijau, LOW);
    digitalWrite(LED_Red, HIGH);
    digitalWrite(relay2, HIGH);
    delay(t);
  }
  else {
    Serial.println("No Fire");
    digitalWrite(LED_Hijau, LOW);
    digitalWrite(LED_Red, HIGH);
    digitalWrite(relay2, LOW);
  }
}

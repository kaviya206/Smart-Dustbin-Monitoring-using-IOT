// Source code along with Blynk intergration 

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


#define TRIGGER_PIN 16
#define ECHO_PIN 17

// LED Pins
#define RED_LED 2       // Red LED = Bin Full
#define GREEN_LED 4     // Green LED = Bin Empty


char ssid[] = "Wokwi-GUEST";  
char pass[] = "";             
char auth[] = BLYNK_AUTH_TOKEN;

bool binWasFull = false;

void setup() {
  Serial.begin(115200);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  long distance = measureDistance();  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  int fullThreshold = 15;  // Bin is full when trash is close to sensor (<15cm)

  if (distance < fullThreshold) {
    // Bin is full
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    Blynk.virtualWrite(V0, "Bin Full");

    if (!binWasFull) {
      Blynk.logEvent("bin_alert", " Bin is Full! ");
      binWasFull = true;
    }

  } else {
    // Bin is not full
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    Blynk.virtualWrite(V0, " Bin Empty");
    binWasFull = false;
  }

  delay(1000);
}

long measureDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

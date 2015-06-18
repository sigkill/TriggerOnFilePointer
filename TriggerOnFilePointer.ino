#define TRIGGER_PIN 3
#define DURATION    250

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  
  system("rm /tmp/trigger.gong.fp");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!system("test -e /tmp/trigger.gong.fp")) {
    digitalWrite(TRIGGER_PIN, HIGH);
    delay(DURATION);
    digitalWrite(TRIGGER_PIN, LOW);
    system("rm /tmp/trigger.gong.fp");
    Serial.println("Gong!!!");
  }
 
  delay(1000); 
}

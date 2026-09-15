int trigPin = 9;
int echoPin = 10;

int redLED = 3;
int yellowLED = 4;
int greenLED = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Mesafe ölçümü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long sure = pulseIn(echoPin, HIGH);
  float mesafe = sure * 0.034 / 2;

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  // Mesafeye göre davranışları
  if (mesafe < 2.5) {

    // Kırmızı titreşim-araba aşırı yakın
    digitalWrite(redLED, HIGH);
    delay(100);
    digitalWrite(redLED, LOW);
    delay(100);

  }
  else if (mesafe < 3.5) {

    // Sabit kırmızı-araba çok yakın olmaya başladı
    digitalWrite(redLED, HIGH);

  }
  // sabit sarı-araba orta mesafede
  else if (mesafe < 4.5) {

    
    digitalWrite(yellowLED, HIGH);

  }
  //sabit yeşil-araba uzakta, mesafe çok
  else {
    digitalWrite(greenLED, HIGH);
  }

  delay(50);
}

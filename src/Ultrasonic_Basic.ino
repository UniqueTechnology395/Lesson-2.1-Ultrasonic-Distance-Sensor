// Ορισμός των Pins
const int trigPin = 9;
const int echoPin = 10;

// Μεταβλητές για τον χρόνο και την απόσταση
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Το Trig στέλνει τον ήχο
  pinMode(echoPin, INPUT);  // Το Echo δέχεται την επιστροφή
  Serial.begin(9600);       // Έναρξη επικοινωνίας με την οθόνη (Serial Monitor)
}

void loop() {
  // Καθαρισμός του trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Αποστολή ήχου για 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Ανάγνωση του χρόνου επιστροφής
  duration = pulseIn(echoPin, HIGH);

  // Υπολογισμός απόστασης σε εκατοστά (cm)
  // Ταχύτητα ήχου / 2 (γιατί η διαδρομή είναι πήγαινε-έλα)
  distance = duration * 0.034 / 2;

  // Εμφάνιση αποτελέσματος στο Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Μικρή παύση πριν την επόμενη μέτρηση
}

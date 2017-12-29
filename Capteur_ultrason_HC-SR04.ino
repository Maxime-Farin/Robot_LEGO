/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const byte LED_PIN = 12;  // Broche LED
const byte PIEZO_PIN = 8;  // Broche PIEZO

/* Constantes pour la calibration */
float sensorValue;

 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 50000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

/** Fonction setup() */
void setup() {
   
  /* Initialise le port série */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
 
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);

}
 
/** Fonction loop() */
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */


 long measure[5];
  float average = 0;
  for(int ii = 0; ii < 5; ii++){
  
      digitalWrite(TRIGGER_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGER_PIN, LOW);
    
      measure[ii] = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
      average = average + measure[ii];
      delay(10);
  }
 
  sensorValue = average / 5.0 / 2.0 * SOUND_SPEED; /* Distance en millimetres */

  if(sensorValue < 2000 && sensorValue > 100){
    digitalWrite(LED_PIN, HIGH);

    float pitch = map(sensorValue, 0, 2000, 50, 4000);
    tone(PIEZO_PIN, abs(pitch)); /*abs(sensorValue*1000));*/

    /* Affiche les résultats en mm, cm et m */
    Serial.print(F("Distance: "));
    Serial.print(pitch, 2);
    Serial.println(F("m)"));
  }

  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(500);
  
  digitalWrite(LED_PIN, LOW);
  noTone(PIEZO_PIN);

}

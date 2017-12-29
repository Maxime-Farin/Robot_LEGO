/* 
 * Code d'exemple pour un capteur � ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const byte LED_PIN = 12;  // Broche LED
const byte PIEZO_PIN = 8;  // Broche PIEZO

 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 50000UL; // 25ms = ~8m � 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

/** Fonction setup() */
void setup() {
   
  /* Initialise le port s�rie */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit �tre � LOW au repos
 
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);
}
 
/** Fonction loop() */
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10�s sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son �cho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance � partir du temps mesur� */
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  if(distance_mm/1000 < 1){
    digitalWrite(LED_PIN, HIGH);
    tone(PIEZO_PIN, 294);
  }
  
  /* Affiche les r�sultats en mm, cm et m 
  Serial.print(F("Distance: "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   */

  /* D�lai d'attente pour �viter d'afficher trop de r�sultats � la seconde */
  delay(200);
  
  digitalWrite(LED_PIN, LOW);
  noTone(PIEZO_PIN);

}
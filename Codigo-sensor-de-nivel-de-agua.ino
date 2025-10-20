// Código sensor de nível para horta automática
#define PIN_BOIA_ALTO 3
#define PIN_BOIA_BAIXO 4
#define PIN_BUZZER 12
#define PIN_LED 13

bool boiaAlto, boiaBaixo, erro = false;

void setup() {
  pinMode(PIN_BOIA_ALTO, INPUT_PULLUP); 
  pinMode(PIN_BOIA_BAIXO, INPUT_PULLUP); 
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(erro == false) {
    digitalWrite(PIN_BUZZER, LOW);

    boiaAlto = digitalRead(PIN_BOIA_ALTO);
    boiaBaixo = digitalRead(PIN_BOIA_BAIXO);

    if (boiaAlto == LOW && boiaBaixo == LOW) {
      // Ambas as boias ativadas (nível alto)
      digitalWrite(PIN_LED, HIGH);
      Serial.println("Nível ALTO. Água detectada.");
    } 
    else if (boiaAlto == HIGH && boiaBaixo == LOW) {
      // Apenas boia baixa ativada (nível médio)
      digitalWrite(PIN_LED, HIGH);
      Serial.println("Nível MÉDIO. Água acabando.");
    } 
    else if (boiaAlto == HIGH && boiaBaixo == HIGH) {
      // Nenhuma boia ativada (nível baixo)
      digitalWrite(PIN_LED, LOW);
      Serial.println("Nível BAIXO. Sem água.");
    } 
    else {
      // Estado inválido (boia alta ativada e baixa não)
      erro = true;
      digitalWrite(PIN_LED, HIGH);
      digitalWrite(PIN_BUZZER, HIGH);
      Serial.println("ERRO: Estado inválido das boias!");
    }
    
    delay(500); 
  }
}

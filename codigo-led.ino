// 🟢 Piscar LED - Exemplo básico Arduino
// Autor: Gabriela Bittencourt
// Data: Outubro/2025

// Define o pino onde o LED está conectado
int ledPin = 13;  // O pino 13 já tem um LED embutido em muitas placas

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Liga o LED
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Espera 1 segundo (1000 milissegundos)

  // Desliga o LED
  digitalWrite(ledPin, LOW);
  delay(1000);  // Espera 1 segundo
}

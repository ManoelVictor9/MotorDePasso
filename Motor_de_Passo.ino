
// Declaração das portas que serão utilizadas

const int IN1 = 9;
const int IN2 = 10;
const int IN3 = 11;
const int IN4 = 12;

// Declaração do Array  que representa a sequencia de passos que o motor deve seguir. 32 passos por revolução, portanto, 
// defini um array com 8 elementos (4 fases x 2 passos por fase) que represente uma revolução completa do motor:

byte valores_Step[8] = {B0001, B0011, B0010, B0110, B0100, B1100, B1000, B1001};

void setup() {
  //Definição dos Pinos do motor como saida

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// Função que envia os sinais corretamente para o driver
void step(int direction, int valores_step) {
  for (int i = 0; i < valores_Step; i++) {
    for (int j = 0; j < 8; j++) {
      if (direction == 1) {
        digitalWrite(IN1, bitRead(valores_step[j], 0));
        digitalWrite(IN2, bitRead(valores_step[j], 1));
        digitalWrite(IN3, bitRead(valores_step[j], 2));
        digitalWrite(IN4, bitRead(valores_step[j], 3));
      } else {
        digitalWrite(IN1, bitRead(valores_step[7-j], 0));
        digitalWrite(IN2, bitRead(valores_step[7-j], 1));
        digitalWrite(IN3, bitRead(valores_step[7-j], 2));
        digitalWrite(IN4, bitRead(valores_step[7-j], 3));
      }
      delay(2);
    }
  }
}

void loop() {
  step(1, 150); // Gira 150 passos no sentido horário
  delay(5000);
  step(-1, 50); // Gira 50 passos no sentido anti-horário
  delay(5000);
}

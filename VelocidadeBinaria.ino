  // Declarando pinos de entrada:
  const int inputBit1 = 2;
  const int inputBit2 = 3;
  const int inputBit3 = 4;
  const int inputBit4 = 5;
  // Declarando pinos de saída:
  const int outputBit1 = 8;
  const int outputBit2 = 9;
  const int outputBit3 = 10;
  const int outputBit4 = 11;
  // Declarando os bits de entrada do tempo:
  int tBit1, tBit2, tBit3, tBit4;
  // Declarando os bits de saída da velocidade:
  int vBit1, vBit2, vBit3, vBit4;

  
  int tempo;
  int velocidade;
  int valorbinario[4];

void setup() {

  // Configurando os bits como entrada:
  pinMode (inputBit1, INPUT);
  pinMode (inputBit2, INPUT);
  pinMode (inputBit3, INPUT);
  pinMode (inputBit4, INPUT);

  //Configurando os bits como saída:
  pinMode (outputBit1, OUTPUT);
  pinMode (outputBit2, OUTPUT);
  pinMode (outputBit3, OUTPUT);
  pinMode (outputBit4, OUTPUT);
}


  //Funcao que converte Decimal pra Binario
void dectobin(int valor){
    int i=1;
    while (i<5){
      valorbinario [4-i] = valor % 2;
      valor = valor/2;
      i++;
    }
  }

void loop() {

  //Lê os valores de cada entrada de forma digital:
  
  tBit1 = digitalRead(inputBit1);
  tBit2 = digitalRead(inputBit2);
  tBit3 = digitalRead(inputBit3);
  tBit4 = digitalRead(inputBit4);

  // Calcula o valor analógico do tempo:
  tempo = (tBit4)+(2*tBit3) + (4*tBit2) + (8*tBit1);
  velocidade = 15/tempo;
  
  //Converte o valor da velocidade para binário:
  dectobin (velocidade);
  vBit1 = valorbinario[0];
  vBit2 = valorbinario[1];
  vBit3 = valorbinario[2];
  vBit4 = valorbinario[3];

  //Passa os bits como saída:
  digitalWrite (outputBit1, vBit1);
  digitalWrite (outputBit2, vBit2);
  digitalWrite (outputBit3, vBit3);
  digitalWrite (outputBit4, vBit4);
}

/*#include <LiquidCrystal_I2C.h>

//#include <Adafruit_LiquidCrystal.h>
//Adafruit_LiquidCrystal lcd(0);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alterar o endereço conforme modulo I2C
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 20;
int array[20];
int pontos = 0;

//desenho invertido
byte cabeca1inv[11] = {
  B00110,
  B00001,
  B10000,
  B10000,
  B10000,
  B01000,
  B00101,
  B00011,

};

byte corpo1inv[11] = {
  B00000,
  B00001,
  B00010,
  B10011,
  B10111,
  B10111,
  B11111,
  B11111,
};

byte corpo2inv[11] = {
  B00000,
  B10011,
  B00110,
  B01001,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte bunda1inv[11] = {
  B00110,
  B11000,
  B10000,
  B00000,
  B10000,
  B11100,
  B11110,
  B11111,
};

byte cabeca2inv[11] = {
  B00011,
  B00101,
  B01000,
  B10000,
  B10000,
  B10000,
  B01000,
  B00000,
};

byte corpo3inv[11] = {
  B10111,
  B11111,
  B01110,
  B00111,
  B00111,
  B00010,
  B00001,
  B00000,
};

byte corpo4inv[11] = {
  B11110,
  B10001,
  B01111,
  B11111,
  B00111,
  B00000,
  B00000,
  B00000,
};

byte bunda2inv[11] = {
  B00011,
  B11110,
  B11000,
  B10000,
  B11100,
  B00110,
  B00010,
  B00000,
};
 
void setup() {

  pinMode(BotA, INPUT_PULLUP);
  pinMode(BotB, INPUT_PULLUP);
  pinMode(BotC, INPUT_PULLUP);
  pinMode(BotD, INPUT_PULLUP);

  randomSeed(analogRead(0));
 
  lcd.begin(20, 4);
  //lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
 
  lcd.createChar(9, cabeca1inv);
  lcd.createChar(10, corpo1inv);
  lcd.createChar(11, corpo2inv);
  lcd.createChar(12, bunda1inv);
  lcd.createChar(13, cabeca2inv);
  lcd.createChar(14, corpo3inv);
  lcd.createChar(15, corpo4inv);
  lcd.createChar(8, bunda2inv);
 
  barata();
 
  delay(2500);
  lcd.clear();


  geraSequencia();
}


void loop() {
  for (int i = 0; i < 20; i++) {
    SelecionaQuestao(i);
  }

  delay(1000);
  lcd.clear();
  fimdojogo();
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);


  delay(500);
}


void SelecionaQuestao(int nQuestao) {
  switch (nQuestao) {
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Um");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Quanto tempo durou a ");
      lcd.setCursor( 0, 1);
      lcd.print("guerra dos 100 anos?");
      lcd.setCursor (0, 2);
      lcd.print("A)116 B)113 C)100");
      lcd.setCursor(0, 3);
      lcd.print("D)93");
      if (AnalisaBotao() == 'A') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(120);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(120);
        barataerrado();
      }
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dois");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Um exemplo de bloco");
      lcd.setCursor(0, 1);
      lcd.print("de livre comercio:");
      lcd.setCursor(0, 2);
      lcd.print("A)BRICS B)NAFTA");
      lcd.setCursor(0, 3);
      lcd.print("C)ONU D)OMC");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Tres");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Ha enclise em:");
      lcd.setCursor(0, 1);
      lcd.print("A)amar-te-ia");
      lcd.setCursor(0, 2);
      lcd.print("B)Te amo C)Amo-te");
      lcd.setCursor(0, 3);
      lcd.print("D)Te amarei");
      if (AnalisaBotao() == 'C') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Quatro");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("A celula animal e:");
      lcd.setCursor(0, 1);
      lcd.print("A)procariotica");
      lcd.setCursor(0, 2);
      lcd.print("B)Ameba C)Bastonete");
      lcd.setCursor(0, 3);
      lcd.print("D)Eucariotica");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Cinco");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Quantos elementos");
      lcd.setCursor(0, 1);
      lcd.print("tem a tabela");
      lcd.setCursor(0, 2);
       lcd.print("periodica?");
      lcd.setCursor(0, 3);
      lcd.print("A)113 B)118 C)92 D)9");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Seis");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("E um espelho convexo");
      lcd.setCursor(0, 1);
      lcd.print("A)telescopio");
      lcd.setCursor(0, 2);
      lcd.print("B)de segurança");
      lcd.setCursor(0, 3);
      lcd.print("C)projetor D)plano");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 6:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Sete");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Quanto e 7x8?");
      lcd.setCursor(0, 1);
      lcd.print("A)91 B)49 C)56 D)64");
      if (AnalisaBotao() == 'C') {
        lcd.clear();
        lcd.setCursor(0, 2);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 2);
        barataerrado();
      }
      break;
    case 7:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Oito");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("E um renacentista:");
      lcd.setCursor(0, 1);
      lcd.print("A)Aleijadinho B)Hals");
      lcd.setCursor(0, 2);
      lcd.print("C)Guido D)Da Vinci");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 8:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Nove");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Ecritor de Iracema e");
      lcd.setCursor(0, 1);
      lcd.print("A)Jose de Alencar");
      lcd.setCursor(0, 2);
      lcd.print("B)G.Dias C)M.Assis");
      lcd.setCursor(0, 3);
      lcd.print("D)Alvares de Azevedo");
      if (AnalisaBotao() == 'A') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 9:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dez");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("A palavra Legend");
      lcd.setCursor(0, 1);
      lcd.print("Significa:");
      lcd.setCursor(0, 2);
      lcd.print("A)Conto B)Lenda");
      lcd.setCursor(0, 3);
      lcd.print("C)Gibi D)Lendario");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
       break;
    case 10:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Onze");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("De quem e a frase:");
      lcd.setCursor(0, 1);
      lcd.print("Penso,logo existo.");
      lcd.setCursor(0, 2);
      lcd.print("A)Platao B)Socrates");
      lcd.setCursor(0, 3);
      lcd.print("C)Descartes D)Deus");
      if (AnalisaBotao() == 'C') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 11:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("DOze");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Onde inventaram o");
      lcd.setCursor(0, 1);
      lcd.print("chuveiro eletrico ?");
      lcd.setCursor(0, 2);
      lcd.print("A)Franca B)Brasil");
      lcd.setCursor(0, 3);
      lcd.print("C)Russia D)Canada");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 12:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Treze");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Qual o menor");
      lcd.setCursor(0, 1);
      lcd.print("pais do mundo?");
      lcd.setCursor(0, 2);
      lcd.print("A)Vaticano B)Naru");
      lcd.setCursor(0, 3);
      lcd.print("C)China D)India");
      if (AnalisaBotao() == 'A') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 13:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Quatorze");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Quantas casas");
      lcd.setCursor(0, 1);
      lcd.print("decimais tem o pi?");
      lcd.setCursor(0, 2);
      lcd.print("A)Duas B)Cem C)Mil");
      lcd.setCursor(0, 3);
      lcd.print("D)Infinitas");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 14:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Quinze");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("O numero minimo de");
      lcd.setCursor(0, 1);
      lcd.print("jogadores no jogo de");
      lcd.setCursor(0, 2);
      lcd.print("Futebol");
      lcd.setCursor(0, 3);
      lcd.print("A)9 B)11 C)7 D)8");
      if (AnalisaBotao() == 'C') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 15:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dezesseis");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Qual o maior animal");
      lcd.setCursor(0, 1);
      lcd.print("terrestre?");
      lcd.setCursor(0, 2);
      lcd.print("A)Girafa B)T-rex");
      lcd.setCursor(0, 3);
      lcd.print("C)Baleia D)Elefante");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 16:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dezesste");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Qual o animal que");
      lcd.setCursor(0, 1);
      lcd.print("amamentou Romulo e");
      lcd.setCursor(0, 2);
      lcd.print("Remulo A)Cabra");
      lcd.setCursor(0, 3);
      lcd.print("B)Vaca C)Gata D)Loba");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 17:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dezoito");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Qual o metal cujo");
      lcd.setCursor(0, 1);
      lcd.print("simbolo quimico e Au");
      lcd.setCursor(0, 2);
      lcd.print("A)Cobre B)Prata");
      lcd.setCursor(0, 3);
      lcd.print("C)Ouro D)manganes");
      if (AnalisaBotao() == 'C') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
      break;
    case 18:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Dezenove");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Quantos ossos temos");
      lcd.setCursor(0, 1);
      lcd.print("no nosso corpo?");
      lcd.setCursor(0, 2);
      lcd.print("A)126 B)206 C)300");
      lcd.setCursor(0, 3);
      lcd.print("D)200");
      if (AnalisaBotao() == 'B') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
      }
     break;
    case 19:
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(1200);
      lcd.print("Questão");
      lcd.setCursor( 7, 2);
      lcd.print("Vinte");
      lcd.setCursor (9, 3);
      delay(500);
      lcd.print("Qual o maior planeta");
      lcd.setCursor(0, 1);
      lcd.print("do sistema solar?");
      lcd.setCursor(0, 2);
      lcd.print("A)Lua B)Sol C)Marte");
      lcd.setCursor(0, 3);
      lcd.print("D)Jupter");
      if (AnalisaBotao() == 'D') {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        baratacerto();
        pontos++;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        delay(1200);
        barataerrado();
    }
      break;

  }
}

char AnalisaBotao() {
  bool BotaoPressionado = true;

  while (BotaoPressionado) {
    if (!digitalRead(BotA)) {
      BotaoPressionado = false;
      return 'A';
    } else if (!digitalRead(BotB)) {
      BotaoPressionado = false;
      return 'B';
    } else if (!digitalRead(BotC)) {
      BotaoPressionado = false;
      return 'C';
    } else if (!digitalRead(BotD)) {
      BotaoPressionado = false;
      return 'D';
    }
  }
}

void barata() {
   
for(int i=20; i>0; i--){
  if(i-4 > 0){
    lcd.setCursor(i-4, 1);
    lcd.write(9);
    lcd.setCursor(i-4, 2);
    lcd.write(13);
  }
 
  if(i-3 > 0){
    lcd.setCursor(i-3, 1);
    lcd.write(10);
    lcd.setCursor(i-3, 2);
    lcd.write(14);
  }
  if(i-2 > 0){
    lcd.setCursor(i-2, 1);
    lcd.write(11);
    lcd.setCursor(i-2, 2);
    lcd.write(15);
  }
  if(i-1 > 0){
    lcd.setCursor(i-1, 1);
    lcd.write(12);
    lcd.setCursor(i-1, 2);
    lcd.write(8);
  }
  delay(100);
  lcd.clear();
}
  delay(200);
  lcd.setCursor(5, 1);
  lcd.print("Bem Vindo!");
  lcd.setCursor(6, 2);
  lcd.print("Jogador");
  delay(1500);
 
  //lcd.clear();
 
  Serial.begin(9600);
  delay(2000);
  //lcd.clear();
}


void baratacerto() {
 
for(int i=20; i>0; i--){
  if(i-4 > 0){
    lcd.setCursor(i-4, 1);
    lcd.write(9);
    lcd.setCursor(i-4, 2);
    lcd.write(13);
  }
 
  if(i-3 > 0){
    lcd.setCursor(i-3, 1);
    lcd.write(10);
    lcd.setCursor(i-3, 2);
    lcd.write(14);
  }
  if(i-2 > 0){
    lcd.setCursor(i-2, 1);
    lcd.write(11);
    lcd.setCursor(i-2, 2);
    lcd.write(15);
  }
  if(i-1 > 0){
    lcd.setCursor(i-1, 1);
    lcd.write(12);
    lcd.setCursor(i-1, 2);
    lcd.write(8);
  }
  delay(100);
  lcd.clear();
}
  delay(200);
  lcd.setCursor(5, 1);
  lcd.print("Correto!!");
   lcd.setCursor(8, 2);
  lcd.print(":)");

  delay(1500);
 
  //lcd.clear();
 
  Serial.begin(9600);
  delay(2000);
  //lcd.clear();
}



void barataerrado() {
 
for(int i=20; i>0; i--){
  if(i-4 > 0){
    lcd.setCursor(i-4, 1);
    lcd.write(9);
    lcd.setCursor(i-4, 2);
    lcd.write(13);
  }
 
  if(i-3 > 0){
    lcd.setCursor(i-3, 1);
    lcd.write(10);
    lcd.setCursor(i-3, 2);
    lcd.write(14);
  }
  if(i-2 > 0){
    lcd.setCursor(i-2, 1);
    lcd.write(11);
    lcd.setCursor(i-2, 2);
    lcd.write(15);
  }
  if(i-1 > 0){
    lcd.setCursor(i-1, 1);
    lcd.write(12);
    lcd.setCursor(i-1, 2);
    lcd.write(8);
  }
  delay(100);
  lcd.clear();
}
  delay(200);
  lcd.setCursor(5, 1);
  lcd.print("Errado!!!");
  lcd.setCursor(8, 2);
  lcd.print(":(");
 
  delay(1500);

  //lcd.clear();
 
  Serial.begin(9600);
  delay(2000);
  //lcd.clear();
}



void fimdojogo() {

 
for(int i=20; i>0; i--){
  if(i-4 > 0){
    lcd.setCursor(i-4, 1);
    lcd.write(9);
    lcd.setCursor(i-4, 2);
    lcd.write(13);
  }
 
  if(i-3 > 0){
    lcd.setCursor(i-3, 1);
    lcd.write(10);
    lcd.setCursor(i-3, 2);
    lcd.write(14);
  }
  if(i-2 > 0){
    lcd.setCursor(i-2, 1);
    lcd.write(11);
    lcd.setCursor(i-2, 2);
    lcd.write(15);
  }
  if(i-1 > 0){
    lcd.setCursor(i-1, 1);
    lcd.write(12);
    lcd.setCursor(i-1, 2);
    lcd.write(8);
  }
  delay(100);
  lcd.clear();
}
  delay(200);
   lcd.setCursor(24, 0);
  lcd.print("Fim de jogo");
  lcd.setCursor(23, 1);
  lcd.print("Voce fez ");
  delay(500);
  lcd.setCursor(32, 1);
  lcd.print(pontos++);
  lcd.setCursor(33, 1);
  lcd.print("/20");

  //lcd.clear();
 
  Serial.begin(9600);
  delay(2000);
  //lcd.clear();
}


void geraSequencia() {
  for (int i = 0; i < nQuestao; i++) {
    array[i] = i;
  }
  for (int i = 0; i < nQuestao; i++) {
    int temp = array[i];
    int novoIndice = random(nQuestao);
    array[i] = array[novoIndice];
    array[novoIndice] = temp;
  }
}

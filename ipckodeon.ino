/*
 *                  IPčko Deónik
 *              created by VincoNafta
 * 
 */

/*
 * Definovanie jednotilivých pinov, piny môžete prepísať
 * Podporované dosky Arduino UNO, Arduino Mini, Arduino Nano
 * Podporovane piny 3, 5, 6, 9, 10, 11
 */
#define MAX_JAS 50
const int Ichar = 11;
const int Pchar = 9;
const int dot1 = 6;
const int dot2 = 5;
const int dot3 = 3;
/*
 * Deklarácia a inicializácia celého deóniku
 */
int diody[] = {Ichar, Pchar, dot1, dot2, dot3};
int diodesCount=5;

/*
 * Nastavenie pinov na východziu hodnotu, do tejto časti nezasahujte ak neviete čo robíte
 */
void setup() {
  for (int i = 0; i < diodesCount; i++) {
    pinMode(diody[i], OUTPUT);
  }

}

/*
 * Nekonečná slučka, tu môžte prepísať poradie animácii, prípadne zmeniť čas
 */
void loop() {
  repeatShowDots(350, 12, 3);
  turnOffAll(0);
  delay(1000);
  turnOnAll(500,15);
  delay(6000);
  turnOffAllReverse(1000);
  delay(3000);
  blick(2400,12,5);
  postupneRozsvedcuj(250);
  delay(1000);
  postupneZhasni(250);
  delay(3000);
  
  

}

/*
 * Vysvietenie všetkých diod s časovým intervalom čakanie, v prípade 0 sa nebude čakať. Rozsah jasu je 0-100
 */
void turnOnAll(const int timeOn, const int jas) {
  for(int i = 0; i< diodesCount; i++) {
    analogWrite(diody[i], jas);
    delay(timeOn);
  }
}

/*
 * Blikanie všetkých diod podľa času, jasu, posledný parameter je počet krát koľko sa má opakovať blikanie
 */
void blick(const int timeB, const int jas, const int countTimes) {
  for (int i = 0; i < countTimes; i++) {
    turnOnAll(0,jas);
    delay(timeB);
    turnOffAll(0);
    delay(timeB);
  }
}

/**
 * Postupné rozsvitenie všetkých diod na maximálnu stanovenú hodnutu
 */
void postupneRozsvedcuj(const int timeOn) {
  for(int i = 0; i< MAX_JAS; i++) {
    turnOnAll(0, i);
    delay(timeOn);
  }
}

/**
 * Postupné zhasínanie diod 
 */
void postupneZhasni(const int timeOff) {
  for(int i = MAX_JAS; i > 0; i--) {
    turnOnAll(0, i);
    delay(timeOff);
  }
}

/*
 * Zhasnutite všetkých diod s časovým intervalom čakanie, v prípade 0 sa nebude čakať
 */
void turnOffAll(const int timeOn) {
  /*for(int i = 0; i< diodesCount; i++) {
    analogWrite(diody[i], 0);
    delay(timeOn);
  }*/
  turnOnAll(timeOn, 0);
}


/*
 * Vysvietenie I a P písmena
 */
void showIP(const int timeOn, const int jas) {
  for(int i = 0; i< 2; i++) {
    analogWrite(diody[i], jas);
    delay(timeOn);
  }
}

/*
 * Vysvietenie bodiek
 */
void showDots(const int timeOn, const int jas){
    for(int i = 2; i< diodesCount; i++) {
    analogWrite(diody[i], jas);
    delay(timeOn);
  }
}

/**
 * Opakované rozsvietenie všetkych diod ako bodky. Parametre su čas po ktory sa budu diody, jas diod a počet krát po ktorý sa majú diody rozsvietiť
 */
void repeatShowDots(const int timeOn, const int jas, const int repeatTimes) {
  for (int i = 0; i < repeatTimes; i++) {
    showDots(timeOn, jas);
    delay(timeOn);
    turnOffAll(0);
  }
}


/*
 * Zhasnutie od poslednej bodky s časovým intervalom. Ak je 0 nebude sa čakať
 */
void turnOffAllReverse(const int timeOn) {
  for(int i = diodesCount-1; i>= 0; i--) {
    analogWrite(diody[i], 0);
    delay(timeOn);
  }
}

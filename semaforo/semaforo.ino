int s1[] = {8, 9, 10};
int s2[] = {5, 6, 7};
// int semaforo = {verde, ambar, rojo}
byte u[] = {B00000000,B00000001,B00000010,B00000011,B00000100,B00000101,
                          B00000110,B00000111,B00001000,B00001001};
byte d[] = {B00000000,B00000001,B00000010,B00000011,B00000100,B00000101};

void setup() {
  for(int i=0; i<14; i++){
    pinMode(i, OUTPUT);
  }
    // display decenas
    digitalWrite(4, 0);
    digitalWrite(11, 1);
    digitalWrite(12, 1);
    digitalWrite(13, 0) ; 
    // display unidades
    digitalWrite(0, 0);
    digitalWrite(1, 0);
    digitalWrite(2, 0);
    digitalWrite(3, 0) ; 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  cambiar(8,7);  // iniciamos el semaforo
  // Cuenta regresiva
  for (int i=5; i>=0; i--){
    digitalWrite(4, bitRead (d[i], 0));
    digitalWrite(11, bitRead (d[i], 1));
    digitalWrite(12, bitRead (d[i], 2));
    digitalWrite(13, bitRead (d[i], 3)) ; 
    for (int j=9; j>=0; j--){
      digitalWrite(0, bitRead (u[j], 0));
      digitalWrite(1, bitRead (u[j], 1));
      digitalWrite(2, bitRead (u[j], 2));
      digitalWrite(3, bitRead (u[j], 3)) ; 
      delay(1000);
      if (j==2 && i ==0){
        cambiar(9,7);    // Ambar
      }
    }
  }
  
  cambiar(10,5); // cambia a rojo
   // cambia a verde
  for (int i=5; i>=0; i--){
    digitalWrite(4, bitRead (d[i], 0));
    digitalWrite(11, bitRead (d[i], 1));
    digitalWrite(12, bitRead (d[i], 2));
    digitalWrite(13, bitRead (d[i], 3)) ; 
  
    for (int j=9; j>=0; j--){
      digitalWrite(0, bitRead (u[j], 0));
      digitalWrite(1, bitRead (u[j], 1));
      digitalWrite(2, bitRead (u[j], 2));
      digitalWrite(3, bitRead (u[j], 3)) ; 
      delay(1000);
      if (j==2 && i ==0){
        cambiar(6,10);    // Ambar
      }
    }
  }
}

void cambiar(int c1, int c2){
  // c1 y c2 representan los pines para cada cada color de los semaforos
  int i, j;
  for(i=5; i<11; i++){
    if(i==c1){
      digitalWrite(c1,HIGH); // prender color
    }else if(i == c2){
      digitalWrite(c2,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
}

// Ejercicio evaluatorio 3er bimestre
/*
  Integrantes
    Nombre: Felipe
    Apellido: Maierowicz
    Curso: 3C
    
    Nombre: Jonás
    Apellido: Leiserson
    Curso: 3C
  
Congisgnas
  Conexionado:
    En la protoboard, conectar 4 LEDs para que cada uno pueda ser controlado individualmente. Cada LED deberá tener su respectiva resistencia.
    Se debe conectar tambien, un pulsador que permita recibir información de un usuario.
    Indicar a continuación los pines a los cuales se conectó cada elemento y el valor de resistencias utilizado:
      Pines:
        Boton: 10
        LED1: 2
        LED2: 4
        LED3: 6
        LED4: 8
      Valor:
        R_boton: 47k Ohms 5%
        R_LEDs: 10 Ohms 5%

  Progamas:
    Se deben entregar un programa distinto por cada punto. Los programas son una modificación entre ellos.
    El código deberá estar comentado indicando qué se propone hacer con cada línea de código
    1.  El primer programa sirve para corroborar la correcta conexión de los elementos de hardware.
        El mismo deberá encender TODOS los LEDs cuando se presione el pulsador y apagarlos cuando éste se suelte.
    2.  En el siguiente programa se deberá prender de a UN LED POR VEZ.
        Por cada pulsación se deberá apagar el LED prendido y prender el LED más próximo de la derecha.
        En caso de no haber, se deberá volver a empezar la vuelta, empezando desde el LED de la izquierda.
    3.  A continnuación se desea fabricar un contador binario de 4 bits.
        El programa deberá contar de 0 a 15 mostrando la cuenta actual a través de los 4 LEDs.
        Se interpreta 0 si el LED está apagado y 1 si el LED está prendido. 
        La cuenta aumenta cada vez que el pulsador es presionado, al llegar a 15 deberá volver a empezar en 0.
        IMPORTANTE: la cuenta debe aumentar UNA SOLA VEZ por cada pulsación.
    4. Opcional:
        Utilizando comunicación serie, se desea crear un programa que muestre mediante los LEDs, el nro ingresado en el monitor serie.
        El programa deberá mostrar el número binario prendiendo los LEDs según el criterio del programa 3.
        El nro mostrado será ingresado por el usuario mediante el monitor serie.
        IMPORTANTE: si el nro es mayor a 15 se deberá enviar un mensaje de error. 

*/ 

#define azul 2
#define amarillo 4
#define verde 6
#define rojo 8
#define boton 10
//nombrando cada pin a su respectivo led o boton
bool valorBoton = 0; // preparado para leer el valor del input
bool valorAnterior = 0;

void setup() {
  pinMode(azul, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(boton, INPUT);
  //configurando funcionalidad de los pines
}

void loop() {
  valorBoton = digitalRead(boton);
  if(valorBoton && !valorAnterior) { //se apreto el boton y no estaba apretado antes

    //contando en binario
    if(digitalRead(azul)) { //esta prendido el led azul
      digitalWrite(azul, 0);
      if(!digitalRead(amarillo)) {
        digitalWrite(amarillo, 1);
      }
      else{
        if(!digitalRead(verde)) {
          digitalWrite(verde, 1);
          digitalWrite(amarillo, 0);
        }
        else{
            if(!digitalRead(rojo)){
            digitalWrite(rojo, 1);
            digitalWrite(verde, 0);
            digitalWrite(amarillo, 0);
            }
            else {
            digitalWrite(azul, 0);
            digitalWrite(amarillo, 0);
            digitalWrite(verde, 0);
            digitalWrite(rojo, 0);
            }
        }
      }
    }
    else{
      digitalWrite(azul, 1);
    }
    
  }
  
  valorAnterior = valorBoton;
  delay(250);
}

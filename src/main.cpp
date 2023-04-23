#include <Arduino.h>
#include "L9110.h"
#include "GP2Y0E03.h"
//deben de ser sobre los pines PWM

L9110 Motores(6,9,3,5);//6 y 9 control de setido de motor A
                      /3 y 5 contro de sentido de motor B
sensor_distancia sensor(0,0); ///leemos en el pin analogico 0

void setup() {
  Serial.begin(9600);
  //debo de implementar un pulsador o selector
  delay(5000);
}

void loop() {
  //Lee_sensor(0);
  //girar(l,r,t); //l: velocidad de motor izquierdo
                  //r: velocidad de motor derecho
                  //t: tiempo de espera
  //adelante(l,r,t);//l: velocidad de motor izquierdo
                  //r: velocidad de motor derecho
                  //t: tiempo de espera
  //atras(l,r,t);//l: velocidad de motor izquierdo
                  //r: velocidad de motor derecho
                  //t: tiempo de espera

}
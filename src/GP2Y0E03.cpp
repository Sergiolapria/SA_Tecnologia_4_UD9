#include "GP2Y0E03.h"
#include "Arduino.h"
#include "Wire.h"

sensor_distancia::sensor_distancia(int MODEREAD,int Pin){
    this->_MODEREAD=MODEREAD;
    this->_Pin=Pin;
}
int sensor_distancia::Lee_sensor(int _Pin){
    _measure=analogRead(_Pin);
    return _measure;
}
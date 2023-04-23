/*Pinout del sensor
-SDA
-SCL
-GPIO1
-2.7V|5.5V
-GND
-Vout
-VDD(5v)
*/
/////I2C no implementado todavia, es más lento
#ifndef GP2Y
#define GP2Y
class sensor_distancia{
    public:
        sensor_distancia(int MODEREAD,int Pin);
        int Lee_sensor(int Pin);
    private:
        int _MODEREAD;
        int _Pin;
        int _measure;

};
#endif
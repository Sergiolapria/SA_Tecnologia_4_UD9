# SA_Tecnologia_4_UD9
Situación de aprendizaje UD9.Telecomunicaciones digitales
Se detalla la situacion de aprendizaje de la UD9. Telecomunicaciones digitales, concerniente con el saber básico C.3, según el RD217/2022.
En esta situación de aprendizaje el alumnado debera de analizar la presente aplicación de IoT compuesta por un NodeMCU leyendo valores de un sensor de temperatura y humedad que los envia siguiendo el protocolo MQTT y es visualizado en una app realizada en NodeRed.
## COMPONENTES HW NECESARIOS
1. Raspberry Pi3 mínimo conectado a nuestra red con broker de MQTT y node-RED ejecuntandose.
2. DOIT ESP32 o similar.
3. Sensores AHT10, BME680 o VEML6070.
## COMPONENTES SW NECESARIOS
1. VSC con PlatFomIO, se puede usar el IDE de Arduino, se debera de instalar para este proyecto la libreria "PubSubClient.h" de https://github.com/knolleary.
2. Raspberry PI con Mosquitto y Node-red instalados[^1], podemos obviar el Node-red e instalarlo en los ordenadores del aula si tenemos miedo a sobrecargar la RPI.
3. Angry IP Scanner o similar.
## OBJETIVOS
Se hace esta instalación base con el fin de que el alumnado investigue por si mismo acerca del potencial del IoT prototipando sus propios proyectos.
## COMPONENTES
1. Ficheros para el ESP32 acabados en .cpp y h
2. Fichero .json para Node-red.
[^1]: Se obvia el paso de instalar estos programas ya que en la red existen multitud de tutoriales acerca de estos pasos.

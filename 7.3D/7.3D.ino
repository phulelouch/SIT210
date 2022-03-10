#I will be using gpiozero instead of rpi.gpio in this project

from time import sleep
import gpiozero

led = gpiozero.PWMLED(14)
ultrasonic = gpiozero.DistanceSensor(echo=17, trigger=4)


led.on()
while True:
    distance= round(ultrasonic.value,1)
    sleep(0.1)
    led.value = 1-distance



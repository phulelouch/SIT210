from gpiozero import Button
from gpiozero import PWMLED
import requests
import RPi.GPIO as io

flashingLight_pin = 27
button = Button(22)

io.setup(flashingLight_pin, io.OUT)
io.output(flashingLight_pin, io.LOW)

send=False
send2=False
pressed=False

def send_mess(mess):
    data="ALARM " +  mess
    r=requests.post("https://maker.ifttt.com/trigger/gas/with/key/b0Po42qqDHZtYh35jt9kbY", json={"value1":data})



def alarm(gas,flame):
    if((gas>1000 or flame>500) and pressed==False):
        io.output(flashingLight_pin, io.HIGH)
    else:
         io.output(flashingLight_pin, io.LOW)

while True:
    gas_value = float(requests.get('http://128.199.190.200:9000/?read=1').text)
    flame_value = float(requests.get('http://128.199.190.200:9000/?read=2').text)
    button_value = float(requests.get('http://128.199.190.200:9000/?read=3').text)

    alarm(gas_value, flame_value)

    if(gas_value>1000):
        if(send==False):
            send_mess("GAS LEAK!!!")
            send=True
    else:
        send=False
        

    if(flame_value>500):
        if(send2==False):
            send_mess("FIRE!!!")
            send2=True
    else:
        send2=False


    if(button_value==1):
        pressed = True
    elif(button_value==0):
        pressed = False

    if(button.is_pressed):
        pressed=True
        io.output(flashingLight_pin, io.HIGH)
        data={"button":1}
        r = requests.post('http://128.199.190.200:9000', data=data)
        print("send "+r.text)


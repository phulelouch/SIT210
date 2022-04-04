from tkinter import *

import RPi.GPIO as GPIO
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(10, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(12, GPIO.OUT, initial=GPIO.LOW)



root = Tk()
root.title("SIT210 - 5.2C")

r = IntVar()


def clicked(value):
    print(value)
    if(value==2):
        GPIO.output(8, GPIO.HIGH)
        GPIO.output(10, GPIO.LOW)
        GPIO.output(12, GPIO.LOW)
    elif(value==1):
        GPIO.output(8, GPIO.LOW)
        GPIO.output(10, GPIO.LOW)
        GPIO.output(12, GPIO.HIGH)
    else:
        GPIO.output(8, GPIO.LOW)
        GPIO.output(10, GPIO.HIGH)
        GPIO.output(12, GPIO.LOW)
        
        


Radiobutton(root, text="RED", variable=r, value=1, command=lambda: clicked(r.get())).pack()
Radiobutton(root, text="YELLOW", variable=r, value=3, command=lambda: clicked(r.get())).pack()
Radiobutton(root, text="GREEN", variable=r, value=2, command=lambda: clicked(r.get())).pack()

mainloop ()

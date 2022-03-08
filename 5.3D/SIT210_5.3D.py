from tkinter import *
from time import sleep
from tkinter import messagebox
import RPi.GPIO as GPIO

GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)


root = Tk()
root.title("SIT210 - 5.3D")

e = Entry(root,width=40)
e.pack()

def clicked():
    if(len(e.get()) > 12):
      messagebox.showinfo(message="> 12 characters, take 12 only") 

    print(e.get().upper()[:12])
    morse = encrypt(e.get().upper()[:12])
    print(morse)
    print(len(morse))
    for i in range(0,len(morse)):
        print(i)
        if(morse[i]=="."):
            GPIO.output(8, GPIO.HIGH)
            sleep(0.3)
            GPIO.output(8, GPIO.LOW)
            sleep(1)
        elif(morse[i]=="-"):
            GPIO.output(8, GPIO.HIGH)
            sleep(1)
            GPIO.output(8, GPIO.LOW)
            sleep(1)
        else:
            sleep(1)



myButton = Button(root, text="Enter text all you want, we will take 12 only", command=clicked)
myButton.pack()

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}
 
# Function to encrypt the string
# according to the morse code chart
def encrypt(message):
    cipher = ''
    for letter in message:
        if letter != ' ':
 
            # Looks up the dictionary and adds the
            # correspponding morse code
            # along with a space to separate
            # morse codes for different characters
            cipher += MORSE_CODE_DICT[letter] + ' '
        else:
            # 1 space indicates different characters
            # and 2 indicates different words
            cipher += ' '
 
    return cipher

mainloop()

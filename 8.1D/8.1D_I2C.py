#!/usr/bin/python
import smbus
import time
 
# Define some constants from the datasheet
DEVICE     = 0x23 # Default device I2C address
POWER_DOWN = 0x00 # No active state
POWER_ON   = 0x01 # Power on
RESET      = 0x07 # Reset data register value
ONE_TIME_HIGH_RES_MODE = 0x20
 
bus = smbus.SMBus(1)  # Rev 2 Pi uses 1
 
def convertToNumber(data):
  return ((data[1] + (256 * data[0])) / 1.2)
 
def readLight(addr=DEVICE):
  data = bus.read_i2c_block_data(addr,ONE_TIME_HIGH_RES_MODE)
  return convertToNumber(data)
 
def main():
 
  while True:
    x = readLight()
    if x > 300:
        print("Too bright")
    elif x > 200 and x < 300:
        print("Bright")
    elif x > 100 and x < 200:
        print("Medium")
    elif x > 30 and x < 100:
        print("Dark")
    else:
        print("Too Dark")
    time.sleep(0.5)
 
if __name__=="__main__":
   main()


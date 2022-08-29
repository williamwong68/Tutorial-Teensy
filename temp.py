import serial
import string
import paho.mqtt.publish as publish

#AWS EC2 ip
EC2 = "3.27.48.19"

#Connect to Bluetooth
ser = serial.Serial("/dev/rfcomm0", 9600)
ser.write(str.encode('start\r\n')) #Send write to Arduino

while True:
  if ser.in_waiting > 0:
    rawserial = ser.readline()
    cookedserial = rawserial.decode('utf-8').strip('\r\n')
    print(cookedserial)
    
    humi = cookedserial[11:16]
    print(humi)
    
    temp = cookedserial[32:37]
    print(temp)
    
    heat = cookedserial[59:64]
    print(heat)
    
    publish.single("Show/Humi", humi, hostname = EC2)
    publish.single("Show/Temp", Temp, hostname = EC2)
    publish.single("Show/Heat", heat, hostname = EC2)

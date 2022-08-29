import paho.mqtt.client as mqtt
import serial
import string

EC2 = "3.27.48.19"

#Connect to MQTT
def on_connect(client, userdata, flags, rc):
	print("Connected to MQTT")
	print("Connected with result code " + str(rc))
	# Create Topics
	client.subscribe("Show/Humi")
	client.subscribe("Show/Temp")
	client.subscribe("Show/Heat")

#Sending message
def on_message(client, userdata, msg):
	print(msg.topic + " " + str(msg.payload))
	
	temp = float(msg.payload)
	# Check the temperature is greater or equal than 28.00
	# If yes turn the LED on
	if temp >= 28.00:  
		#Connect to Bluetooth
		ser = serial.Serial("/dev/rfcomm0", 9600)
		#Send the command through BlueTooth
		ser.write(str.encode('ON'))
	# If no, will not turn the LED on
	elif temp < 28.00:
		#Connect to Bluetooth
		ser = serial.Serial("/dev/rfcomm0", 9600)
		#Send the command through BlueTooth
		ser.write(str.encode('OFF'))
	

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(EC2, 1883, 60)

client.loop_forever()


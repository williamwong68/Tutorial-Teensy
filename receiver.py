import paho.mqtt.client as mqtt
import serial
import string

ser = serial.Serial("/dev/rfcomm0", 9600)

#Connect to MQTT
def on_connect(client, userdata, flags, rc):
	print("Connected to MQTT")
	print("Connected with result code " + str(rc))
	client.subscribe("ifn649")

#Sending message
def on_message(client, userdata, msg):
	print(msg.topic + " " + str(msg.payload))
	print(msg.payload)
	
	ser.write(msg.payload)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("3.27.48.19", 1883, 60)

client.loop_forever()


import socket

HOST = '127.0.0.1'
PORT = 12345

clisock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
clisock.connect((HOST,PORT))

name = input(str("Enter your name "))

clisock.sendto(name.encode(),(HOST,PORT))

s_name,addr = clisock.recvfrom(1024)
s_name = s_name.decode()

print(f"{s_name} has joined the chat room\nEnter [e] to exit")
while True:
	message,addr = clisock.recvfrom(1024)
	message = message.decode()
	print(f"{s_name}: {message}")
	message = input(str("Me: "))
	if message == "[e]":
		message = "Left chat room"
		clisock.sendto(message.encode(),(HOST,PORT))
		print("\n")
		break
	clisock.sendto(message.encode(),(HOST,PORT))



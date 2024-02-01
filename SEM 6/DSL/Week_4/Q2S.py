import socket

HOST = '127.0.0.1'
PORT = 12345

servsock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

servsock.bind((HOST,PORT))

s_name,addr = servsock.recvfrom(1024)
s_name = s_name.decode()
print(f"{s_name} has connected to the chat room\nEnter [e] to exit")
name = input(str("Enter your name: "))
servsock.sendto(name.encode(),(addr[0],addr[1]))

while True:
	message = input(str("Me: "))
	if message == "[e]":
		message = "Left chat room"
		servsock.sendto(message.encode(),(addr[0],addr[1]))
		print("\n")
		break
	servsock.sendto(message.encode(),(addr[0],addr[1]))
	message,addr = servsock.recvfrom(1024)
	message = message.decode()
	print(f"{s_name}: {message}")
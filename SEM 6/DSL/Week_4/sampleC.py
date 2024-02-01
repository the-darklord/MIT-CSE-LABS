import socket

#1

# sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
# udp_host = socket.gethostname()
# udp_port = 12345
# msg = "UDP Program!"
# print("UDP target IP:", udp_host)
# print("UDP target Port:", udp_port)
# sock.sendto(msg.encode(),(udp_host,udp_port))


#2

# HOST = '127.0.0.1'
# PORT = 2054
# with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#     s.connect((HOST, PORT))
#     s.sendall(b'Hello, world')
#     data = s.recv(1024)
#     print('Received Connection')
#     print('Server:', data.decode())


#3

# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# host = socket.gethostname()
# port = 9991
# s.connect((host, port))
# tm = s.recv(1024)
# print(' Current time from Sever :', tm.decode())
# s.close()


#4

# HOST = '172.16.59.36'
# PORT = 31621
# s = socket.socket()
# name = input(str("\nEnter your name: "))
# print("\nTrying to connect to ", HOST, "(", PORT, ")\n")
# s.connect((HOST, PORT))
# print("Connected...\n")
# s.send(name.encode())
# s_name = s.recv(1024)
# s_name = s_name.decode()
# print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")
# while True:
#     message = s.recv(1024)
#     message = message.decode()
#     print(s_name, ":", message)
#     message = input(str("Me : "))
#     if message == "[e]":
#         message = "Left chat room!"
#         s.send(message.encode())
#         print("\n")
#         break
#     s.send(message.encode())


#5

# ClientSocket = socket.socket()
# host = '127.0.0.1'
# port = 1233
# print('Waiting for connection')
# try:
#     ClientSocket.connect((host, port))
# except socket.error as e:
#     print(str(e))
# Response = ClientSocket.recv(1024)
# while True:
#     Input = input('Say Something: ')
#     ClientSocket.send(str.encode(Input))
#     Response = ClientSocket.recv(1024)
#     print(Response.decode('utf-8'))
# ClientSocket.close()
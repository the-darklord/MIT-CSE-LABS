import socket

#1

# sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
# udp_host = socket.gethostname()
# udp_port = 12345
# sock.bind((udp_host, udp_port))
# while True:
#     print("Waiting for client...")
#     data,addr = sock.recvfrom(1024)
#     print("Received Messages:",data.decode()," from",addr)


#2

# HOST = '127.0.0.1'
# PORT = 2054
# with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#     s.bind((HOST, PORT))
#     s.listen()
#     conn, addr = s.accept()
#     with conn:
#         print('Connected by', addr)
#         while True:
#             data = conn.recv(1024)
#             if data:
#                 print("Client: ",data.decode())
#                 data = input("Enter message to client:");
#             if not data:
#                 break;
#             conn.sendall(bytearray(data, 'utf-8'));
#         conn.close()


#3

# import time
# serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# host = socket.gethostname()
# port = 9991
# serversocket.bind((host, port))
# serversocket.listen(5)
# while True:
#     clientsocket,addr = serversocket.accept()
#     print("Got a connection from %s" % str(addr))
#     currentTime = time.ctime(time.time()) + "\r\n"
#     clientsocket.send(currentTime.encode('ascii'))
#     clientsocket.close()


#4

# HOST = '172.16.59.21'
# PORT = 31621
# s = socket.socket()
# s.bind((HOST, PORT))
# s.listen()
# print("\nWaiting for incoming connections...\n")
# conn, addr = s.accept()
# print("Received connection from ", addr[0], "(", addr[1], ")\n")
# s_name = conn.recv(1024)
# s_name = s_name.decode()
# print(s_name, "has connected to the chat room\nEnter [e] to exit chat room\n")
# name = input(str("Enter your name: "))
# conn.send(name.encode())
# while True:
#     message = input(str("Me : "))
#     if message == "[e]":
#         message = "Left chat room!"
#         conn.send(message.encode())
#         print("\n")
#         break
#     conn.send(message.encode())
#     message = conn.recv(1024)
#     message = message.decode()
#     print(s_name, ":", message)


#5

# import os
# from _thread import *
# ServerSocket = socket.socket()
# host = '127.0.0.1'
# port = 1233
# ThreadCount = 0
# try:
#     ServerSocket.bind((host, port))
# except socket.error as e:
#     print(str(e))
# print('Waitiing for a Connection..')
# ServerSocket.listen(5)

# def threaded_client(connection):
#     connection.send(str.encode('Welcome to the Servern'))
#     while True:
#         data = connection.recv(2048)
#         reply = 'Server Says: ' + data.decode('utf-8')
#         if not data:
#             break
#         connection.sendall(str.encode(reply))
#     connection.close()

# while True:
#     Client, address = ServerSocket.accept()
#     print('Connected to: ' + address[0] + ':' + str(address[1]))
#     start_new_thread(threaded_client, (Client, ))
#     ThreadCount += 1
#     print('Thread Number: ' + str(ThreadCount))
# ServerSocket.close()
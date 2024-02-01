import socket
import time

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
host = '127.0.0.1'
port = 6996
s.bind((host,port))

while True:
    data,addr  =s.recvfrom(1024)
    print('Got Connection from : ',str(addr))
    Time = time.ctime(time.time())+"\r\n"
    s.sendto(Time.encode(),addr)
s.close()

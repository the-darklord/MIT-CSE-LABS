import socket

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
host = '127.0.0.1'
port = 6996
s.connect((host,port))
s.sendto(b'Send Time',(host,port))
Time,addr = s.recvfrom(1024)
print('Time from Server : ',Time.decode())
s.close()
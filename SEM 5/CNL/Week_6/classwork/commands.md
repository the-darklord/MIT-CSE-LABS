### Configuring PC

# PC1
ip 30.0.0.1/8 30.255.255.254

# PC2
ip 30.0.0.2/8 30.255.255.254

# PC3
ip 172.16.0.1/16 172.16.255.254

# PC4
ip 172.16.0.2/16 172.16.255.254

# PC5
ip 192.168.1.1/24 192.168.1.254

# PC6
ip 192.168.1.2/24 192.168.1.254


### Configuring Routers

# Router1

config t

int f0/0
ip address 20.0.0.1 255.0.0.0
no shutdown
exit

int f0/1
ip address 10.0.0.1 255.0.0.0
no shutdown
exit

int f2/0
ip address 30.255.255.254 255.0.0.0
no shutdown
exit


# Router2

config t

int f0/0
ip address 50.0.0.2 255.0.0.0
no shutdown
exit

int f0/1
ip address 40.0.0.1 255.0.0.0
no shutdown
exit

int f2/0
ip address 172.16.255.254 255.255.0.0
no shutdown
exit


# Router3

config t

int f0/0
ip address 20.0.0.2 255.0.0.0
no shutdown
exit

int f0/1
ip address 50.0.0.1 255.0.0.0
no shutdown
exit


# Router4

config t

int f0/0
ip address 40.0.0.2 255.0.0.0
no shutdown
exit

int f0/1
ip address 10.0.0.2 255.0.0.0
no shutdown
exit

int f2/0
ip address 192.168.1.254 255.255.255.0
no shutdown
exit


### Routing

# Router 1

ip route 172.16.0.0 255.255.0.0 20.0.0.2
ip route 192.168.1.0 255.255.255.0 10.0.0.2


# Router 2

ip route 30.0.0.0 255.0.0.0 50.0.0.1
ip route 192.168.1.0 255.255.255.0 40.0.0.2

# Router 3

ip route 30.0.0.0 255.0.0.0 20.0.0.1
ip route 172.16.0.0 255.255.0.0 50.0.0.2


# Router 4

ip route 30.0.0.0 255.0.0.0 10.0.0.1
ip route 172.16.0.0 255.255.0.0 40.0.0.1


### Pinging

ping 30.0.0.1
ping 30.0.0.2
ping 172.16.0.1
ping 172.16.0.2
ping 192.168.1.1
ping 192.168.1.2

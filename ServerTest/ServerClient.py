import socket

class Client():
    def __init__(self,host,port):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connection = (host,port)

    def send(self,string):
        self.socket.sendall(string.encode())

    def connect(self):
        self.socket.connect(self.connection)
    
    def sendFile(self, filename):
        self.send(filename)
        f = open(filename,'rb')
        l = f.read(1024)
        while(l):
            self.socket.sendall(l)
            l = f.read(1024)
        f.close()


class Server():
    def __init__(self,host,port):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connection = (host,port)
        self.socket.bind(self.connection)
        self.socket.listen()
        self.conn, self.addr = self.socket.accept()
        self.data = b""
    
    def recieve(self):
        while True:
            data = self.conn.recv(1024)
            if not data:
                break
            self.data = data.decode()

    def recieveFile(self):
        self.recieve()
        filename = self.data
        f = open(filename,'wb')
        while True:
            data = self.conn.recv(1024)
            if not data:
                break
            f.write(data)
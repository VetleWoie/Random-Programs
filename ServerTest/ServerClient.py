import socket

class Client():
    def __init__(self,host,port):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connection = (host,port)

    def send(self,string):
        self.socket.sendall(string.encode())

    def connect(self):
        self.socket.connect(self.connection)

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
            self.data = self.conn.recv(1024)
            if not self.data:
                break
            print(self.data)

from ServerClient import Client

HOST = '192.168.1.165'  # The server's hostname or IP address
PORT = 6000        # The port used by the server

client = Client(HOST,PORT)
client.connect()
client.sendFile("test.txt")



import serial
import keyboard


print("Serial Script")

ser = serial.Serial(
    port='\\\\.\\COM8',
    baudrate=31250,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

if ser.isOpen():
    ser.close()
ser.open()
ser.isOpen()

while True:
    print(keyboard.is_pressed("w"))
    if keyboard.is_pressed("w"):
        ser.write("3".encode('utf-8'))
        continue
    if keyboard.is_pressed("s"):
        ser.write(bytes("4", 'utf-8'))
        continue
    if keyboard.is_pressed("a"):
        ser.write(bytes("1", 'utf-8'))
        continue
    if keyboard.is_pressed("d"):
        ser.write(bytes("2", 'utf-8'))
        continue
    ser.write(bytes("5", 'utf-8'))
    

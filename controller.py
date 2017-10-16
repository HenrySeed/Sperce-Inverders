import serial # if you have not already done so
import sys, termios, tty, os, time

ser = serial.Serial('/dev/cu.wchusbserial1420', 9600)

def getch():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)

    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch

button_delay = 0.01

while True:
    char = getch()

    if char == 'r':
        break
    else:
        ser.write(char.encode())

    time.sleep(button_delay)

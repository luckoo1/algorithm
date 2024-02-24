import pyautogui
import time 

while (1):
    time.sleep(60)
    pyautogui.moveTo(100, 200) # x 100, y 200 위치로 바로 이동
    pyautogui.moveTo(100, 400, 2) # x 100, y 200 위치로 2초동안 이동
    
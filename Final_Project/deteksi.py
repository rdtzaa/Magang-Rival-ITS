import cv2
import numpy as np
import sys
import time
# from pyzbar.pyzbar import decode
import serial
from ultralytics import YOLO

model = YOLO('data/best_3.pt').to(device='cuda')

arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)
time.sleep(2)

value_temp = None
tes_value = None
direction = '0'

# def send_direction(direction):
#     print(direction)
#     arduino.write(direction.encode())
#     time.sleep(0.02)
#     # data = arduino.readline()
#     # print(data)

last_sent_time = 0
delay_time = 1

def send_direction(direction):
    global last_sent_time
    current_time = time.perf_counter()
    
    if current_time - last_sent_time >= delay_time and direction != '6':
        print(direction)
        arduino.write(direction.encode())
        last_sent_time = current_time
    else:
        arduino.write(direction.encode()) 

def olah_direction(frame, bound_box, min_area=22000):
    center = (355, 347)
    status = (bound_box[0] + bound_box[2] // 2, bound_box[1] + bound_box[3] // 2)
    cv2.line(frame, center, status, (0,255,0), 2)
    
    if status[0] > center[0] + 13 :
        # print("Gerak roda kanan (arah kanan)")
        return '4'
    elif status[0] < center[0] - 13:
        # print("Gerak roda kiri (arah kiri)")
        return '3'
    elif bound_box[2] * bound_box[3] > min_area + 12000 and status[1] < center[1] - 15:
        # print("Trial cocokkan dengan arm (mundur)")
        return '2'
    elif bound_box[2] * bound_box[3] < min_area or status[1] > center[1] + 15:
        # print("Trial cocokkan dengan arm (maju)")
        return '1'
    else: 
        # print("Diam")
        send_direction('6')
        return '0'
    
def olah_direction_qr(frame, bound_box, min_area=22000):
    center = (150, 347)
    status = (bound_box[0] + bound_box[2] // 2, bound_box[1] + bound_box[3] // 2)
    cv2.line(frame, center, status, (0,255,0), 2)

    
    if status[0] > center[0] + 53:
        # print("Gerak roda kanan (arah kanan)")
        return '4'
    elif status[0] < center[0] - 53:
        # print("Gerak roda kiri (arah kiri)")
        return '3'
    elif bound_box[2] * bound_box[3] > min_area + 12000:
        # print("Trial cocokkan dengan arm (mundur)")
        return '2'
    elif bound_box[2] * bound_box[3] < min_area + 2500:
        # print("Trial cocokkan dengan arm (maju)")
        return '1'
    else: 
        # print("Diam")
        return 'a'
        

def buat_kotak(frame, result, target_class):
    global direction
    bbox = result[0].boxes.xyxy
    class_ids = result[0].boxes.cls
    confidences = result[0].boxes.conf
    valid_detection = False
    for i, box in enumerate(bbox):
        x_min, y_min, x_max, y_max = box
        confidence = confidences[i]
        class_id = int(class_ids[i])
        if confidence > 0.5 and class_id == target_class:
            valid_detection = True
            cv2.rectangle(frame, (int(x_min), int(y_min)), (int(x_max), int(y_max)), (0,255,0), 2)
            x, y, w, h = int(x_min), int(y_min), int(x_max - x_min), int(y_max - y_min)
            cv2.putText(frame, f'Area: {w * h}, {x + w//2}, {y + h//2}', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
            rect = (x, y, w, h)
            direction = olah_direction(frame, rect)
            send_direction(direction)
    
    if not valid_detection:
        direction = '5'
        print('aku')
        send_direction(direction)

    cv2.imshow('Man Hunter', frame)

def data_qr(frame):
    qr_decoder = cv2.QRCodeDetector()
    
    decoded_info, points, straight_qrcode = qr_decoder.detectAndDecode(frame)
    cv2.imshow('Man Hunter', frame)

    if decoded_info:
        print(decoded_info)
        return decoded_info
    else:
        return None

def cari_qr(frame, target):
    qr_detector = cv2.QRCodeDetector()
    decode_info, points, straight_code = qr_detector.detectAndDecode(frame)
    print('qr')
    if decode_info == target:
        for pts in points:
            x_min, y_min = pts[0]
            x_max, y_max = pts[2]
            x, y, w, h = int(x_min), int(y_min), int(x_max - x_min), int(y_max - y_min)
            rect = (x, y, w, h)
            direction = olah_direction_qr(frame, rect)
            send_direction(direction)
    else:
        send_direction('5')


    cv2.imshow('Man Hunter', frame)

cap = cv2.VideoCapture(0)

mode_angkat = False
is_value = False

while True:
    ret, frame = cap.read()
    if not ret:
        break

    
    
    # detect_and_display_color(frame)
    # if tes_value:
    #     results = model.predict(frame)
    #     buat_kotak(frame, results, tes_value)
    # else:
    #     tes_value = data_qr(frame)
    # results = model.predict(frame)
    # buat_kotak(frame, results)
    # cv2.rectangle(frame, (370 + 10, 260+10), (370 + 10, 260 - 10), (0, 255, 0), 2)


    if value_temp == None:
        value = data_qr(frame)
        if value == 'PENJARA PUTIH':
            value_temp = 1
            is_value = True
            time.sleep(4)
        elif value == 'PENJARA BIRU':
            is_value = True
            value_temp = 0
            time.sleep(4)


    if is_value and not mode_angkat:
        mode_angkat = False
        results = model.predict(frame)
        buat_kotak(frame, results, value_temp)
        if direction == '0':
            # results = model.predict(frame)
            # buat_kotak(frame, results, value_temp)
            # if direction == '0':
            #     direction = '6'
            mode_angkat = True
            print('Berhasil Angkat')
            send_direction('6')
    elif is_value and mode_angkat:
        cari_qr(frame, value)
        print(value)
        if direction == 'a':
            cari_qr(frame, value_temp)
            if direction == 'a':
                # time.sleep(5)
                direction = '6'
                send_direction(direction)
                # time.sleep(5)
                break

    cv2.imshow('Man Hunter', frame)
    

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

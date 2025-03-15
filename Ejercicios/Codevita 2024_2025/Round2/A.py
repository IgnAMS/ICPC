n = int(input())


def time_to_number(time):
    numero = 0
    hora = int(time.split(':')[0])
    minuto = int(time.split(':')[1][:2])
    if "PM" in time and hora == 12:
        numero = hora * 60 + minuto
        
    elif "PM" in time:
        numero = (hora + 12) * 60 + minuto
    
    elif "AM" in time and hora == 12:
        numero = (hora - 12) * 60 + minuto
    
    elif "AM" in time:
        numero = hora * 60 + minuto
        
    return numero

# dado un id guarda la informacion list of [event, place, hour] 
last_data = dict()
worked_hours = dict()
inconsistent = False

Events = []
for i in range(n):
    linea = input().split(' ')
    id_number = int(linea[0])
    event = linea[1]
    place = linea[2]
    hora = time_to_number(linea[3])
    Events.append([id_number, event, place, hora])
    
Events.sort(key=lambda x: x[3])
suspect = int(input())
worked_hours[suspect] = 0

for id_number, event, place, hora in Events:
    # print([id_number, event, place, hora])
    if id_number not in last_data.keys() and event != "enters":
        # empty -> exit
        inconsistent = True
        
    if id_number in last_data.keys() and event == last_data[id_number][0]:
        # exit -> exit 
        # enters -> enters
        inconsistent = True
        
    if id_number in last_data.keys() and last_data[id_number][0] == "enters" and last_data[id_number][1] != place:
        # enters place1 -> exit place2
        inconsistent = True
    
    if id_number in last_data.keys() and last_data[id_number][0] == "enters" and event == "exits" and "room" in place:
        if id_number not in worked_hours.keys():
            worked_hours[id_number] = 0
        worked_hours[id_number] += hora - last_data[id_number][2]

    last_data[id_number] = [event, place, hora]

# for worker, time in worked_hours.items():
#     print(worker, time)

for id_number in last_data.keys():
    if last_data[id_number][0] == "enters":
        inconsistent = True

if inconsistent or suspect not in worked_hours.keys():
    print("Cannot be determined")
elif worked_hours[suspect] == min(worked_hours.values()):
    print("Yes")
else:
    print("No")

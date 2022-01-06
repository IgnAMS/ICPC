import random
nombres=['rorro','zarco','eug','nano']
for i in range(4):
    random.shuffle(nombres)
    if(i==2):
        print()
    if(i<2):
        print('equipo1: ',nombres[0])
        nombres.remove(nombres[0])
    else:
        print('equipo2: ',nombres[0])
        nombres.remove(nombres[0])
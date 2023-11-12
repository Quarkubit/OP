import folium
from geopy.geocoders import Nominatim
from datetime import datetime, timedelta

nominaltim = Nominatim(user_agent='user')
m= folium.Map(location=[55.753732, 37.621070],zoom_start=10)

def parse_time_window(time_window):
    begin_time, end_time = time_window.split('-')
    if '.'in begin_time:
        begin_time = datetime.strptime(begin_time, '%H.%M')
    else:
        begin_time+='.00'
        begin_time = datetime.strptime(begin_time, '%H.%M')
    if '.'in end_time:
        end_time = datetime.strptime(end_time, '%H.%M')
    else:
        end_time+='.00'
        end_time = datetime.strptime(end_time, '%H.%M')
    return begin_time, end_time

def group_addresses(addresses):
    early_group = []
    standart_group = []
    late_group = []

    for address in addresses:
        db_address, time_window = address
        if time_window!='24' and time_window!='0':
            begin_time, end_time = parse_time_window(time_window)
        elif time_window=='0':
            standart_group.append(db_address)
            continue
        else:
            early_group.append(db_address)
            late_group.append(db_address)
            continue

        if end_time <= datetime.strptime('13.00', '%H.%M'):
            early_group.append(db_address)
        elif end_time <= datetime.strptime('18.00', '%H.%M'):
            standart_group.append(db_address)
        else:
            late_group.append(db_address)

    return early_group, standart_group, late_group

def spliter(n):
    a, b=n.split('!')
    return [a,b]

addresses = []

print('\nВведите адрес(через , без пробелов) и через ! временное окно(через дефис в формате часы.минуты-часы.минуты)\n\t---для круглосуточного адреса введите 24---\n\t---для адреса без временного окна введите 0---\n\nПример:\nМосковский Кремль, Чудовская улица, 18, 19, Тверской район, Москва, Россия!24\n\n\t  !введите 0 для конца записи!\n')
counter=0
while 1:
    x=input()
    if x == '0':
        break
    counter+=1
    x=spliter(x)
    addresses.append(x)
print('\n-------------------------')

early_group, standart_group, late_group = group_addresses(addresses)

#добавить разный цвет/иконки маркерам
print('Ранняя группа:')
for address in early_group:
    location=nominaltim.geocode(address).raw
    coordinates=[]
    coordinates.append(float(location['lat']))
    coordinates.append(float(location['lon']))
    tooltip=address
    folium.Marker(coordinates, tooltip=tooltip).add_to(m)
    print(address)

print('\nСтандартная группа:')
for address in standart_group:
    location=nominaltim.geocode(address).raw
    coordinates=[]
    coordinates.append(float(location['lat']))
    coordinates.append(float(location['lon']))
    tooltip=address
    folium.Marker(coordinates, tooltip=tooltip).add_to(m)
    print(address)

print('\nПоздняя группа:')
for address in late_group:
    location=nominaltim.geocode(address).raw
    coordinates=[]
    coordinates.append(float(location['lat']))
    coordinates.append(float(location['lon']))
    tooltip=address
    folium.Marker(coordinates, tooltip=tooltip).add_to(m)
    print(address)

m.save('programms/tier-adresser/tier_map.html')
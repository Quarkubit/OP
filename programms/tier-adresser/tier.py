from datetime import datetime, timedelta

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
    late_group = []
    indefinite_group = []

    for address in addresses:
        db_address, time_window = address
        if time_window!='24':
            begin_time, end_time = parse_time_window(time_window)
        else:
            early_group.append(db_address)
            indefinite_group.append(db_address)
            continue

        if end_time <= datetime.strptime('13.00', '%H.%M'):
            early_group.append(db_address)
        elif end_time <= datetime.strptime('18.00', '%H.%M'):
            late_group.append(db_address)
        else:
            indefinite_group.append(db_address)

    return early_group, late_group, indefinite_group

def spliter(n):
    a, b=n.split(' ')
    return [a,b]

addresses = []

print('Введите адрес и через пробел временное окно(через дефис в формате часы.минуты-часы.минуты)\n\t(для круглосуточного адресса введите 24)\n\t!!!минуты указывать обезательно!!!\n\t  !введите 0 для конца записи!\n')
while 1:
    x=input()
    if x == '0':
        break
    x=spliter(x)
    addresses.append(x)
print('\n-------------------------\n')

early_group, late_group, indefinite_group = group_addresses(addresses)

print('Ранняя группа:')
for address in early_group:
    print(address)

print('\nСтандартная группа:')
for address in late_group:
    print(address)

print('\nпоздняя группа:')
for address in indefinite_group:
    print(address)
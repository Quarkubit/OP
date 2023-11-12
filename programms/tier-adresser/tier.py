from datetime import datetime, timedelta

def parse_time_window(time_window):
    if time_window == '24':
        begin_time, end_time='0.00-23.59'.split('-')
        begin_time = datetime.strptime(begin_time, '%H.%M')
        end_time = datetime.strptime(end_time, '%H.%M')
        return begin_time, end_time
    begin_time, end_time = time_window.split('-')
    begin_time = datetime.strptime(begin_time, '%H.%M')
    end_time = datetime.strptime(end_time, '%H.%M')
    return begin_time, end_time

def group_addresses(addresses):
    early_group = []
    late_group = []
    indefinite_group = []

    for address in addresses:
        db_address, time_window = address
        begin_time, end_time = parse_time_window(time_window)

        if end_time <= datetime.strptime('13.00', '%H.%M'):
            early_group.append(db_address)
        elif end_time <= datetime.strptime('20.00', '%H.%M'):
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

early_group, late_group, indefinite_group = group_addresses(addresses)

print('Ранняя группа:')
for address in early_group:
    print(address)

print('\nПоздняя группа:')
for address in late_group:
    print(address)

print('\nБессрочная группа:')
for address in indefinite_group:
    print(address)
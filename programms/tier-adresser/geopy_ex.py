from geopy.geocoders import Nominatim
from pprint import pprint


#получение координат

nominaltim = Nominatim(user_agent='user')

location = nominaltim.geocode('Московский Кремль, Чудовская улица, 18, 19, Тверской район, Москва, Россия').raw

pprint(location)

print(location['lat']+', '+location['lon'])


#извлечение из координат адреса

coordinates = '55.751111244682804, 37.617843455497336'

location1 = nominaltim.reverse(coordinates)
print(location1)
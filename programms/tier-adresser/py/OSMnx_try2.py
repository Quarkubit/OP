import osmnx as ox
 
# Задаем границы для построения маршрута
#north, west, south, east = 56.24, 36.79, 55.29, 38.68
place = 'Москва, Россия'
mode = 'walk' # 'drive', 'bike', 'walk'
optimizer = 'time' # 'length','time'
print('\n\n\n1\n\n\n')
# Загружаем граф дорожной сети
#G = ox.graph_from_bbox(north, south, east, west, network_type='all')
G = ox.graph_from_place(place, network_type = mode)
print('\n\n\n2\n\n\n')
# Визуализация графа дорожной сети
ox.plot_graph(G)
print('\n\n\n3\n\n\n')
# Находим геокоды для начальной и конечной точек
origin = ox.geocode('пл. Революции, Москва, Россия')
destination = ox.geocode('Москворецкая наб., Москва, Россия')
print('\n\n\n4\n\n\n')
# Находим ближайшие узлы на графе
origin_node = ox.nearest_nodes(G, origin[1], origin[0])
destination_node = ox.nearest_nodes(G, destination[1], destination[0])
print('\n\n\n5\n\n\n')
# Строим кратчайший путь на основе заданной карты
route = ox.shortest_path(G, origin_node, destination_node, weight='length')
print('\n\n\n6\n\n\n')
# Визуализация маршрута на заданной карте
ox.plot_graph_route(G, route)
print('\n\n\n7\n\n\n')
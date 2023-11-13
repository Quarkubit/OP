import osmnx as ox
 
# Задаем границы для построения маршрута
north, south, east, west = 56.24, 36.79, 55.29, 38.68

# Загружаем граф дорожной сети
G = ox.graph_from_bbox(north, south, east, west, network_type='all')

# Визуализация графа дорожной сети
ox.plot_graph(G)

# Находим геокоды для начальной и конечной точек
origin = ox.geocode('пл. Революции, Москва, Россия')
destination = ox.geocode('Москворецкая наб., Москва, Россия')

# Находим ближайшие узлы на графе
origin_node = ox.nearest_nodes(G, origin[1], origin[0])
destination_node = ox.nearest_nodes(G, destination[1], destination[0])

# Строим кратчайший путь на основе заданной карты
route = ox.shortest_path(G, origin_node, destination_node, weight='length')

# Визуализация маршрута на заданной карте
ox.plot_graph_route(G, route)
import osmnx as ox
import networkx as nx

ox.settings.log_console=True
ox.settings.use_cache=True

# define the start and end locations in latlng
start_latlng = (55.751111244682804, 37.617843455497336)
end_latlng = (55.74998356645684, 37.617001324422745)

# location where you want to find your route
place = 'Москва, Россия'

# find shortest route based on the mode of travel
mode = 'walk' # 'drive', 'bike', 'walk'

# find shortest path based on distance or time
optimizer = 'time' # 'length','time'

print('\n\n\n\t---get road info---\n\n\n')

# create graph from OSM within the boundaries of some 
# geocodable place(s)
graph = ox.graph_from_place(place, network_type = mode)

print('\n\n\n\t---search origin node---\n\n\n')

# find the nearest node to the start location
orig_node = ox.nearest_nodes(graph, start_latlng[0], start_latlng[1])

print('\n\n\n\t---search destanation node---\n\n\n')

# find the nearest node to the end location
dest_node = ox.nearest_nodes(graph, end_latlng[0], end_latlng[1])

print('\n\n\n\t---finding shortest route---\n\n\n')

# find the shortest path
shortest_route = nx.shortest_path(graph, orig_node,dest_node, weight=optimizer)

print('\n\n\n\t---start ploting---\n\n\n')

ox.graph_to_gdfs(G, nodes=False).explore()

print('\n\n\n\t---end---\n\n\n')
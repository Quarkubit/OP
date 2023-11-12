import folium

m= folium.Map(location=[55.753732, 37.621070],zoom_start=10)

tooltip='РТУ МИРЭА'
tooltip_2='Центр'
comment='Лучший институт москвы'
comment_2='Центр Москвы'

folium.Marker([55.66999523743406, 37.48029973770085],popup=comment, tooltip=tooltip).add_to(m)
folium.Marker([55.753732, 37.621070],popup=comment_2, tooltip=tooltip_2).add_to(m)

m.save('programms/tier-adresser/folium_ex.html')

#55.740739, 37.861690   дом
#55.753732, 37.621070   центр
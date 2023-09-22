import matplotlib.pyplot as plot
import numpy as np

distancias = []
with open("Generated/2000.txt") as file:
    for num in file:
        distancias.append(float(num))
intervalos = np.arange(min(distancias), max(distancias) + 0.1, 0.2)

plot.hist(x=distancias, bins=intervalos, color='#F2AB6D', rwidth=0.8)
plot.title('Histograma de las distancias entre puntos de dimension 2000')
plot.xlabel('Distancia')
plot.ylabel('Frecuencia')
plot.xticks(intervalos)

plot.show() #dibujamos el histograma
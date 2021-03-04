#\file heightMapGenerator.py
#\author Marc MOUTARDE
#\brief fichier permetant de séparer une carte de mars en petites images de 64*64 pixels

from PIL import Image

source = Image.open("map.jpg")
sourcePixelMap = source.load()
print(source.size)

destination = "bin/res/height/"
width = 64
height = 64

startX = 204
startY = 385

sourceWidth = 11520
sourceHeight = 6400

iterationLargeur = int(sourceWidth/(width-2))
iterationHauteur = int(sourceHeight/(height-2))

print("Nombre images largeur:", iterationLargeur)
print("Nombre images hauteur:", iterationHauteur)

meridiens = [i for i in range(524, 11724, 320)]
parallelles = [i for i in range(402, 6400, 767)]

def getPixelColor(posX, posY):
	for x in meridiens:
		if(x == posX):
			return (int((sourcePixelMap[posX-1, posY][0]+sourcePixelMap[posX+1, posY][0])/2),\
					int((sourcePixelMap[posX-1, posY][1]+sourcePixelMap[posX+1, posY][1])/2),\
					int((sourcePixelMap[posX-1, posY][2]+sourcePixelMap[posX+1, posY][2])/2))
	for y in parallelles:
		if(y == posY):
			return (int((sourcePixelMap[posX, posY-1][0]+sourcePixelMap[posX, posY+1][0])/2),\
					int((sourcePixelMap[posX, posY-1][1]+sourcePixelMap[posX, posY+1][1])/2),\
					int((sourcePixelMap[posX, posY-1][2]+sourcePixelMap[posX, posY+1][2])/2))
	return sourcePixelMap[posX, posY]

for x in range(0, iterationHauteur):
	for y in range(0, iterationLargeur):
		image = Image.new('RGB', (width, height))
		pixMap = image.load()

		for posX in range(0, width):
			for posY in range(0, height):
				pixMap[posX, posY] = getPixelColor(startX+y*(width-1)+posX, startY+x*(height-1)+posY)

		imgName = destination + "carte_" + str(x) + "_" + str(y) + ".jpeg"
		image.save(imgName, "JPEG")

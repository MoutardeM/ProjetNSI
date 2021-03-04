#Carte de Mars
***
Projet de NSI représentant mars en 3D avec un éclairage calculer par shader OpenGL

#Informations
##Dépendances

 * [GLFW](https://www.glfw.org):3.3.2 Bibliothèques de création de fenetre multiplateforme
 * [GLEW](http://glew.sourceforge.net/):2.1.0 Bibliothèque de chargement d'extentions OpenGL
 * [STB IMAGES](https://github.com/nothings/stb):2.26 Bibliothèque de décodage d'images
***

##Carte globale de mars
Genérée par les données du MOLA (Mars Orbiter Laser Altimeter) du MOLA Science Team et de la NASA (National Aéronautics and Space Administration)
Site web source: https://attic.gsfc.nasa.gov/mola/images.html
***

##Compilation et utilsation du programme
 1) Télécharger et installer les dépendances exepter STB IMAGE qui est dans le dossier 3rd_part
 2) éxecuter cmake
 3) compilez
 4) executez avec python heightMapGenerator.py qui sépare le fichier map.jpg en plus petits fichiers
 5) executez le programme.

##Documentation
 Sous linux:
 	Executez doxygen documentation

##Bug
 * La séparation entre les différentes images est visibles par un décalage du maillage
 * La séparation entre les différentes images est marquée par un petit dégradé en noire du a l'assimilation à 0 de la normal de bord +1

##Reste à implémenter
 * Cicles jours-nuit simulant une rotation de la planète par le mouvenement de la source de lumière
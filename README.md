# TETRIS

Il s’agit d’implanter complètement le jeu TETRIS et d’étendre ce jeu à de nouvelles variantes soit en implantant la possibilité d’un jeu multijoueurs.

## Introduction

Nous avons choisi le framework Qt pour créer un jeu de Tetris en ligne pour plusieurs raisons. 

Voici quelques-uns des principaux avantages de l'utilisation de Qt dans ce contexte :

* _Portabilité_ : Qt est un framework multiplateforme qui permet de créer des applications fonctionnant sur différents systèmes d'exploitation, tels que Windows, macOS, Linux, Android et iOS. Cela signifie que notre jeu de Tetris en ligne sera facilement accessible par un large éventail d'utilisateurs, quelle que soit leur plateforme préférée.

* _Facilité d'utilisation_ : Qt est réputé pour sa facilité d'utilisation et sa courbe d'apprentissage relativement douce. Pour les étudiants qui n'ont pas beaucoup d'expérience en développement logiciel, cette accessibilité est un énorme avantage. De plus, Qt offre une documentation complète et une grande communauté d'utilisateurs, ce qui facilite l'apprentissage et la résolution de problèmes.

* _Bibliothèques intégrées_ : Qt offre de nombreuses bibliothèques intégrées pour le développement d'applications, notamment pour la gestion des fenêtres, les graphismes 2D et 3D, les widgets, le réseau et la gestion des événements. Cela permet aux étudiants de se concentrer sur la logique du jeu et la conception plutôt que de passer du temps à rechercher et intégrer des bibliothèques externes.

* _Outils de développement_ : Qt propose un environnement de développement intégré (IDE) appelé Qt Creator, qui facilite la création, le débogage et la maintenance du code. Qt Creator offre également un éditeur graphique pour la conception d'interfaces utilisateur, permettant aux étudiants de créer rapidement des interfaces attrayantes et fonctionnelles pour leur jeu de Tetris en ligne.

* _Performance_ : Qt est optimisé pour offrir de bonnes performances, ce qui est essentiel pour le développement de jeux. Le framework utilise le C++ natif, ce qui permet d'obtenir un code rapide et efficace. De plus, Qt supporte OpenGL, ce qui facilite l'accélération matérielle et garantit que le jeu fonctionne de manière fluide sur différents appareils.

* _Licence_: Qt est disponible sous une licence open source (LGPL) pour les projets non commerciaux, ce qui le rend adapté aux projets étudiants sans engendrer de coûts supplémentaires.

En somme, Qt est un excellent choix pour créer un jeu de Tetris en ligne dans le cadre d'un projet étudiant en raison de sa portabilité, de sa facilité d'utilisation, de ses bibliothèques intégrées, de ses outils de développement, de ses performances et de sa licence adaptée aux projets non commerciaux.

### Ce jeu présente les caractéristiques suivantes:

* _Customizable gameplay_, avec plusieurs modes de jeu
  plusieurs modes de jeu : sigleplayer, multiplayer.
* _Multijoueur_ : jusqu'à 8 joueurs,jouer en parallèle avec des amis.
* _Statistiques de jeu_ : lignes effacées, score individuel
* _Interface colorée_...




## Structure

Le jeu contient deux modules : le _serveur_ et le _jeu principal_.


### Ce projet montre comment créer un jeu simple :

* _La classe TetrisWindow_ est utilisée pour afficher le score du joueur, le nombre de vies et des informations sur la prochaine pièce à apparaître.

* _La classe TetrisBoard_ contient la logique du jeu, gère les saisies au clavier et affiche les pièces sur l'aire de jeu.

* _La classe Tetrominoclass_ contient des informations sur chaque pièce.

* _la classe MultiplayerBlock_ est utilisée pour gérer la connexion, la communication et l'affichage des joueurs dans un jeu de Tetris en ligne. La classe hérite de QWidget, ce qui permet d'intégrer facilement MultiplayerBlock dans une interface utilisateur Qt.

* _La classe playerwidget_ contient des informations sur joueur.

* _La classe MainMenu_ est utilisée pour gérer le menu principal de l'interface utilisateur d'un jeu de Tetris. Elle hérite de _QMainWindow_ et utilise un fichier d'interface utilisateur (UI) pour définir l'apparence et la disposition des éléments du menu.


Dans cette approche, la classe _TetrisBoard_ est la plus complexe, car elle gère la logique du jeu et le rendu. 



## Screenshots

![main-menu](images\main_menu.jpg)


![single-player](images\singleplayer.jpg)


![multiplayer:player1](/images/player1.jpg)

![multiplayer:player2](/images/player2.jpg)

![multiplayer:player3](/images/player3.jpg)

![multiplayer:player4](/images/player4.jpg)

## Controls

| Key         | Action                                    |
| ----------- | ----------------------------------------- |
| Left, Right | Controls the piece                        |
| Down        | Soft-drop                                 |
| Space       | Hard-drop                                 |
| c           | Holds the piece                           |
| Up/Shift    | Rotates piece counter-clockwise/clockwise |


## Dependencies



## Usage







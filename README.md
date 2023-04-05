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

## Multiplayer
Nous avons choisi d'utiliser une connexion TCP pour plusieurs raisons, qui sont principalement liées aux caractéristiques inhérentes du protocole TCP et à sa pertinence pour les applications de jeu en ligne comme Tetris.

* _Fiabilité_ : Le protocole TCP est un protocole orienté connexion, ce qui signifie qu'il établit une connexion fiable entre les deux parties avant de commencer la communication. Il garantit que les données envoyées par une partie seront reçues par l'autre partie dans le bon ordre et sans erreurs. Cette fiabilité est cruciale pour les jeux en ligne, car elle permet de s'assurer que toutes les actions des joueurs sont correctement transmises et synchronisées entre les clients et le serveur.

* _Contrôle de flux_ : TCP implémente un mécanisme de contrôle de flux qui ajuste automatiquement la vitesse à laquelle les données sont envoyées en fonction de la capacité du réseau et du récepteur. Cela permet d'éviter l'engorgement du réseau et garantit que les clients et le serveur communiquent de manière efficace, ce qui est important pour maintenir une expérience de jeu fluide et réactive.

* _Gestion de la congestion_ : TCP dispose également d'une gestion intégrée de la congestion qui permet d'éviter l'encombrement du réseau en ajustant la vitesse de transmission des données en fonction des conditions du réseau. Cette fonctionnalité contribue à maintenir une latence faible et une expérience de jeu de qualité, même lorsque le réseau est encombré.

* _Facilité d'utilisation_ : TCP est largement utilisé et bien documenté, ce qui facilite son implémentation et sa maintenance. De plus, les API et les bibliothèques de programmation, telles que Qt, fournissent des abstractions de haut niveau pour travailler avec TCP, simplifiant encore le développement d'applications basées sur ce protocole.

En somme, le choix d'une connexion TCP pour notre jeu Tetris en ligne repose sur la fiabilité, le contrôle de flux, la gestion de la congestion et la facilité d'utilisation offerts par ce protocole. Ces caractéristiques sont essentielles pour assurer une expérience de jeu en ligne de qualité et un échange de données efficace entre les clients et le serveur.

### La connexion entre le serveur et le bloc multijoueur fonctionne de la manière suivante:

* Dans la classe _MultiplayerBlock_, un objet QTcpSocket est créé pour établir une connexion au serveur. Le socket est connecté à l'hôte (serveur) en utilisant l'adresse IP (hostname) et le port spécifiés. Une fois la connexion établie, des signaux sont connectés aux slots appropriés. Le signal readyRead est connecté au slot slotReadyRead, qui est déclenché lorsque des données sont disponibles pour être lues depuis le serveur. Le signal disconnected est connecté au slot deleteLater qui supprime le socket lorsqu'il est déconnecté.

* Dans _la classe Server_, la méthode incomingConnection est appelée chaque fois qu'un nouveau client tente de se connecter au serveur. Cette méthode crée un nouveau socket pour le client, en utilisant le descripteur de socket reçu. Le serveur connecte également les signaux aux slots appropriés pour gérer les données entrantes. Le signal readyRead est connecté au slot slotReadyRead qui lit les données envoyées par les clients et les diffuse à tous les autres clients connectés.

Lorsque des données sont disponibles pour être lues dans le bloc multijoueur, la méthode slotReadyRead est déclenchée. Les données sont extraites du flux, et le score et le pseudo du joueur sont mis à jour en fonction des données reçues. Si un nouveau joueur se connecte, un nouveau widget est créé pour ce joueur, et il est ajouté à la liste des joueurs.

De manière similaire, lorsque le serveur reçoit des données d'un client, la méthode slotReadyRead est déclenchée. Les données sont extraites et envoyées à tous les clients connectés via la méthode SendToClient.


## Screenshots

![main-menu](/images/main_menu.jpg)


![single-player](/images/singleplayer.jpg)


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

## How to compile:
### Étapes pour compiler et exécuter le projet
* Installer les outils de développement Qt : Assurez-vous d'avoir installé les outils de développement Qt sur votre système. Vous pouvez les télécharger à partir du site officiel de Qt : https://www.qt.io/download
* Exécuter qmake : Exécutez la commande qmake pour générer le fichier Makefile à partir du fichier de projet .pro. Si vous utilisez une version spécifique de Qt, vous devrez peut-être spécifier le chemin complet vers l'exécutable qmake.
* Compiler le projet : Compilez le projet en utilisant la commande make (ou nmake sur Windows avec Visual Studio). Ceci va compiler le code source et créer l'exécutable du projet.
* Exécuter l'application 









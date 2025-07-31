# Cub3D 🎮

Cub3D vous fait revivre l'Histoire du jeu vidéo en implémentant les techniques utilisées par les légendaires John Carmack et John Romero d'ID Software. Vous devrez créer une représentation graphique 3D "réalistique" d'un labyrinthe en utilisant une vue subjective et les principes du ray-casting.

### Objectifs du Projet

- **Rigueur et algorithmes** : Utilisation du C et d'algorithmes basiques
- **Design graphique** : Travail sur les fenêtres, couleurs, événements, formes
- **Mathématiques appliquées** : Exploration pratique sans nécessiter une compréhension théorique approfondie
- **Ray-casting** : Implémentation de cette technique révolutionnaire des années 90

## 🎯 Partie Obligatoire

### Spécifications Techniques

**Programme :** `cub3D`  
**Arguments :** Une map au format `*.cub`  
**Compilation :** `make all`, `clean`, `fclean`, `re`, `bonus`

### Fonctions Externes Autorisées
- **Système :** `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`
- **Mathématiques :** Toutes les fonctions de la lib math (`-lm`)
- **Graphique :** Toutes les fonctions de la MinilibX
- **Libft :** Autorisée

### Fonctionnalités Obligatoires

#### Affichage et Rendu
- Vue 3D réaliste avec ray-casting
- Textures différentes selon l'orientation des murs (Nord, Sud, Est, Ouest)
- Couleurs personnalisables pour le sol et le plafond
- Gestion parfaite des fenêtres (minimisation, changement de focus, etc.)

#### Contrôles
- **Flèches gauche/droite** : Rotation de la caméra
- **W, A, S, D** : Déplacement du personnage
- **ESC** : Fermer le programme proprement
- **Croix rouge** : Fermer le programme proprement

#### Format de Map (.cub)

**Éléments de configuration :**
```
NO ./path_to_the_north_texture    # Texture Nord
SO ./path_to_the_south_texture    # Texture Sud  
WE ./path_to_the_west_texture     # Texture Ouest
EA ./path_to_the_east_texture     # Texture Est
F 220,100,0                       # Couleur sol (R,G,B)
C 225,30,0                        # Couleur plafond (R,G,B)
```

**Caractères de map :**
- `0` : Espace vide
- `1` : Mur
- `N`, `S`, `E`, `W` : Position et orientation de départ du joueur

**Exemple de map valide :**
```
111111
100101
101001
1100N1
111111
```

### Règles de Map
- La map doit être fermée/entourée de murs
- Description de la carte toujours en dernier dans le fichier
- Espaces valables dans la carte
- Gestion d'erreur avec message "Error\n" + description explicite

## 🌟 Partie Bonus

**⚠️ Les bonus ne sont évalués que si la partie obligatoire est PARFAITE !**

### Liste des Bonus Disponibles
- **Collision contre les murs**
- **Système de minicarte**
- **Portes ouvrables/fermables**
- **Animations (sprites animés)**
- **Rotation avec la souris**

### Liberté Créative
- Utilisation d'autres fonctions autorisée
- Ajout de symboles sur la carte
- Modification du format de fichier de scène
- Soyez intelligent dans vos choix !

## 🛠️ Installation et Compilation

### Prérequis
- Compilateur C (gcc/clang)
- MinilibX installée
- Make

### Compilation
```bash
make                 # Compile le projet
make clean          # Nettoie les fichiers objets
make fclean         # Nettoie tout
make re             # Recompile tout
make bonus          # Compile avec les bonus
```

### Utilisation
```bash
./cub3D maps/example.cub
```

## 📁 Structure du Projet

```
cub3d/
├── src/
│   ├── main.c
│   ├── init.c
│   ├── draw.c
│   ├── exit_error.c
│   ├── movements.c
│   ├── ray.c
│   ├── pov_handler.c
│   ├── render.c
│   ├── textures.c
│   └── utils.c
├── includes/
│   └── cub3d.h
├── maps/
│   └── *.cub
├── textures/
│   └── *.xpm
├── libft/
├── minilibx-linux/
├── gnl/
├── Makefile
└── README.md
```

## 🎮 Exemples Visuels

Le projet doit produire un rendu similaire à Wolfenstein 3D original :
- Perspective en première personne
- Murs texturés selon leur orientation
- Sol et plafond colorés
- Navigation fluide dans le labyrinthe

### Rendu Attendu
- **Vue 3D** avec effet de profondeur
- **Textures murales** différenciées
- **Interface** simple et efficace
- **Performance** fluide

## 🔧 Concepts Techniques

### Ray-Casting
- Projection de rayons depuis la position du joueur
- Calcul des distances aux murs
- Détermination de la hauteur des colonnes à afficher
- Application des textures selon l'orientation

### Gestion des Événements
- Capture des inputs clavier/souris
- Mise à jour de la position et orientation
- Rafraîchissement de l'affichage

### Parsing de Map
- Lecture et validation du fichier .cub
- Extraction des paramètres de configuration
- Construction de la grille de jeu
- Gestion d'erreurs robuste

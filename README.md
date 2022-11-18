# projet sokoban
## projet réalisé par :  
Mohamed Yassine Azaza.  
Mohammed Chahbaoui.  

## c'est quoi le sokoban ?
- preview du jeu : 
<div><img src="../img/Sokoban_ani.gif" width="20%"></div>

- lien vers la page wikipedia du jeu : <a href="https://fr.wikipedia.org/wiki/Sokoban">sokoban wikipedia</a>

## comment on a réalisé ce projet ?
- Langague utilisé : langage C
- outils appliqués : Doxygene et un fichier markdown
- La structure de donne optée pour approché le probleme : <div> <ol> <li>
on represente, la grille du sokoban qu'on joue sur, par un tableau unidimensionnel qu'on l'affichera sous forme d'une 
grille double dimension, <br>et deux entiers qui representent les dimensions de la grille.</li> <li>
la grille affichée et d'origine un ficher <b>.txt</b> : <div style="text-align:center"><p><img src="../img/grille.png" width="15%"></p> <p> 
<u><b>legende</b></u> : </p> <p>
'#' représente un mur. </p> <p>
'$' représente un cube. </p> <p>
'@' représente votre personnage. </p> <p>
'.' représente un objectif. (l'endroit ou on doit placer les cubes pour gagner) </p> <p>
' ' représente du vide dans lequel votre personnage et les cubes pourront progresser.</p> </div></li> </ol></div>

- l'extraction de la grille (du fichier .txt) et son affichage : <div> <ol> <li> par la fonction <u>init_level(path, la structure Grid)</u> </li> <li>
par la fonction <u>Display(la structure 'Grid') </li>
</ol></div>
/**
 * @file player.c
 * @author Mohammed chahbaoui et Mohamed yassine azaza.
 * @brief mise à jour de la position de joueur selon la direction entrée.\n
 * 
 */

#include "../include/grid.h"

enum CaseType entite = NONE;// global variable contenent l'entité de la grille que le PLAYER a passé sur. (par defaut NONE)
enum CaseType entite_box = NONE; // global variable contenent l'entité de la grille que le BOX a passé sur. (par defaut NONE)

/**
 * @brief change les coordonnées du joueur selon la direction.\n 
 * 
 * @param grille adresse de la structure Grid.
 * @param dir direction où on va déplacer le joueur.
 * @return renvoie la grille après le changement de la position de joueur et les box.
 */

void move_player(Grid* grille, enum Direction dir){
	int colonne = grille->column_number; // nmbr de colonne de la grille
	int ligne = grille->row_number; // nmbr de ligne de la grille
	int coord_player_1D = (grille->Player).x + (grille->Player).y *  colonne; // les coordonées du Player dans un tableau 1D depuis une grille (2D)
	int boolean = 1; // si boolean affiche la grille sinon rien
	
	
	switch(dir){
		case TOP :{// mouvement en haut décremente le y(en 2D) donc diminue les coord player en 1D par une valeur colonne
			  // d'apres la formule 
			
			// on enleve le joueur de la grille pour le moment 
			grille->game_grid[coord_player_1D] = entite; 
			
			
			// m-a-j des coord (en 1D et 2D)
			(grille->Player).y -=1;
			coord_player_1D -= colonne;
			
			// si on passe par un BOX
			int ou_mettre_box = coord_player_1D - colonne; // ou sera le box apres mvmt
			if (grille->game_grid[coord_player_1D] == BOX && grille->game_grid[ou_mettre_box]!= WALL && grille->game_grid[ou_mettre_box]!= BOX){
				grille->game_grid[coord_player_1D] = entite_box; // on met entite_box a la place du BOX (l'enlever) (entite_box = NONE or GOAL)
				entite_box = grille->game_grid[ou_mettre_box]; // sauvegarde l'entite que le box a passé sur
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}

			// on change l'entité à ce que le joueur a passé sur
			entite = grille->game_grid[coord_player_1D];
			
			// s'assurer de ne pas depasser un murs ou un box (ne pas depasser les boxs === ne pas sortir de la zone
			// puisque la grille est entouré des murs)
			// si on passera sur un WALL OU Entre un WALL (OU un autre BOX) et le joueur y a Box 
			enum CaseType dessus_de_ou_on_vas = grille->game_grid[coord_player_1D - colonne];
			if (grille->game_grid[coord_player_1D] == WALL ||((dessus_de_ou_on_vas == WALL || dessus_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){ 
				// on rechange les coords de tel sort qu'on a rien fait
				(grille->Player).y +=1;
				coord_player_1D += colonne;
				// entite = NONE ou GOAL pas d'autre ,sinon en revient au defaut (NONE)
				entite = NONE;
				//entite_box = NONE;
				boolean = 0; // pour ne pas afficher la grille si on fait un mvmt invalide
				printf("\n!! MOUVEMENT INVALIDE !!\n");
			}
			
			
			// placement du PLayer apres maj des son coord 
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
		}
			
			
		case BOTTOM:{			 

			grille->game_grid[coord_player_1D] = entite; 
			

			(grille->Player).y +=1;
			coord_player_1D += colonne;

			int ou_mettre_box = coord_player_1D + colonne; // ou sera le box apres mvmt
			if (grille->game_grid[coord_player_1D] == BOX && grille->game_grid[ou_mettre_box]!= WALL && grille->game_grid[ou_mettre_box]!= BOX){
				grille->game_grid[coord_player_1D] = entite_box;
				entite_box = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			entite = grille->game_grid[coord_player_1D];

			enum CaseType dessous_de_ou_on_vas = grille->game_grid[coord_player_1D + colonne];
			if (grille->game_grid[coord_player_1D] == WALL || ((dessous_de_ou_on_vas == WALL || dessous_de_ou_on_vas == BOX) && grille->game_grid[coord_player_1D] == BOX)){

				(grille->Player).y -=1;
				coord_player_1D -= colonne;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
		}
			
		case RIGHT:{
			
			grille->game_grid[coord_player_1D] = entite;
			
			(grille->Player).x +=1;
			coord_player_1D += 1;

			int ou_mettre_box = coord_player_1D + 1; // ou sera le box apres mvmt
			if (grille->game_grid[coord_player_1D] == BOX && grille->game_grid[ou_mettre_box]!= WALL && grille->game_grid[ou_mettre_box]!= BOX){
				grille->game_grid[coord_player_1D] = entite_box;
				entite_box = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			entite = grille->game_grid[coord_player_1D];

			enum CaseType right_de_ou_on_vas = grille->game_grid[coord_player_1D +1 ];
			if (grille->game_grid[coord_player_1D] == WALL ||((right_de_ou_on_vas == WALL || right_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){
				(grille->Player).x -=1;
				coord_player_1D -= 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}


			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
		}

		case LEFT:{
		
			grille->game_grid[coord_player_1D] = entite;
			
			(grille->Player).x -=1;
			coord_player_1D -= 1;

			int ou_mettre_box = coord_player_1D - 1; // ou sera le box apres mvmt
			if (grille->game_grid[coord_player_1D] == BOX && grille->game_grid[ou_mettre_box]!= WALL && grille->game_grid[ou_mettre_box]!= BOX){
				grille->game_grid[coord_player_1D] = entite_box;
				entite_box = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			entite = grille->game_grid[coord_player_1D];
			
			enum CaseType left_de_ou_on_vas = grille->game_grid[coord_player_1D - 1];
			if (grille->game_grid[coord_player_1D] == WALL ||((left_de_ou_on_vas == WALL || left_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){
				(grille->Player).x +=1;
				coord_player_1D += 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
		}


		default :{
			printf("\ninvalide key\n");			
		}
	
	}
	// affichage la grille aprés le mvmt	
	if (boolean)		
	display(grille);		   
}

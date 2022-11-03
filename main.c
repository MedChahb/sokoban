#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	Grid grille; 
	init_level("/home/chahbaoui/Desktop/projet_tech_dev/sokoban/level1.txt", &grille); 
	display(&grille);
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'z':
				move_player(&grille, TOP);
				break;
			case 's':
				move_player(&grille, BOTTOM);
				break;
			case 'q':
				move_player(&grille, LEFT);
				break;
			case 'd':
				move_player(&grille, RIGHT);
				break;
			
			case 'x' :{
				run = false;
				break;
			}
		}
	}
	
	
}


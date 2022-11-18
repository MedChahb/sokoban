#include <stdio.h>
#include "../include/grid.h"
#include <stdbool.h>
#include <ctype.h>

int main(void){
	Grid grille; 
	init_level("levels/level1.txt", &grille); 
	display(&grille);
	
	bool run = true;
	while(run){
		char entry = tolower(fgetc(stdin)); // tolower() used to ignore upper and lower case
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

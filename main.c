#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	Grid grille; 
	init_level("/home/chahbaoui/Desktop/projet_tech_dev/sokoban/level1.txt", &grille); 
	
	
	for(int i=0; i<286; i++){
		printf("%c",grille.game_grid[i]);
	}
	
	/*
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
	*/
	
}


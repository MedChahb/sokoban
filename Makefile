main : main.o grid.o player.o
	gcc  grid.o main.o player.o -o main
	
main.o : main.c grid.h
	gcc -w -c main.c
	
grid.o : grid.c grid.h
	gcc -w -c grid.c
	
player.o : player.c grid.h 
	gcc -w -c player.c
	
clean :
	rm *.o 

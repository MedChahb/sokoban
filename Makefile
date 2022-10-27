main : main.o grid.o
	gcc  grid.o main.o -o main
	
main.o : main.c grid.h
	gcc -c main.c
	
grid.o : grid.c grid.h
	gcc -c grid.c
	
clean :
	rm *.o 

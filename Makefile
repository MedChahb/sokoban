S_REP = src/
H_REP = include/
O_REP = obj/
B_REP = bin/
D_REP = doc/

EXE = $(B_REP)main

$(EXE) : $(O_REP) $(B_REP) $(O_REP)main.o $(O_REP)grid.o $(O_REP)player.o
	gcc  $(O_REP)grid.o $(O_REP)main.o $(O_REP)player.o -o $(B_REP)main
	
$(O_REP)%.o : $(S_REP)%.c
	gcc -c $< -o $@

	
$(O_REP) $(B_REP) :
	mkdir $@

clean :
	rm -r $(O_REP) $(B_REP)

S_REP = src/
H_REP = include/
O_REP = obj/
B_REP = bin/
D_REP = doc/

EXE = $(B_REP)main
SRC = $(wildcard $(S_REP)*.c)
OBJ = $(SRC:$(S_REP)%.c=$(O_REP)%.o)

$(EXE) : $(OBJ) | $(B_REP) $(D_REP)
	gcc $^ -lm -o $@ 

$(O_REP)%.o : $(S_REP)%.c | $(O_REP)
	gcc -c $< -o $@

$(B_REP) $(O_REP) $(D_REP):
	mkdir $@

$(D_REP) :
	doxygen Doxyfile

clean :
	rm -r $(O_REP) $(B_REP) $(D_REP)

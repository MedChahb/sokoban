I_REP = img/
S_REP = src/
H_REP = include/
O_REP = obj/
B_REP = bin/
D_REP = doc/

EXE = $(B_REP)main
SRC = $(wildcard $(S_REP)*.c)
OBJ = $(SRC:$(S_REP)%.c=$(O_REP)%.o)

CFLAGS = -Wall -Wextra
LDLIBS = -lm

$(EXE) : $(OBJ) | $(B_REP) $(D_REP) move_image
	gcc $^ $(CFLAGS) $(LDLIBS) -o $@ 

$(O_REP)%.o : $(S_REP)%.c | $(O_REP)
	gcc -c $< -o $@

$(B_REP) $(O_REP) :
	mkdir $@

$(D_REP) :
	doxygen Doxyfile

archive : 
	tar -cf sokoban.tar.gz $(I_REP) $(S_REP) $(H_REP) levels/ Doxyfile Makefile README.md sokoban.sh
	
archive_all:
	tar -cf sokoban.tar.gz */ Doxyfile Makefile README.md sokoban.sh

#images pour la documentation
move_image:
	cp -r $(I_REP) $(D_REP)html/

clean :
	rm -r $(O_REP) $(B_REP) $(D_REP)

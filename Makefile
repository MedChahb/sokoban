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

# pour utiliser le symbole dollar
DOLLAR = $

$(EXE) : $(OBJ) | SDL2 $(B_REP) $(D_REP)  move_image
	gcc $^ $(O_REP)sdl2.o $(CFLAGS) $(LDLIBS) -o $@ -I ../SokobanTechDev/install_dir/include/SDL2 -L ../SokobanTechDev/install_dir/lib/ -lSDL2main -lSDL2

$(O_REP)%.o : $(S_REP)%.c | $(O_REP)
	gcc -c $< -o $@

$(B_REP) $(O_REP) :
	mkdir $@

$(D_REP) :
	doxygen Doxyfile


archive : 
	tar -cf sokoban.tar.gz $(I_REP) $(S_REP) $(H_REP) levels/ Doxyfile Makefile README.md sokoban.sh
	
archive_all:
	tar -cf sokoban_all.tar.gz */ Doxyfile Makefile README.md sokoban.sh


SDL2:
	cd ../SokobanTechDev/SDL2/ && ./configure --prefix=$(DOLLAR)PWD/../install_dir
	cd ../SokobanTechDev/SDL2/ && make install -j6
	cd ../SokobanTechDev/src/ && gcc -c sdl2.c
	mv ../SokobanTechDev/src/sdl2.o $(O_REP)


#images pour la documentation
move_image:
	cp -r $(I_REP) $(D_REP)html/

clean :
	rm -r $(O_REP) $(B_REP) $(D_REP)

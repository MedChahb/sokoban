make clean
make
echo ""
echo "TYPE ./bin/main TO PLAY SOKOBAN"
echo ""

# ouverture de la documentation Doxygen 
firefox doc/html/index.html

#termination
kill 0

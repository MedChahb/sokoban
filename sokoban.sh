sudo apt-get install doxygen
sudo apt-get install graphviz
make clean
make
echo ""
echo "TYPE ./bin/main TO PLAY SOKOBAN"
echo ""

firefox doc/html/index.html

output: main.o Space.o Inventory.o Object.o
	g++ main.cpp Space.cpp Inventory.cpp Object.cpp Game.cpp -o output

main.o: main.cpp
	g++ -c main.cpp

Space.o: Space.hpp Space.cpp
	g++ -c Space.cpp

Inventory.o: Inventory.hpp Inventory.cpp
	g++ -c Inventory.cpp

Game.o: Game.hpp Game.cpp
	g++ -c Game.cpp

Object.o: Object.hpp Object.cpp
	g++ -c Object.cpp

clear:
	rm *.o output


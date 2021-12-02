all: main

main: ObjFiles/input.o ObjFiles/main.o ObjFiles/menu.o ObjFiles/preGame.o ObjFiles/game.o ObjFiles/options.o ObjFiles/records.o ObjFiles/show.o
	g++ ObjFiles/input.o ObjFiles/main.o ObjFiles/menu.o ObjFiles/preGame.o ObjFiles/game.o ObjFiles/options.o ObjFiles/records.o ObjFiles/show.o -o main

ObjFiles/input.o: Source/input.cpp
	g++ -c Source/input.cpp -o ObjFiles/input.o

ObjFiles/main.o: Source/main.cpp
	g++ -c Source/main.cpp -o ObjFiles/main.o

ObjFiles/menu.o: Source/menu.cpp
	g++ -c Source/menu.cpp -o ObjFiles/menu.o 

ObjFiles/preGame.o: Source/preGame.cpp 
	g++ -c Source/preGame.cpp -o ObjFiles/preGame.o

ObjFiles/game.o: Source/game.cpp
	g++ -c Source/game.cpp -o ObjFiles/game.o 
 
ObjFiles/options.o: Source/options.cpp
	g++ -c Source/options.cpp -o ObjFiles/options.o

ObjFiles/records.o: Source/records.cpp
	g++ -c Source/records.cpp -o ObjFiles/records.o

ObjFiles/show.o: Source/show.cpp
	g++ -c Source/show.cpp -o ObjFiles/show.o
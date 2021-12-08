all: main

main: ObjFiles/input.o ObjFiles/main.o ObjFiles/menu.o ObjFiles/preGame.o ObjFiles/game.o ObjFiles/options.o ObjFiles/records.o ObjFiles/show.o
	g++ ObjFiles/input.o ObjFiles/main.o ObjFiles/menu.o ObjFiles/preGame.o ObjFiles/game.o ObjFiles/options.o ObjFiles/records.o ObjFiles/show.o -o main

ObjFiles/input.o: Src/input.cpp
	g++ -c Src/input.cpp -o ObjFiles/input.o

ObjFiles/main.o: Src/main.cpp
	g++ -c Src/main.cpp -o ObjFiles/main.o

ObjFiles/menu.o: Src/menu.cpp
	g++ -c Src/menu.cpp -o ObjFiles/menu.o 

ObjFiles/preGame.o: Src/preGame.cpp
	g++ -c Src/preGame.cpp -o ObjFiles/preGame.o

ObjFiles/game.o: Src/game.cpp
	g++ -c Src/game.cpp -o ObjFiles/game.o 
 
ObjFiles/options.o: Src/options.cpp
	g++ -c Src/options.cpp -o ObjFiles/options.o

ObjFiles/records.o: Src/records.cpp
	g++ -c Src/records.cpp -o ObjFiles/records.o

ObjFiles/show.o: Src/show.cpp
	g++ -c Src/show.cpp -o ObjFiles/show.o


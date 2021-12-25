Omain = Bin/main.o
Oinput = Bin/input.o
Omenu = Bin/menu.o
OpreGame = Bin/preGame.o
Ogame = Bin/game.o
Ooptions = Bin/options.o
Orecords = Bin/records.o
Oshow = Bin/show.o
Ofirework = Bin/firework.o
Oparticle = Bin/particle.o
ncurses = /usr/lib/x86_64-linux-gnu/libm.so -lncurses 
Oall = $(Oinput) $(Omain) $(Omenu) $(OpreGame) $(Ogame) $(Ooptions) $(Orecords) $(Oshow) $(Ofirework) $(Oparticle)

all: main

main: $(Oall)
	@g++ $(Oall) $(ncurses) -o main -lm

$(Oinput): Src/input.cpp
	g++ -c Src/input.cpp -o $(Oinput)

$(Omain): Src/main.cpp
	g++ -c Src/main.cpp -o $(Omain)

$(Omenu): Src/menu.cpp
	g++ -c Src/menu.cpp -o $(Omenu) 

$(OpreGame): Src/preGame.cpp
	g++ -c Src/preGame.cpp -o $(OpreGame)

$(ogame): Src/game.cpp
	g++ -c Src/game.cpp -o $(ogame)

$(Ooptions): Src/options.cpp
	g++ -c Src/options.cpp -o $(Ooptions)

$(Orecords): Src/records.cpp
	g++ -c Src/records.cpp -o $(Orecords)

$(show): Src/show.cpp
	g++ -c Src/show.cpp -o $(show)

$(Ofirework): Src/firework.cpp
	g++ -c Src/firework.cpp -o $(Ofirework) -lm

$(Oparticle): Src/particle.cpp
	g++ -c Src/particle.cpp -o $(Oparticle) -lm



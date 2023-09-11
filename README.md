# How To Run
You need to install ncurses and make at first:
```
sudo apt-get install libncurses5-dev
sudo apt-get install make
```
After that just run in main directory:
```
make
```
then: 
```
./main
```

# About Minesweeper

Minesweeper is a single-player puzzle video game. The objective of the game is to clear a rectangular board containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighboring mines in each field. The game originates from the 1960s, and it has been written for many computing platforms in use today. It has many variations and offshoots.


# Gameplay

In Minesweeper, mines (that resemble naval mines in the classic theme) are scattered throughout a board, which is divided into cells. Cells have three states: uncovered, covered and flagged. A covered cell is blank and clickable, while an uncovered cell is exposed. Flagged cells are those marked by the player to indicate a potential mine location.

A player should press 'Enter' a cell to uncover it. If a player uncovers a mined cell, the game ends, as there is only 1 life per game. Otherwise, the uncovered cells displays either a number, indicating the number of mines diagonally and/or adjacent to it, or a blank tile (or "0"), and all adjacent non-mined cells will automatically be uncovered. 'F' button on a cell will flag it, causing a flag to appear on it. Flagged cells are still considered covered, and a player can prees 'F' on them to uncover them.

To win the game, players must uncover all non-mine cells, at which point, the timer is stopped. Flagging all the mined cells is not required.
  
  
# How To Play

[ W ] - Up
  
[ S ] - Down
  
[ A ] - Left
  
[ D ] - Right
  
[ Enter ] - Open
  
[ F ] - Flag
  
[ P ] - Pause


# Screenshots

![Main Menu](https://github.com/YurBagoyan/Minesweeper/assets/90376899/ad31bd60-d633-4779-a3a5-fac982d0eb10)
![Options](https://github.com/YurBagoyan/Minesweeper/assets/90376899/7f4e7672-d772-4879-8bc6-e2c1e9f6b8c0)
![Records](https://github.com/YurBagoyan/Minesweeper/assets/90376899/b7f3d5fe-c985-42b7-9ba0-afd1df2782ee)
![How to play](https://github.com/YurBagoyan/Minesweeper/assets/90376899/6bada904-c74a-4bec-96dc-40ec0e61ca82)


# References

Minesweeper slide link - https://clck.ru/ZsQ4U

About game in Wikipedia - https://en.wikipedia.org/wiki/Minesweeper_(video_game)

Color scheme - https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit 

Unusual symbols - https://coolsymbol.com

For text design - https://www.messletters.com/en/big-text/

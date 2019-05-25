# Reversi
---
# Description
This is my reversi game implementation made for semester project and self improvement. The goal is to have more pieces than enemy at the end of the game.
## Rules
There are two players (black and white) and a square 8x8 grid. The game starts with 4 pieces where each player owns 2 of them. The player that is on the move has to place a piece in such way that there is his another piece in the straight line (verical, horizontal or diagonal) and between them there is atleast one (or more) enemy's piece with no other gaps. After placing the piece he captures all pieces lying between two player's pieces in all directions. A valid move is when active player captures at least one opponent's piece. If active player has no valid moves then the opponent becomes an active player. The game ends when there aren't more valid moves or the grid is full of pieces. The winner is a player with bigger amount of pieces.

## How to launch?
1. Clone repository using:
```sh
git clone https://github.com/fiedosiukr/reversi
```
2. Open terminal in folder where your repository is:
```sh
cd reversi
```
3. Compile all files:
```sh
make
```
4. Launch the game (depending on your system):
```sh
./reversi
```
or
```sh
reversi
```

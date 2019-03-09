## **FILLER**

### Player for the game Filler
<hr>

### Game description
FILLER is a game, where 2 players are playing against each other.
The virtual machine calls the players alternatively, gives each player a random piece on each turn
and each player places a piece to hinder the opponent or occupy strategically important area of the board. 
To put down a piece, the player have to print the coordinates in the "Y X\n" format on the standard output (stdout).
The goal of the game is to place more pieces than the opponent.

### Video
![](https://i.imgur.com/X00GduI.gif)
* player1 is YELLOW
* player2 is RED

### installation
make
make -C visu

SDL is used to implement visualizer for the filler. SDL and pkg-config has to be installed to compile & execute visualizer

### execution
./resources/filler_vm -f ./resources/maps/map01 -p1 ./jaelee.filler -p2 ./resources/players/carli.filler
with the visualizer \
./resources/filler_vm -f ./resources/maps/map01 -p1 ./jaelee.filler -p2 ./resources/players/carli.filler | ./visu/visualizer

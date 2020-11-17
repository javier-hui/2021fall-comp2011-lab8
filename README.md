# COMP2011 Lab 8: Bingo

## Introduction

In this lab, you are going to implement a bingo game with C++ structs, 1-D and 2-D arrays. Also, you will practice on separate compilation with separate ‘.h’ and ‘.cpp’ files.
Description
This is a group game with 5 players. Each player has a bingo card (the size is 5x5), which is filled with numbers from 1 to 25. The position of each number is random and one number appears exactly once.

## The procedure of the game:

- At the beginning, you need to initialize the information for players, including their names, bingo cards and so on.
- After that you can start the game. For each round, you need to pick one number from range 1 to 25. (You can assume that you never pick the repeated number.) Then, the grid with this number on the bingo card is considered as occupied.
- After several rounds, when there is one player having an entire occupied row, column, or diagonal, the game is over and that player gets bingo!

## Implementation

Start your coding with skeleton code and complete the core functions.
* We have a struct called Player, which contains four variables: name, bingo_card, card_status and bingo. More specifically:
  * name: char array.
  * bingo_card: 5x5 2d integer array.
  * card_status: 5x5 2d boolean array, where one or zero means occupied or not.
  * bingo: is a boolean variable, where true or false means bingo or not.
* We have an 1d array with size 5 called ‘plys’, which stores five players.

Tasks:
* Complete four function declarations in "lab8.h". They are called in "main.cpp".
* Finish all function definitions in "lab8.cpp". Details are in the comments.
* Write a make file in "Makefile".

Notes:
You don't need to modify the code in "main.cpp", only write your code in "lab8.h", "lab8.cpp", and "Makefile".
To run the code, firstly you need to use "make" command in the terminal to generate the executable file. Then, use "./YOUR_EXECUTABLE_FILE_NAME" command to run. (You should replace "YOUR_EXECUTABLE_FILE_NAME" with the name you used in "Makefile")
Samples of Make file can be found at code in separate compilation https://course.cse.ust.hk/comp2011/notes/separate-compilation-program.zip.

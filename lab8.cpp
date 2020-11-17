#include "lab8.h"

/*
Task 1
Initialize the players:
Assign the name
Randomly generate a bingo card
Initialize card_status to all zeros and bingo to false
Hint: you can use "std::random_shuffle()" function to generate 1d array with size 25, and resize it to 5x5 2d array
*/

// function name: init_player
// Your code here

void init_player(Player& ply, char name[]) {
    memcpy(ply.name, name, strlen(name)+1);
    int temp[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; ++i) temp[i] = i + 1;
    random_shuffle(temp, temp + SIZE * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ply.bingo_card[i][j] = temp[i * SIZE + j];
            ply.card_status[i][j] = 0;
        }
    }
    ply.bingo = false;
}


 
/*
Task 2:
Display five players' information:
If the number has been picked, add '*' after it. 
The output for each player looks like this:
___________________________________________________
Name: Peter
Bingo card ('*' means the number has been picked)
20      4       15      16      11
3       23      25      9*      5
21      8       6       12      2
10      1       22      14      19
13      24      7       17      18
*/
// function name: display_info
// Your code here

void display_info(Player plys[], int player_num) {
    for (int i = 0; i < player_num; ++i) {
        cout << "___________________________________________________" << endl;
        cout << "Name: " << plys[i].name << endl;
        cout << "Bingo card ('*' means the number has been picked)" << endl;
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                cout << plys[i].bingo_card[j][k] << (plys[i].card_status[j][k] ? "*\t" : "\t");
            }
            cout << endl;
        }
    }
}


/*
Task 3:
Change the status for picked number:
You should find the position of the number you picked in bingo card and update the status.
*/

// function name: change_status
// Your code here

void change_status(Player& ply, int num) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (ply.bingo_card[i][j] == num) ply.card_status[i][j] = true;
    return;
}

/*
Task 4:
Check bingo:
You should check the status for all rows, columns and two diagonals. 
Return true if there is an entire occupied line, otherwise, return false.
*/

// function name: check_bingo
// Your code here

bool check_bingo(Player& ply) {
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < SIZE; ++i) {
        bool horizontal = true, vertical = true;
        for (int j = 0; j < SIZE; ++j) {
            if (!ply.card_status[i][j]) horizontal = false;
            if (!ply.card_status[j][i]) vertical = false;
        }
        if (horizontal || vertical) ply.bingo = true;
        if (!ply.card_status[i][i]) diag1 = false;
        if (!ply.card_status[i][SIZE-i-1]) diag2 = false;
    }
    if (diag1 || diag2) ply.bingo = true;
    return ply.bingo;
}
#include<stdio.h>
char board[3][3]=
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void display_board();
int checkWin();
void make_move(char player);

int main() 
{
    char currentPlayer = 'X';
    printf("Welcome to Tic Tac Toe!\n");
    display_board();

    for (int turn = 0; turn < 9; turn++) 
    {
        make_move(currentPlayer);
        display_board();

        if (checkWin()) 
        {
            printf("Player %c wins!\n", currentPlayer);
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printf("It's a draw!\n");
    return 0;
}

void display_board() 
{
    printf("\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

//Code for making a move for a player 
void make_move(char player)
{
    int choice;
    printf("Player %c, enter a number (1-9):",player);
    scanf("%d",&choice);
    
    int row = (choice-1)/3;
    int column = (choice-1)%3;
    if(choice<1 || choice>9 || board[row][column]=='O' || board[row][column]=='X')
    {
        printf("Invalid move\n");
        make_move(player);
    }
    else
    {
        board[row][column]=player;
    }
}

int checkWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1; // Row match
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1; // Column match
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1; // Diagonal match
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1; // opposite diagonal match

    return 0; // No win
}

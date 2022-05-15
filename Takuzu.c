//
// Project Takuzu provided by Antoine Dupont et Alexandre Poujol
//
//Description of the role of every function

#include "Takuzu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int size() // Ask for the size of the Takuzu that the user wants and return this value
{
    int size;
    do {
        printf("Type the size of Takuzu that you want (only 4*4 and 8*8 are available): \n");
        fflush(stdin);
        scanf("%d",&size);
    }while(size != 4 && size != 8);

    return(size);
}

int empty(int s, int grid[s][s], int row, int column) // Look if the cell is empty returning 1 if yes and 0 if not
{
    int valid;

    if (grid[row][column] != 1 && grid[row][column] != 0)  // If the cell do not have any 1 or 0
    {
        valid = 1; // The move is valid
    }
    else
    {
        valid = 0;
    }
    return valid;
}

int full(int s, int grid[s][s]) // Look if the grid is full or not and returning 0 if not
{
    int full = 1;
    for (int i=0; i<s; i++){
        for (int j = 0; j < s; j++) {
            if (grid[i][j] != 1 && grid[i][j] != 0) // If one of the cell do not contain any 1 or 0
            {
                full = 0; // The matrix is not full
                break;
            }
        }
    }
    return full;
}

int validity(int s, int solution[s][s],int row, int column, int value) // Check if the value entered is same as in the solution returning 1 if yes 0 if not
{
    int validity;
    if (value == solution[row][column]) // If the value is the same as the solution matrix
    {
        validity = 1; // The move is valid
    }
    else
    {
        validity = 0;
    }
    return validity;
}

void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s]) // Create the grid for the user in game_grid by compiling the mask and solution grid
{
    for (int i=0; i < s; i++) {
        for (int j = 0; j < s; j++)
        {
            if (mask[i][j] == 1) // If the mask wants to display it (have a 1 in this cell)
            {
                game_grid[i][j] = solution[i][j]; // We put it in the game_grid
            }
            else
            {
                game_grid[i][j] = 10;
            }
        }
    }
}

char ask_column(int s) // Ask the user in which column he wants to put his value returning a character
{
    char column;
    if (s==4)
    {
        do { // Ask for the column if 4*4
            printf("Enter the column of the value you want (A to D): \n");
            fflush(stdin);
            scanf(" %c", &column);
        } while (!strchr("ABCDabcd", column)); // Verify that the column entered is possible
    }
    else
    {
        do { // Ask for the column if 8*8
            printf("Enter the column of the value you want (A to H): \n");
            fflush(stdin);
            scanf(" %c", &column);
        } while (!strchr("ABCDEFGHabcdefgh", column)); // Verify that the column entered is possible
    }
    return column;
}

int ask_row(int s) // Ask the user in which row he wants to put his value returning the row-1 to be used by the matrix
{
    int row;
    if (s==4)
    {
        do { // Ask for the row if 4*4
            printf("Enter the row of the value you want (1 to 4): \n");
            fflush(stdin);
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4); // Verify that the row entered is possible
    }
    else
    {
        do { // Ask for the row if 8*8
            printf("Enter the row of the value you want (1 to 8): \n");
            fflush(stdin);
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4 && row != 5 && row != 6 && row != 7 && row != 8); // Verify that the row entered is possible
    }
    return row-1; // Return the value that the program can use
}

int conv_l_to_nb(char column) // Transform the column entered which is a letter to a value returned that the matrix can use
{
    int j;
    if (column == 'a' || column == 'A') { // If the column is 'A' or 'a' it means that it is the first column which is 0 for the program
        j = 0;
    } else {
        if (column == 'b' || column == 'B') {
            j = 1;
        } else {
            if (column == 'c' || column == 'C') {
                j = 2;
            } else {
                if (column == 'd' || column == 'D') {
                    j = 3;
                } else {
                    if (column == 'e' || column == 'E') {
                        j = 4;
                    } else {
                        if (column == 'f' || column == 'F') {
                            j = 5;
                        } else {
                            if (column == 'g' || column == 'H'){
                                j=6;
                            }
                            else{
                                j=7;
                            }
                        }
                    }
                }
            }
        }
    }
    return j;
}

void generate_matrix(int s, int solution[s][s], int mask[s][s]) // Create two matrices (solution and mask) according to the size using a library of solution and mask matrices
{
    int r;
    srand(time(0));
    r = (rand()%4); // Generate a random number
    if (s==4)
    { // The library of 4*4 matrices (solutions and masks)
        int solution14[4][4]={
                {1, 0, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 1}
        };
        int mask14[4][4]={
                {1, 0, 0, 0},
                {0, 0, 1, 0},
                {1, 0, 1, 1},
                {0, 1, 0, 0}
        };
        int solution24[4][4]={
                {0, 1, 1, 0},
                {1, 0, 0, 1},
                {0, 0, 1, 1},
                {1, 1, 0, 0}
        };
        int mask24[4][4]={
                {0, 1, 0, 1},
                {0, 0, 1, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 1}
        };
        int solution34[4][4]={
                {0, 1, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 1},
                {1, 1, 0, 0}
        };
        int mask34[4][4]={
                {0, 1, 0, 1},
                {0, 1, 1, 0},
                {0, 0, 0, 1},
                {1, 1, 0, 1}
        };
        int solution44[4][4]={
                {0, 1, 1, 0},
                {1, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1}
        };
        int mask44[4][4]={
                {0, 1, 0, 1},
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 0, 1, 1}
        };
        if(r==0) // If the random value is 0
        {
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < s; j++) {
                    solution[i][j] = solution14[i][j]; // The solution grid will be the first one in the library
                    mask[i][j] = mask14[i][j]; // The mask grid will be the first one in the library
                }
            }
        }
        else
        {
            if(r==1)
            {
                for (int i = 0; i < s; i++) {
                    for (int j = 0; j < s; j++) {
                        solution[i][j] = solution24[i][j];
                        mask[i][j] = mask24[i][j];
                    }
                }
            }
            else
            {
                if (r==2)
                {
                    for (int i = 0; i < s; i++) {
                        for (int j = 0; j < s; j++) {
                            solution[i][j] = solution34[i][j];
                            mask[i][j] = mask34[i][j];
                        }
                    }
                }
                else
                {
                    if (r==3)
                    {
                        for (int i = 0; i < s; i++) {
                            for (int j = 0; j < s; j++) {
                                solution[i][j] = solution44[i][j];
                                mask[i][j] = mask44[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    else
    { // The library of 8*8 matrices (solutions and masks)
        int solution18[8][8]={
                {1, 0, 1, 1, 0,1 ,0,0},
                {1, 0, 1, 0, 1,0 ,0,1},
                {0, 1, 0, 1, 1,0 ,1,0},
                {0, 1, 0, 1, 0,1 ,1,0},
                {1, 0, 1, 0, 0,1 ,0,1},
                {0, 1, 0, 0, 1,0 ,1,1},
                {0, 0, 1, 1, 0,1 ,1,0},
                {1, 1, 0, 0, 1,0 ,0,1},
        };
        int mask18[8][8]={
                {1, 0, 1, 1, 0,1 ,0,1},
                {0, 0, 1, 0, 0,0 ,0,0},
                {1, 0, 0, 0, 0,0 ,0,1},
                {1, 0, 1, 0, 0,1 ,1,0},
                {1, 0, 0, 0, 1,0 ,0,1},
                {0, 0, 0, 0, 1,0 ,0,0},
                {0, 1, 1, 1, 1,1 ,0,0},
                {0, 1, 0, 1, 0,0 ,1,0},
        };
        int solution28[8][8]={
                {0, 0, 1, 0, 1, 0, 1, 1},
                {1, 0, 0, 1, 0, 1, 0, 1},
                {0, 1, 0, 1, 1, 0, 1, 0},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {1, 0, 1, 0, 0, 1, 0, 1},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {0, 1, 1, 0, 1, 0, 1, 0},
                {1, 1, 0, 1, 0, 1, 0, 0},
        };
        int mask28[8][8]={
                {1, 1, 1, 1, 1, 1, 0, 0},
                {1, 0, 1, 0, 1, 0, 0, 0},
                {1, 1, 1, 0, 0, 0, 1, 0},
                {1, 0, 0, 0, 1, 0, 1, 0},
                {1, 0, 0, 0, 0, 1, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 1, 0, 0, 0, 1, 1},
        };
        int solution38[8][8]={
                {1, 0, 0, 1, 0, 1, 0, 1},
                {0, 0, 1, 1, 0, 0, 1, 1},
                {1, 1, 0, 0, 1, 1, 0, 0},
                {1, 1, 0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0, 1, 1},
                {0, 0, 1, 1, 0, 1, 0, 1},
                {1, 1, 0, 0, 1, 0, 1, 0},
                {0, 1, 1, 0, 1, 0, 1, 0},
        };
        int mask38[8][8]={
                {0, 1, 1, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 1},
                {0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 1},
                {1, 0, 1, 1, 0, 0, 1, 0},
                {0, 1, 1, 0, 0, 1, 0, 0},
        };
        int solution48[8][8]={
                {1, 1, 0, 1, 0, 1, 0, 0},
                {1, 0, 1, 0, 1, 0, 0, 1},
                {0, 1, 0, 1, 0, 0, 1, 1},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {1, 0, 1, 0, 1, 1, 0, 0},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {0, 1, 0, 1, 0, 1, 1, 0},
                {0, 0, 1, 0, 1, 0, 1, 1},
        };
        int mask48[8][8]={
                {0, 1, 1 ,1, 1, 0, 1, 0},
                {0, 1, 0 ,0, 0, 0, 1, 1},
                {1, 1, 0 ,0, 0, 1, 0, 0},
                {1, 0, 0 ,1, 1, 1, 0, 0},
                {1, 1, 0 ,0, 1, 0, 1, 1},
                {0, 1, 1 ,0, 0, 0, 1, 0},
                {0, 0, 0 ,0, 0, 0, 0, 0},
                {0, 0, 0 ,0, 1, 0, 0, 0},
        };
        if(r==0)
        {
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < s; j++) {
                    solution[i][j] = solution18[i][j];
                    mask[i][j] = mask18[i][j];
                }
            }
        }
        else
        {
            if (r==1)
            {
                for (int i = 0; i < s; i++) {
                    for (int j = 0; j < s; j++) {
                        solution[i][j] = solution28[i][j];
                        mask[i][j] = mask28[i][j];
                    }
                }
            }
            else
            {
                if (r==2)
                {
                    for (int i = 0; i < s; i++) {
                        for (int j = 0; j < s; j++) {
                            solution[i][j] = solution38[i][j];
                            mask[i][j] = mask38[i][j];
                        }
                    }
                }
                else
                {
                    if (r==3)
                    {
                        for (int i = 0; i < s; i++) {
                            for (int j = 0; j < s; j++) {
                                solution[i][j] = solution48[i][j];
                                mask[i][j] = mask48[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
}

void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives, int stop) //Can enter a value in a cell, checking if the move is valid or display a hint 3 times
{
    char column;
    int row,value,j,valid,same_solution,full1,back;
    full1 = full(s,game_grid);

    if (full1 == 0) // If the grid is not full
    {
        do{
            printf("\nWhat do you want to do next ?\n - Enter another value (press 1)\n - Have a hint on a value in the grid (press 2)\n - Go back to the main menu (press 3)\n");
            fflush(stdin);
            scanf("%d",&back);
        }while (back != 1 && back != 2 && back != 3);

        if (back == 3) // If the user wants to go back to the main menu
        {
            printf("\nYou're back in the main menu.\n\n");
            menu();
        }
        else
        {
            if (back == 2) // If the user wants to have a hint
            {
                if (stop > 0) // Checking if he still have hints
                {
                    stop = hint(s,solution,game_grid,stop);
                    play(s,mask,solution,game_grid,lives,stop);
                }
                else
                {
                    printf("You have no more hint...\n");
                    enter_value(s,mask,solution,game_grid,lives,stop);
                }
            }
            else // If the user wants to enter a value
            {
                column = ask_column(s);
                j = conv_l_to_nb(column); // Convert the letter given by the user to the real column in the matrix


                row = ask_row(s);

                valid = empty(s, game_grid, row, j); // Check if the cell is empty

                if (valid == 0) // If the cell is not empty
                {
                    printf("The cell is not empty.\nTry again :\n");
                    play(s,mask, solution,game_grid,lives,stop);
                }
                else // If the cell is empty
                {
                    do {
                        printf("Enter the value you want to enter (1 or 0): \n");
                        fflush(stdin);
                        scanf("%d", &value);
                    } while (value != 1 && value != 0);
                    same_solution = validity(s,solution,row,j,value);


                    if (same_solution == 1) // If the value correspond to the solution grid
                    {
                        game_grid[row][j] = value;
                        printf("\nYou want to enter %d at the coordinate %c%d. This move is valid.\n", value, column, row+1);
                    }
                    else
                    {
                        why_wrong(s,game_grid,row,j); // Explain the mistake and subtract a life
                        lives-=1;
                        printf("You lost one life. You have now %d.\n\n",lives);
                    }

                    if (lives !=0) // If there is some lives left
                    {
                        play(s,mask,solution,game_grid, lives,stop);
                    }
                    else
                    {
                        printf("You've lost ! Try again !\n\n"); // If no lives left
                        menu();
                    }
                }
            }
        }

    }
    else // If the grid is full
    {
        printf("You've finished this grid, well done !\n\n");
        menu();
    }


}

void why_wrong(int s, int game_grid[s][s], int row, int column) // Explain what is error made by the user by checking every case possible
{
    if (column-1 >-1 && column-2 >-1 && game_grid[row][column-1] == game_grid[row][column-2] && game_grid[row][column-1] != 10 && game_grid[row][column-2] != 10)
    {
        printf("The two previous values in this row are the same. You must put another value after it.\n");
    }
    else
    {
        if (column+1 < s && column+2 < s && game_grid[row][column+1] == game_grid[row][column+2] && game_grid[row][column+1] != 10 && game_grid[row][column+2] != 10)
        {
            printf("The two next values in this row are the same. You must put another value before it.\n");
        }
        else
        {
            if (row-1 >-1 && row-2 > -1 && game_grid[row-1][column] == game_grid[row-2][column] && game_grid[row-1][column] != 10 && game_grid[row-2][column] != 10)
            {
                printf("The two previous values in this column are the same. You must put another value after it.\n");
            }
            else
            {
                if (row+1 < s && row+2 < s && game_grid[row+1][column] == game_grid[row+2][column] && game_grid[row+1][column] != 10 && game_grid[row+2][column] != 10)
                {
                    printf("The two next values in this column are the same. You must put another value before it.\n");
                }
                else
                {
                    if (column+1 < s && column-1 >-1 && game_grid[row][column-1] == game_grid[row][column+1] && game_grid[row][column-1] != 10 && game_grid[row][column+1] != 10)
                    {
                        printf("The two values around are the same. You must put another value in the middle.\n");
                    }
                    else
                    {
                        if (row+1 < s && row-1 >-1 && game_grid[row-1][column] == game_grid[row+1][column] && game_grid[row-1][column] != 10 && game_grid[row+1][column] != 10)
                        {
                            printf("The two values above and below are the same. You must put another value in the middle.\n");
                        }
                        else
                        {
                            printf("Your move could be right but do not correspond to the solution grid.\n"); //If no condition correspond then the move could be right but isn't the same as the solution
                        }
                    }
                }
            }
        }
    }
}

int hint(int s,int solution[s][s],int game_grid[s][s], int stop) // Display a random value from the solution grid that wasn't filled to the user if didn't ask it 3 times already and return 'stop' which represent the hints that he still have
{
    int column,row,empty1,hint_value;
    char columnl;

    do{
        srand(time(0));
        column = (rand()%s); //Generate a random number for the column

        row = (rand()%s); // Generate a random number for the row
        empty1 = empty(s,game_grid,row,column);  // Checking if the cell generated is empty
    }while(empty1 != 1);


    // Convert the column number to a letter that will be displayed to the user
    if (column == 0)
    {
        columnl = 'A';
    }
    else
    {
        if (column == 1)
        {
            columnl = 'B';
        }
        else
        {
            if (column == 2)
            {
                columnl = 'C';
            }
            else
            {
                if (column == 3)
                {
                    columnl = 'D';
                }
                else
                {
                    if (column == 4)
                    {
                        columnl = 'E';
                    }
                    else
                    {
                        if (column == 5)
                        {
                            columnl = 'F';
                        }
                        else
                        {
                            if (column == 6)
                            {
                                columnl = 'G';
                            }
                            else
                            {
                                columnl = 'H';
                            }
                        }
                    }
                }
            }
        }
    }

    hint_value = solution[row][column]; // The value corresponding to the column and row chosen by the program in the solution grid is putted in hint_value
    printf("\nThe value at %c%d is %d.\n",columnl,row+1,hint_value);
    stop-= 1; // Subtract a hint
    return stop;
}

void display_matrix(int s, int grid[s][s])  // Display the matrix and, if it's a game_grid, hide the value that user did not fill already
{
    if (s==4)
    {
        printf("   A B C D\n"); // Display the column names for a 4*4 grid
    }
    else
    {
        printf("   A B C D E F G H\n"); // Display the column names for a 8*8 grid
    }
    for (int i=0; i<s; i++) {
        for (int j = 0; j < s; j++) {
            if (j==0)
            {
                printf("%d  ",i+1); // Display the column names for a 8*8 grid
            }
            if (grid[i][j] != 1 && grid[i][j] != 0) { // If the cell is empty yet
                if (j == s - 1) { // If it is the last value of the row
                    printf("\n");
                }
                else
                {
                    printf("  ");
                }
            }
            else // If the cell already have a value
            {
                if (j != s - 1) { // If it not the last value of the row
                    printf("%d ", grid[i][j]);
                }
                else {
                    printf("%d\n", grid[i][j]);
                }
            }
        }
    }
}

void enter_a_mask(int s, int mask[s][s]) // Allow the user to enter a mask that will be stored in mask
{
    int column, row, value,back;
    int full1 = 0;
    for (int i=0; i<s;i++)
    {
        for (int j=0; j<s;j++)
        {
            mask[i][j] = 10; // Create an empty mask matrix
        }
    }
    do{
        do{
            printf("\nWhat do you want to do next ?\n - Enter another value (press 1)\n - Go back to the main menu (press 2)\n");
            fflush(stdin);
            scanf("%d",&back);
        }while (back != 1 && back != 2);

        if (back==1) // If the user wants to enter a value
        {
                column = conv_l_to_nb(ask_column(s));
                row = ask_row(s); // Ask for the column and row
                do{
                    printf("Enter the value you want (1 if you want to display it or 0 if not):");
                    fflush(stdin);
                    scanf("%d",&value);
                }while (value != 1 && value != 0);
                mask[row][column] = value; // Put the value in the matrix
                display_matrix(s,mask); // Display the new matrix to the user
                full1 = full(s,mask); // Check if the user has filled the mask matrix
        }
        else
        {
            menu();  // Go back to the main menu
        }
    }while(full1==0);
}

void resolve_automatically(int s, int game_grid[s][s], int solution[s][s]) // Resolve a grid automatically waiting for the user to enter n to fill the next cell
{
    int empty1,full1;
    char c;
    display_matrix(s,game_grid); // Display the initial matrix
    do{
        printf("Enter n to see the next resolution :");
        fflush(stdin);
        scanf(" %c",&c);
    }while (c != 'n'); // Wait for the user to enter 'n'
    c = 'a'; // Reinitialise c to make it different from n
    full1 = full(s,game_grid); // Check if the grid is completely resolved
    do{
        for (int i=0; i<s; i++)
        {
            for (int j=0; j<s; j++)
            {
                empty1 = empty(s,game_grid,i,j); // Check if the cell is empty
                if (empty1 == 1)
                {
                    game_grid[i][j]=solution[i][j]; // Put the solution in the game_grid
                    display_matrix(s,game_grid); // Display the matrix with one new value
                    while (c != 'n')
                    {
                        printf("Enter n to see the next resolution :");
                        fflush(stdin);
                        scanf(" %c",&c);
                    }
                    c = 'a';
                    full1 = full(s,game_grid);
                }
            }
        }
    }while(full1==0);
    printf("\nYou're back to the main menu.\n"); // When the grid is completely resolved by the function it goes back to the main menu
    menu();
}

void create_solution(int s, int solution[s][s]) // Create a correct solution grid in solution and check how many times 1 and 0 appears on every row or column
{
    // This function is not efficient enough and so as do not work for 8*8 matrix that make it work for too long
    int x,y,sum_r,sum_c;
    grid_generator(s,solution); // Generate a matrix that respect rules

    x = 0;
    for (int i = 0; i < s; i++) {
        sum_r = 0;
        for (int j = 0; j < s; j++) {
            sum_r += solution[i][j];
            if (j == s - 1 && sum_r == s / 2) {
                x += 1; // Check that every row do not have more that 2 (if 4*4) or 4 (if 8*8) '1'
            }
        }
    }

    display_matrix(s,solution);
    printf("\n");

    if (x < s) // If some rows are incorrect we retry
    {
        create_solution(s,solution);
    }
    else
    {
        y = 0;
        for (int i = 0; i < s; i++) {
            sum_c = 0;
            for (int j = 0; j < s; j++) {
                sum_c+= solution[j][i];
                if (j == s - 1 && sum_c == s / 2) {
                    y+=1; // Check that every column do not have more that 2 (if 4*4) or 4 (if 8*8) '1'
                }
            }
        }
        if (y < s) // If some rows are incorrect we retry
        {
            create_solution(s,solution);
        }
    }
}

void grid_generator(int s, int solution[s][s]) //Generate a random solution grid that respect certain rules but not all (do not check how many times 1 and 0 appears on every row or column)
{
    int r;
    srand(time(0));

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {

            if (j - 1 > -1 && j - 2 > -1 && solution[i][j - 1] == 1 && solution[i][j - 2] == 1) { //If the 2 previous values in the row are 1
                solution[i][j] = 0;
            } else {
                if (j - 1 > -1 && j - 2 > -1 && solution[i][j - 1] == 0 &&
                    solution[i][j - 2] == 0) { //If the 2 previous values in the row are 0
                    solution[i][j] = 1;
                } else {
                    if (i - 1 > -1 && i - 2 > -1 && solution[i - 1][j] == 1 && solution[i - 2][j] == 1) //If the 2 previous values in the column are 1
                    {
                        solution[i][j] = 0;
                    }
                    else {
                        if (i - 1 > -1 && i - 2 > -1 && solution[i - 1][j] == 0 && solution[i - 2][j] == 0) { //If the 2 previous values in the column are 0
                            solution[i][j] = 1;
                        }
                        else
                        {
                            r = (rand()%2); // Generate a random number
                            solution[i][j] = r;
                        }
                    }

                }
            }
        }
    }
}

void mask_generator(int s, int mask[s][s]) //Generate a random mask and put it in the mask matrix
{
    int r;
    srand(time(0));

    for (int i=0; i<s; i++)
    {
        for (int j=0; j<s; j++)
        {
            r = (rand()%2); // Generate a random number
            mask[i][j] = r;
        }
    }
}

void play(int s, int mask[s][s], int solution[s][s],int game_grid[s][s], int lives, int stop) // Call the functions needed to play to the Takuzu game
{
    display_matrix(s,game_grid); // Display the matrix first
    enter_value(s,mask,solution,game_grid,lives,stop);
}

void menu() // The main menu function that display the features and called the functions needed for each
{
    int s, choice, c;
    s = size();
    int solution[s][s];
    int mask[s][s];
    int game_grid[s][s];
    int lives = 3;
    int stop = 3;


    do{
        printf("Do you want to :\n - Enter a mask (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)\n - Resolve a grid automatically (press 4)\n - Generate a solution grid (press 5) ONLY WORK FOR 4*4");
        fflush(stdin);
        scanf("%d",&choice);
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

    if (choice==1) // If the user wants to enter a mask
    {
        generate_matrix(s,solution,mask); // We generate a solution and a mask matrix
        int mask1[s][s];
        enter_a_mask(s,mask1); // We let user enter his value in the new mask1
        game_grid_c(s,mask1,solution,game_grid); // We generate a game grid using the matrix entered by the user
        play(s,mask1,solution,game_grid,lives,stop); // The user can play with his new mask a Takuzu game
    }
    else
    {
        if (choice==2) // If the user wants to generate a mask
        {
            int mask1[s][s];
            do{
                generate_matrix(s, solution, mask); // We generate a solution and a mask matrix
                mask_generator(s,mask1); // We create a random mask
                printf("\nThe mask grid :\n\n");
                display_matrix(s,mask1);
                printf("\n");
                do {
                    printf("Do you want to play with this mask ? (press 1 if yes 2 if no)");
                    fflush(stdin);
                    scanf("%d", &c);
                } while (c != 1 && c != 2);
            }while(c == 2); // While the user do not want to play with the mask we keep displaying new ones
            game_grid_c(s,mask1,solution, game_grid); // When he presses 2 then he can play with it
            play(s,mask1,solution,game_grid,lives,stop);
        }
        else
        {
            if (choice == 3) // If the user wants to play a game
            {
                generate_matrix(s,solution,mask);
                game_grid_c(s,mask,solution, game_grid);
                play(s,mask, solution,game_grid,lives,stop);
            }
            else
            {
                if (choice == 4) // If the user wants to see the program resolve a grid
                {
                    generate_matrix(s,solution,mask);
                    game_grid_c(s,mask,solution,game_grid);
                    resolve_automatically(s, game_grid, solution);
                }
                else // If the user wants to create a solution grid
                {
                    if (s==4)
                    {
                        create_solution(s,game_grid);
                        display_matrix(s,game_grid);
                    }
                    else
                    {
                        printf("This function is not efficient enough for a 8*8 grid...");
                        menu();
                    }

                }

            }
        }
    }
}

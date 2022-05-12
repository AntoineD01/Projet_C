//
// Created by Antoine Dupont on 07/04/2022.
//

#include "Takuzu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int size() /*Ask for the size of the Takuzu that the user wants*/
{
    int size;
    do {
        printf("Type the size of Takuzu that you want (only 4*4 and 8*8 are available): \n");
        scanf("%d",&size);
    }while(size != 4 && size != 8);

    return(size);
}

int empty(int s, int grid[s][s], int row, int column) /*Look if the cell is empty*/
{
    int valid;

    if (grid[row][column] == 10)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    return valid;
}

int full(int s, int grid[s][s]) /*Look if the grid is full or not*/
{
    int full = 1;
    for (int i=0; i<s; i++){
        for (int j = 0; j < s; j++) {
            if (grid[i][j] == 10)
            {
                full = 0;
                break;
            }
        }
    }
    return full;
}

int validity(int s, int solution[s][s], int game_grid[s][s],int row, int column, int value) /*Check if the value entered is same as in the solution*/
{
    int validity;
    if (value == solution[row][column])
    {
        validity = 1;
    }
    else
    {
        validity = 0;
    }
    return validity;
}

void display_matrix(int s, int grid[s][s]) /*Display the matrix*/
{
    for (int i=0; i<s; i++) {
        for (int j = 0; j < s; j++) {
            if (grid[i][j] == 10) {
                if (j != s - 1) {
                    printf("  ");
                }
                else {
                    printf("\n");
                }
            }
            else
            {
                if (j != s - 1) {
                    printf("%d ", grid[i][j]);
                }
                else {
                    printf("%d\n", grid[i][j]);
                }
            }
        }
    }
}

void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s]) /*Create the grid for the user*/
{
    for (int i=0; i < s; i++) {
        for (int j = 0; j < s; j++)
        {
            if (mask[i][j] == 1)
            {
                game_grid[i][j] = solution[i][j];
            }
            else
            {
                game_grid[i][j] = 10;
            }
        }
    }
}

char ask_column(int s) /*Ask the user in which column he wants to put his value*/
{
    char column;
    if (s==4)
    {
        do { /*Ask for the column if 4*4*/
            printf("Enter the column of the value you want (A to D): \n");
            scanf(" %c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'a' && column != 'b' &&
                 column != 'c' && column != 'd');
    }
    else
    {
        do { /*Ask for the column if 8*8*/
            printf("Enter the column of the value you want (A to H): \n");
            scanf(" %c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'E' && column != 'F' &&
                 column != 'G' && column != 'H' && column != 'a' && column != 'b' && column != 'c' && column != 'd' && column != 'e' && column != 'f' &&
                 column != 'g' && column != 'h');
    }
    return column;
}

int ask_row(int s) /*Ask the user in which row he wants to put his value*/
{
    int row;
    if (s==4)
    {
        do { /*Ask for the row*/
            printf("Enter the row of the value you want (1 to 4): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4);
    }
    else
    {
        do { /*Ask for the row*/
            printf("Enter the row of the value you want (1 to 8): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4 && row != 5 && row != 6 && row != 7 && row != 8);
    }
    return row;
}

int conv_l_to_nb(int s,char column) /*Transform the column to a value*/
{
    int j;
    if (column == 'a' || column == 'A') {
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

void generate_matrix(int s, int solution[s][s], int mask[s][s]) /*Create two matrices (solution and mask) according to the size using a library of solution and mask matrices*/
{
    int r;
    srand(time(0));
    r = (rand()%2); /*Generate a random number*/
    if (s==4)
    {
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
        if(r==0)
        {
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < s; j++) {
                    solution[i][j] = solution14[i][j];
                    mask[i][j] = mask14[i][j];
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
    {
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


void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives) /*Put the value in the cell requested by the user*/
{
    char column;
    int row,value,j,valid,same_solution,full1,back;
    int stop = 3;
    full1 = full(s,game_grid);

    if (full1 == 0) /*If the grid is not full*/
    {
        do{
            printf("\nWhat do you want to do next ?\n - Enter another value (press 1)\n - Have a hint on a value in the grid (press 2)\n - Go back to the main menu (press 3)\n");
            scanf("%d",&back);
        }while (back != 1 && back != 2 && back != 3);

        if (back == 3)
        {
            printf("\nYou're back in the main menu.\n\n");
            menu();
        }
        else
        {
            if (back == 2)
            {
                if (stop != 0)
                {
                    hint(s,solution,game_grid,mask,stop,lives);
                    stop-=1;
                    play(s,mask,solution,game_grid,lives);
                }
                else
                {
                    printf("You have no more hint...");
                }
            }
            else
            {
                column = ask_column(s);
                j = conv_l_to_nb(s, column); /*Convert the letter given by the user to the real column in the matrix*/


                row = ask_row(s);
                row-=1;  /*Convert the value given by the user to the real row in the matrix*/

                valid = empty(s, game_grid, row, j); /*Check if the cell is empty*/

                if (valid == 0) /*If the cell is not empty*/
                {
                    printf("The cell is not empty.\nTry again :\n");
                    play(s,mask, solution,game_grid,lives);
                }
                else /*If the cell is empty*/
                {
                    do {
                        printf("Enter the value you want to enter (1 or 0): \n");
                        scanf("%d", &value);
                    } while (value != 1 && value != 0);
                    same_solution = validity(s,solution,game_grid,row,j,value);


                    if (same_solution == 1) /*If the value correspond to the solution grid*/
                    {
                        game_grid[row][j] = value;
                        printf("You want to enter %d at the coordinate %c%d. This move is valid.\n", value, column, row+1);
                    }
                    else
                    {
                        why_wrong(s,solution,game_grid,row,j,value); /*Explain the error*/
                        lives-=1;
                        printf("You lost one life. You have now %d.\n\n",lives);
                    }

                    if (lives !=0) /*If no lives left*/
                    {
                        play(s,mask,solution,game_grid, lives);
                    }
                    else
                    {
                        printf("You've lost ! Try again !\n\n"); /*If there is some lives left*/
                        menu();
                    }
                }
            }
        }

    }
    else /*If the grid is full*/
    {
        printf("You've finished this grid, well done !\n\n");
        menu();
    }


}

void why_wrong(int s, int solution[s][s],int game_grid[s][s], int row, int column, int value) /*Explain what is error made by the user*/
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
                            printf("Your move could be right but do not correspond to the solution grid.\n");
                        }
                    }
                }
            }
        }
    }
}

void hint(int s,int solution[s][s],int game_grid[s][s],int mask[s][s], int stop, int lives) /*Display a hint to the user*/
{
    char column1 = ask_column(s);
    int column = conv_l_to_nb(s,column1);

    int row = ask_row(s);
    row-=1;

    int hint_value, empty1;
    empty1 = empty(s,game_grid,row,column);

    if (empty1==1)
    {
        hint_value = solution[row][column];
        printf("The value at %c%d is %d.\n",column1,row+1,hint_value);
    }
    else
    {
        printf("The cell %c%d is not empty so you already know it's value !\n\n",column1,row+1);
        play(s,mask,solution,game_grid,lives);
    }
}

void play(int s, int mask[s][s], int solution[s][s],int game_grid[s][s], int lives) /*Play the Takuzu*/
{
    display_matrix(s,game_grid);
    enter_value(s,mask,solution,game_grid,lives);
}

void resolve_automatically(int s, int game_grid[s][s], int solution[s][s]) /*Resolve a grid automatically*/
{
    int empty1,full1;
    char c;
    display_matrix(s,game_grid);
    do{
        printf("Enter n to see the next resolution :");
        scanf(" %c",&c);
    }while (c != 'n');
    c = 'a';
    full1 = full(s,game_grid);
    do{
        for (int i=0; i<s; i++)
        {
            for (int j=0; j<s; j++)
            {
                empty1 = empty(s,game_grid,i,j);
                if (empty1 == 1)
                {
                    game_grid[i][j]=solution[i][j];
                    display_matrix(s,game_grid);
                    while (c != 'n')
                    {
                        printf("Enter n to see the next resolution :");
                        scanf(" %c",&c);
                    }
                    c = 'a';
                    full1 = full(s,game_grid);
                }
            }
        }
    }while(full1==0);
    printf("\nYou're back to the main menu.\n");
    menu();
}
/*Work in progress*/

void menu() /*The main menu function*/
{
    int s, choice;
    s = size();
    int solution[s][s];
    int mask[s][s];
    int game_grid[s][s];
    generate_matrix(s,solution,mask);

    do{
        printf("Do you want to :\n - Resolve automatically a grid (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)");
        scanf("%d",&choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    if (choice==1)
    {
        game_grid_c(s,mask,solution,game_grid);
        resolve_automatically(s, game_grid, solution);
    }
    else
    {
        if (choice==2)
        {
            generate_mask(s,solution,mask); /*TO BE DONE*/
        }
        else
        {
            int lives = 3;
            game_grid_c(s,mask,solution, game_grid);
            play(s,mask, solution,game_grid,lives);
        }
    }
}

/* To be done*/

void generate_mask(int s,int solution[s][s], int mask[s][s]) /*Display a grid and it mask*/
{
    printf("\nThis is the solution grid :\n\n");
    display_matrix(s,solution);
    printf("\nThis is the mask grid :\n\n");
    display_matrix(s,mask);
    printf("\n");
    menu();
}



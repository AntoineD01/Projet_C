//
// Created by Antoine Dupont on 07/04/2022.
//

#include "Takuzu.h"
#include <stdio.h>

/*Already done*/

int size() /*Ask for the size of the Takuzu that the user wants*/
{
    int size;
    do {
        printf("Type the size of Takuzu that you want (only 4 and 8 are available): \n");
        scanf("%d",&size);
    }while(size != 4 && size != 8);
    return(size);
}

void display_matrix1(int s, int grid[s][s]) /*Display the matrix*/
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

int empty(int s, int grid[s][s], int row, int column ) /*Look if the cell is empty*/
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

int conv_l_to_nb(int s,int column) /*Transform the column to a value*/
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

void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lifes)
{
    char column;
    int row,value,j,valid,same_solution;

    column = ask_column(s);
    j = conv_l_to_nb(s, column); /*Convert the letter given by the user to the real column in the matrix*/

    row = ask_row(s);
    row-=1;  /*Convert the value given by the user to the real row in the matrix*/

    valid = empty(s, game_grid, row, j); /*Check if the cell is empty*/
    printf(" Row : %d\n Column : %d\n Valid : %d\n",row,j,valid); /*TO BE REMOVED*/

    if (valid == 0) /*If the cell is not empty*/
    {
        printf("The cell is not empty.\nTry again :\n");
        play(s,mask, solution,game_grid,lifes);
    }
    else /*If the cell is empty*/
    {
        do {
            printf("Enter the value you want to enter (1 or 0): \n");
            scanf("%d", &value);
        } while (value != 1 && value != 0);
        same_solution = validity(s,solution,game_grid,row,j,value);


        if (same_solution == 1)
        {
            game_grid[row][j] = value;
            printf("You want to enter %d at the coordinate %c%d. This move is valid.\n", value, column, row);
        }
        else
        {
            lifes-=1;
            printf("The value entered is wrong.\nYou lost one life. You have now %d.\n\n",lifes);
        }

        if (lifes !=0)
        {
            play(s,mask,solution,game_grid, lifes);
        }
        else
        {
            printf("You've lost ! Try again !\n\n");
            menu();
        }
    }


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

char ask_column(int s)
{
    char column;
    if (s==4)
    {
        do { /*Ask for the column if 4*4*/
            printf("Enter the column of the value you want to enter (A to D): \n");
            scanf("%c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'a' && column != 'b' &&
                 column != 'c' && column != 'd');
        printf("You choose column %c.\n", column);
    }
    else
    {
        do { /*Ask for the column if 8*8*/
            printf("Enter the column of the value you want to enter (A to H): \n");
            scanf("%c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'E' && column != 'F' &&
                 column != 'G' && column != 'H' && column != 'a' && column != 'b' && column != 'c' && column != 'd' && column != 'e' && column != 'f' &&
                 column != 'g' && column != 'h');
        printf("You choose column %c.\n", column);
    }
    return column;
}

int ask_row(int s)
{
    int row;
    if (s==4)
    {
        do { /*Ask for the row*/
            printf("Enter the row of the value you want to enter (1 to 4): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4);
        printf("You choose row %d.\n", row);
    }
    else
    {
        do { /*Ask for the row*/
            printf("Enter the row of the value you want to enter (1 to 8): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4 && row != 5 && row != 6 && row != 7 && row != 8);
        printf("You choose row %d.\n", row);
    }
    return row;
}

void play(int s, int mask[s][s], int solution[s][s],int game_grid[s][s], int lifes) /*Play the Takuzu*/
{
    display_matrix1(s,game_grid);
    enter_value(s,mask,solution,game_grid,lifes);
}

/*Work in progress*/

void menu() /*The main menu function*/
{
    printf("Hello player, welcome to Takuzu !\n");
    int s, choice;
    s = size();
    int solution[8][8]={
            {1, 0, 1, 1, 0,1 ,0,0},
            {1, 0, 1, 0, 1,0 ,0,1},
            {0, 1, 0, 1, 1,0 ,1,0},
            {0, 1, 0, 1, 0,1 ,1,0},
            {1, 0, 1, 0, 0,1 ,0,1},
            {0, 1, 0, 0, 1,0 ,1,1},
            {0, 0, 1, 1, 0,1 ,1,0},
            {1, 1, 0, 0, 1,0 ,0,1},
    };
    int mask[8][8]={
            {1, 0, 1, 1, 0,1 ,0,1},
            {0, 0, 1, 0, 0,0 ,0,0},
            {1, 0, 0, 0, 0,0 ,0,1},
            {1, 0, 1, 0, 0,1 ,1,0},
            {1, 0, 0, 0, 1,0 ,0,1},
            {0, 0, 0, 0, 1,0 ,0,0},
            {0, 1, 1, 1, 1,1 ,0,0},
            {0, 1, 0, 1, 0,0 ,1,0},
    };
    int game_grid[s][s];

    do{
        printf("Do you want to :\n - Enter a mask manually (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)");
        scanf("%d",&choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    if (choice==1)
    {
        enter_mask(s,mask);
    }
    else
    {
        if (choice==2)
        {
            generate_mask(s,mask);
        }
        else
        {
            int lifes = 3;
            game_grid_c(s,mask,solution, game_grid);
            play(s,mask, solution,game_grid,lifes);
        }
    }
}

void why_wrong(int s, int solution[s][s],int game_grid[s][s], int row, int column, int value)
{
    if (game_grid[row][column] == 0 && game_grid[row][column])
    {

    }
}

/* To be done*/

void generate_mask(int s,int m[s][s]) /*Generate a mask*/
{
    printf("TO BE DONE");
}


void enter_mask(int s, int mask[s][s])
{
    printf("TO BE DONE");
}
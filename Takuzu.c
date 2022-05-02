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
            if (grid[i][j] != 0 && grid[i][j] != 1) {
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
                j = 3;
            }
        }
    }
    return j;
}

void display_matrix(int s, int mask[s][s], int solution[s][s]) /*Display the matrix using mask and solution*/
{
    for (int i=0; i<s; i++)
    {
        for (int j=0; j<s; j++)
        {
            if (mask[i][j]==1)
            {
                if (j!=s-1)
                {
                    printf("%d ",solution[i][j]);
                }
                else
                {
                    printf("%d\n",solution[i][j]);
                }
            }
            else
            {
                if (j!=s-1)
                {
                    printf("  ");
                }
                else
                {
                    printf("\n");
                }
            }
        }
    }
}

int empty(int s, int mask[s][s], int row, int column ) /*Look if the cell is empty*/
{
    int valid;

    if (mask[row][column] == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    return valid;
}

/*Work in progress*/

void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s])
{
    for (int i=0; i<s; i++) {
        for (int j = 0; j < s; j++)
        {
            if (mask[i][j] == 1)
            {
                game_grid[i][j] = solution[i][j];
            }
            else
            {
                game_grid[i][j] = 5;
            }
        }
    }
}





void menu() /*The main menu function*/
{
    printf("Hello player, welcome to Takuzu\n");
    int s, choice;
    s = size();
    int mask[4][4]={
            {1, 0, 0, 0},
            {0, 0, 1, 0},
            {1, 0, 1, 1},
            {0, 1, 0, 0}
    };
    int solution[4][4]= {
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 1}
    };
    int game_grid[4][4];

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
            play(s,mask, solution);
        }
    }
}

void play(int s, int mask[s][s], int solution[s][s]) /*Play the Takuzu*/
{
    display_matrix(s,mask,solution);
    enter_value(s,mask,solution);
}

void enter_value(int s, int mask[s][s], int solution[s][s])
{
    char column;
    int row,value,j;
    int valid;
    if (s==4) { /*The case for the 4*4*/

        do { /*Ask for the column*/
            printf("Enter the column of the value you want to enter (A to D): \n");
            scanf("%c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'a' && column != 'b' &&
                 column != 'c' && column != 'd');
        printf("You choose column %c.\n", column);
        j = conv_l_to_nb(s, column); /*Convert the letter given by the user to the real column in the matrix*/

        do { /*Ask for the row*/
            printf("Enter the row of the value you want to enter (1 to 4): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4);
        printf("You choose row %d.\n", row);
        row-=1;  /*Convert the value given by the user to the real row in the matrix*/

        valid = empty(4, mask, row, j); /*Check if the cell is empty*/

        printf(" Row = %d\n column = %d\n Valid= %d\n",row,j,valid); /* TO BE REMOVED*/

        /*NOT WORKING*/
        if (valid == 0) /*If the cell is not empty*/
        {
            printf("The cell is not empty\n Try again :\n");
            display_matrix(4,mask,solution);
            play(s,mask, solution);
        }
        else /*If the cell is empty*/
        {
            do {
                printf("Enter the value you want to enter (1 or 0): \n");
                scanf("%d", &value);
            } while (value != 1 && value != 0);
            printf("You want to enter %d at the coordinate %c%d.\n", value, column, row);
            printf("%d",solution[row][j]);
        }
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
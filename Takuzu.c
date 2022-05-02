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

void display_matrix(int s, int mask[s][s], int solution[s][s]) /*Display the matrix*/
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (mask[i][j]==1)
            {
                if (j!=3)
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
                if (j!=3)
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

int empty(int s, int mask[s][s], int a, int b ) /*Look if the cell is empty*/
{
    int valid;

    if (mask[a][b] == 0)
    {
        valid = 0;
    }
    else
    {
        valid = 1;
    }
    return valid;
}

/*Work in progress*/

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
    do{
        printf("Do you want to :\n - Enter a mask manually (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)");
        scanf("%d",&choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    if (choice==1)
    {
        enter_mask(s,mask);
        display_matrix(s,mask,solution);
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
    int valid =0;
    if (s==4) { /*The case for the 4*4*/

        do { /*Ask for the column*/
            printf("Enter the column of the value you want to enter (A to D): \n");
            scanf("%c", &column);
        } while (column != 'A' && column != 'B' && column != 'C' && column != 'D' && column != 'a' && column != 'b' &&
                 column != 'c' && column != 'd');
        printf("You choose column %c.\n", column);

        do { /*Ask for the row*/
            printf("Enter the row of the value you want to enter (1 to 4): \n");
            scanf("%d", &row);
        } while (row != 1 && row != 2 && row != 3 && row != 4);
        printf("You choose row %d.\n", row);

        if (column == 'a') { /*Transform the row to a value*/
            j = 0;
        } else {
            if (column == 'b') {
                j = 1;
            } else {
                if (column == 'c') {
                    j = 2;
                } else {
                    j = 3;
                }
            }
        }

        valid = empty(4, mask, row, j);

        if (valid == 1)
        {
            do {
                printf("Enter the value you want to enter (1 or 0): \n");
                scanf("%d", &value);
            } while (value != 1 && value != 0);
            printf("You want to enter %d at the coordinate %c%d.\n", value, column, row);
        }
        else
        {
            printf("The cell is not empty");
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
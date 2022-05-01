//
// Created by Antoine Dupont on 07/04/2022.
//

#include "Takuzu.h"
#include <stdio.h>


void menu() /*The main menu function*/
{
    printf("Hello player, welcome to Takuzu\n");
    int s, choice;
    s = size();
    int mask[s][s];
    int solution[4][4]= {
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 1}
    };
    do{
        printf("Do you want to :\n - Enter a mask manually (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)\n");
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


void generate_mask(int s,int m[s][s]) /*Generate a mask*/
{
    printf("TO BE DONE");
}


void play(int s, int mask[s][s], int solution[s][s]) /*Play the Takuzu*/
{
    display_matrix(s,mask,solution);
    enter_value(s,mask,solution);
}

int return_the_ascii(char c)
{
    return c;
}

void enter_value(int s, int mask[s][s], int solution[s][s])
{
    char column;
    int row,value;
    if (s==4)
    {
        do{
            printf("Enter the coordinate of the value you want to enter (A to D and 1 to 4): ");
            scanf("%c%d",&column,&row);
        }while(row != 1 && row != 2 && row != 3 && row != 4);

        do{
            printf("Enter the value you want to enter : ");
            scanf("%d",&value);
        }while(row != 1 && row != 2 && row != 3 && row != 4);
    }

}

void enter_mask(int s, int mask[s][s])
{

}
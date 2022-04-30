//
// Created by Antoine Dupont on 07/04/2022.
//

#include "Takuzu.h"
#include <stdio.h>


void menu() /*The main menu function*/
{
    printf("Hello player, welcome to Takuzu\n");
    int play;
    do {
        printf("If you want to play, press 1\n");
        scanf("%d",&play);
    }while(play != 1);
    if (size()==4)
    {
        matrix_four();
    }
    else
    {
        matrix_eight();
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


void matrix_four() /*Display the 4*4 matrix*/
{
    int matrix4[4][4]={
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 1}
    };
    int mask4[4][4]={
            {1, 0, 0, 0},
            {0, 0, 1, 0},
            {1, 0, 1, 1},
            {0, 1, 0, 0}
    };
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (mask4[i][j]==1)
            {
                if (j!=3)
                {
                    printf("%d ",matrix4[i][j]);
                }
                else
                {
                    printf("%d\n",matrix4[i][j]);
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

void matrix_eight() /*Display the 8*8 matrix*/
{
    int matrix8[8][8]={
            {1, 0, 1, 1, 0,1 ,0,0},
            {1, 0, 1, 0, 1,0 ,0,1},
            {0, 1, 0, 1, 1,0 ,1,0},
            {0, 1, 0, 1, 0,1 ,1,0},
            {1, 0, 1, 0, 0,1 ,0,1},
            {0, 1, 0, 0, 1,0 ,1,1},
            {0, 0, 1, 1, 0,1 ,1,0},
            {1, 1, 0, 0, 1,0 ,0,1},
    };
    int mask8[8][8]={
            {1, 0, 1, 1, 0,1 ,0,1},
            {0, 0, 1, 0, 0,0 ,0,0},
            {1, 0, 0, 0, 0,0 ,0,1},
            {1, 0, 1, 0, 0,1 ,1,0},
            {1, 0, 0, 0, 1,0 ,0,1},
            {0, 0, 0, 0, 1,0 ,0,0},
            {0, 1, 1, 1, 1,1 ,0,0},
            {0, 1, 0, 1, 0,0 ,1,0},
    };
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (mask8[i][j]==1)
            {
                if (j!=7)
                {
                    printf("%d ",matrix8[i][j]);
                }
                else
                {
                    printf("%d\n",matrix8[i][j]);
                }
            }
            else
            {
                if (j!=7)
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
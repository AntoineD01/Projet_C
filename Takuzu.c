//
// Created by Antoine Dupont on 07/04/2022.
//

#include "Takuzu.h"
#include <stdio.h>

void menu()
{
    printf("Hello player, welcome to Takuzu\n");
    int play;
    do {
        printf("If you want to play, press 1\n");
        scanf("%d",&play);
    }while(play != 1);
}

void display_matrix()
{
    int size;
    do {
        printf("Type the size of Takuzu that you want (only 4 and 8 are available): \n");
        scanf("%d",&size);
    }while(size != 4 && size != 8);

    if (size==4)
    {
        int matrix4[4][4]={
                {1, 0, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 1}
        };
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++)
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
        }
    }
    else
    {

    }
}
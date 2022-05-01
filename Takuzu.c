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
    if (s==4)
    {
        do{
            printf("Do you want to :\n - Enter a mask manually (press 1)\n - Automatically generate a mask (press 2)\n - Play (press 3)\n");
            scanf("%d",&choice);
        }while(choice != 1 && choice != 2 && choice != 3);
        if (choice==1)
        {
            enter_mask();
        }
        else
        {
            if (choice==2)
            {
                generate_mask();
            }
            else
            {
                play(s);
            }
        }
    }
    else
    {

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
    int solution4[4][4]={
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
                    printf("%d ",solution4[i][j]);
                }
                else
                {
                    printf("%d\n",solution4[i][j]);
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
    int solution8[8][8]={
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
                    printf("%d ",solution8[i][j]);
                }
                else
                {
                    printf("%d\n",solution8[i][j]);
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

void enter_mask()
{
    printf("TO BE DONE");
}

void generate_mask()
{
    printf("TO BE DONE");
}


void play(int a)
{
    if (a==4)
    {
        matrix_four();
    }
    else
    {
        matrix_eight();
    }
}
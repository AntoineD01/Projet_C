//
// Created by Antoine Dupont on 07/04/2022.
//

#ifndef PROJETC_TAKUZU_H
#define PROJETC_TAKUZU_H

void menu();
int size();
void display_matrix1(int s, int grid[s][s]);
void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s]);
void enter_mask(int s, int mask[s][s]);
void generate_mask(int s,int mask[s][s]);
void play(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lifes);
void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lifes);
int empty(int s, int grid[s][s], int row, int column);
int conv_l_to_nb(int s,int column);
int validity(int s, int solution[s][s], int game_grid[s][s], int row, int column, int value);
char ask_column(int s);
int ask_row(int s);
void why_wrong(int s, int solution[s][s],int game_grid[s][s], int row, int column, int value);

#endif //PROJETC_TAKUZU_H

//
// Created by Antoine Dupont on 07/04/2022.
//

#ifndef PROJETC_TAKUZU_H
#define PROJETC_TAKUZU_H

void menu();
int size();
void display_matrix(int s, int grid[s][s]);
void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s]);
void generate_mask(int s,int mask[s][s]);
void play(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives);
void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives);
int empty(int s, int grid[s][s], int row, int column);
int full(int s, int grid[s][s]);
int conv_l_to_nb(int s,char column);
int validity(int s, int solution[s][s], int game_grid[s][s], int row, int column, int value);
char ask_column(int s);
int ask_row(int s);
void why_wrong(int s, int solution[s][s],int game_grid[s][s], int row, int column, int value);
void generate_matrix(int s, int solution[s][s], int mask[s][s]);
void hint(int s,int solution[s][s],int game_grid[s][s], int mask[s][s], int stop, int lives);
void resolve_automatically(int s, int game_grid[s][s], int solution[s][s]);

#endif //PROJETC_TAKUZU_H

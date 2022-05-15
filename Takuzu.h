//
// Project Takuzu provided by Antoine Dupont et Alexandre Poujol
//
//Declaration of the functions

#ifndef PROJETC_TAKUZU_H
#define PROJETC_TAKUZU_H

void menu();
int size();
void display_matrix(int s, int grid[s][s]);
void game_grid_c(int s, int mask[s][s], int solution[s][s], int game_grid[s][s]);
void play(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives, int stop);
void enter_value(int s, int mask[s][s], int solution[s][s], int game_grid[s][s], int lives, int stop);
int empty(int s, int grid[s][s], int row, int column);
int full(int s, int grid[s][s]);
int conv_l_to_nb(char column);
int validity(int s, int solution[s][s], int row, int column, int value);
char ask_column(int s);
int ask_row(int s);
void why_wrong(int s, int game_grid[s][s], int row, int column);
void generate_matrix(int s, int solution[s][s], int mask[s][s]);
int hint(int s,int solution[s][s],int game_grid[s][s], int stop);
void resolve_automatically(int s, int game_grid[s][s], int solution[s][s]);
void enter_a_mask(int s, int mask[s][s]);
void create_solution(int s, int solution[s][s]);
void grid_generator(int s, int game_grid[s][s]);
void mask_generator(int s, int mask[s][s]);


void solution_generator(int s, int game_grid[s][s]);
int bina_to_deci(int binary);

#endif //PROJETC_TAKUZU_H

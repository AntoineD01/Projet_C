//
// Created by Antoine Dupont on 07/04/2022.
//

#ifndef PROJETC_TAKUZU_H
#define PROJETC_TAKUZU_H

void menu();
int size();
void display_matrix(int s, int mask[s][s], int solution[s][s]);
void enter_mask(int s, int mask[s][s]);
void generate_mask(int s,int mask[s][s]);
void play(int s, int mask[s][s], int solution[s][s]);
void enter_value(int s, int mask[s][s], int solution[s][s]);
int return_the_ascii(char c);

#endif //PROJETC_TAKUZU_H

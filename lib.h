#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int tour;
char *joueur1;
char *joueur2;

void my_putchar(int n, char c);
void my_putstr(int n, char *str);
void my_putnbr(int n);
char *my_strcat(char *dest, const char *src);
int my_strlen(const char *str);
void initialisation();
int my_strcmp(char *s1, char *s2);
void brain();
void initialisation_array();
void affichage(char **array);
void game(char **array);
int my_getnbr(char str);
void map(char* zone, char **array);
void check(char **array, char symbole);
void win(char **array, char symbole);
void check_ligne(char **array, char symbole);
void check_colonne(char **array, char symbole);
void check_diagonal(char **array, char symbole);
void someone_win();
void relancer_le_game();
void jeu();

#endif
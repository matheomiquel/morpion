#include "lib.h"
#include "stdio.h"
void brain()
{
    jeu();
    initialisation_array();
}

void jeu(){
    tour = 0;
    joueur1 = malloc(sizeof(char) * 10);
    joueur2 = malloc(sizeof(char) * 10);
    system("clear");
    my_putstr(1, "nom du joueur 1: ");
    read(1, joueur1, 11);
    system("clear");
    my_putstr(1, "nom du joueur 2: ");
    read(1, joueur2, 11);
}

void initialisation_array()
{
    system("clear");
    char **array;
    array = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 4; i++)
        array[i] = malloc(sizeof(char) * 4);
    for (int ligne = 0; ligne < 4; ligne++)
        for (int colonne = 1; colonne < 5; colonne++)
        {
            array[ligne][colonne] = '.';
            if (colonne == 4)
                array[ligne][colonne] = '\n';
        }
    affichage(array);
}

void affichage(char **array)
{
    for (int ligne = 0; ligne < 4; ligne++)
        for (int colonne = 0; colonne < 5; colonne++)
        {
            if (colonne == 0)
                array[ligne][colonne] = ligne + 48;
            if (ligne == 0 && colonne < 4)
                array[ligne][colonne] = colonne + 48;
            my_putchar(1, array[ligne][colonne]);
        }
    game(array);
}

void game(char **array)
{
    char *zone;

    zone = malloc(sizeof(char) * 11);
    my_putstr(1, "au tour de: ");
    if ((tour % 2) == 0)
        my_putstr(1, joueur1);
    else
        my_putstr(1, joueur2);
    read(1, zone, 2);
    if (zone[0] < 52 && zone[0] > 48 && zone[1] < 52 && zone[1] > 48 ){
        map(zone, array);
        free(zone);
    }
    else {
        if(tour != 0){
            system("clear");
            my_putstr(1, "\nvous devez mettre un nombre entre 1 et 3.\n");
            free(zone);
            affichage(array); 
        }
        else{
            system("clear");
            affichage(array);
        }
    }
}

void map(char *zone, char **array)
{
    int x;
    int y;
    char symbole;
    system("clear");
    if ((tour % 2) == 0)
        symbole = 'X';
    else
        symbole = '0';
    x = zone[1] - 48;
    y = my_getnbr(zone[0]);
    my_putchar(1, '\n');
    my_putchar(1, zone[1]);
    my_putnbr(x);
    my_putchar(1, '\n');
    if (array[x][y] != 'X' && array[x][y] != '0')
    {
        array[x][y] = symbole;
        tour++;
        check(array, symbole);
    }
    else{
        my_putstr(1, "\ny'a deja ce symbole frere.\n");
    }
    affichage(array);
}

void check(char **array, char symbole){
    win(array, symbole);
    if(tour == 9){
        system("clear");
        my_putstr(1, "c'est la fin jolie égalité les gars.\n");
        relancer_le_game();
    }
}

void win(char **array, char symbole){
    check_colonne(array, symbole);
    check_ligne(array, symbole);
    check_diagonal(array, symbole);
}

void check_colonne(char **array, char symbole){
    int result;
        for(int ligne = 1; ligne < 4; ligne++){
        result = 0;
            for(int colonne = 1;colonne < 4; colonne++){
                if(array[ligne][colonne] == symbole){
                    result++;
                    if(result == 3)
                        someone_win();
            }
        }
    }
}

void check_ligne(char **array, char symbole){
    int result;
        for(int colonne = 1; colonne < 4; colonne++){
        result = 0;
            for(int ligne = 1;ligne < 4; ligne++){
                if(array[ligne][colonne] == symbole){
                    result++;
                    if(result == 3)
                        someone_win();
            }
        }
    }
}

void check_diagonal(char **array, char symbole){
    int result;
    result = 0;
    int truc = 1;
    int chose = 3;
    for(int i = 1;i < 4;i++)
        if(array[i][i] == symbole) {
            result++;
            if(result == 3)
            someone_win();    
        }
    result = 0;
    for(int i = 1;i < 4 ;i++){
           if(array[chose][truc] == symbole) {
                result++;
            if(result == 3)
                someone_win();    
            truc++;
            chose--;
        }
    }
}

void someone_win(){
    system("clear");
    my_putstr(1, "bravo ");
    if ((tour % 2) == 1)
        my_putstr(1, joueur1);
    else
        my_putstr(1, joueur2);
    my_putstr(1, "tu as facilement écraser ton adversaire !!!\n");
    relancer_le_game();
}

void relancer_le_game(){
    char *result;

    result = malloc(sizeof(char) * 1);
    my_putstr(1, "Pour continuer mettez 1.\nPour arrêter mettez 2.\n");
    read(1,result,1);
        if(result[0] == '1'){
            tour = 0;
            system("clear");
            initialisation_array();
        } else {
            free(joueur1);
            free(joueur2);
            system("clear");
            exit(0);
        }
}

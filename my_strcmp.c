/*
** ETNA PROJECT, 18/02/2019 by soen_l miquel_m
** my_strcmp.c
** File description:
**     my_strcmp
*/

#include "lib.h"
int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] != '\0' || s2[i] != '\0'){
	if(s1[i] > s2[i]){
	    return(1);
	}
	else if(s1[i] < s2[i]){
	    return(-1);
	}
	else
	    i++;
      }
    return(0);
}

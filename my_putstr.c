#include "lib.h"

void my_putstr(int n, char *str){
  
    for(int i = 0; str[i] != '\0' ;i++)
        my_putchar(n,str[i]);
}

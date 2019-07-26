#include "lib.h"

char *my_strcat(char *dest,const char *src){
  
    int i = 0;
    int a = (my_strlen(dest));
    for(i = 0; src[i] != '\0'; i++){
        dest[a + i] = src[i];
    }
    
    dest[a + i] = '\0';

       return(dest);
}


#include "lib.h"

void my_putchar(int n, char c){

    write(n, &c, 1);
}

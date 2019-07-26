#include "lib.h"
int my_getnbr(char str) {
  int result = 0;
  int i = 0;
  int neg = 0;
  while (str == 45 || str == 43) {
    if (str == 45)
      neg++;
    neg = neg % 2;
    i++;
  }
    result = result + str - 48;
  if (neg == 1)
    result = result * -1;
  return result;
}

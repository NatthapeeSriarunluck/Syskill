
#include <stdio.h>

int parity_check(int x);

int parity_check(int x){
 x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x01;
}

int main(){
  int x;
  scanf("%d", &x );
  printf("%d", parity_check(x));
  return 0;
}
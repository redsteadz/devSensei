#include <iostream>

int* divisors (int num, size_t *sz) {
  int s = 0;
  for (int i = 1; i <= num; i++){
    if (num % i == 0) {
      s++;
    }
  }
  
  int *arr = new int[s+1];
  
  int cnt = 0;
  for (int i = 1; i <= num; i++){
    if (num % i == 0) {
      arr[cnt++] = i;
    }
  }
  *sz = s;
  
  return arr;
}

int main (int argc, char *argv[]) {
size_t s;
int *a = divisors(10, &s);
  for (int i = 0; i < s; i++){
    std::cout << *(a + i) << std::endl;
  }
  return 0;
}

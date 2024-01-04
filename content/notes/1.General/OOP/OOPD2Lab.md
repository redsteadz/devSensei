---
id: OOPD2Lab
aliases: []
tags: []
date: "2024-01-04"
title: OOPD2Lab
---
![[notes/1.General/OOP/attachments/Pasted image 20240104161210.png]]

```cpp 

void draw_solid_line(int size, char sym);
void draw_hollow_line(int size, char sym);

void draw_rectangle(int len, int wide, char sym);

int main(void) {
  int length, width;
  char sym;
  cout << "Enter length and width of rectangle >";
  cin >> length >> width;
  cout << "Enter symbol >";
  cin >> sym;
  draw_rectangle(length, width, sym);
  return 0;
}
void draw_solid_line(int size, char sym) {
  // Write your Code Here
  while (size-- > 0) {
    cout << sym;
  }
  cout << endl;
}
void draw_hollow_line(int size, char sym) {
  // Write your Code Here
  cout << sym;
  size -= 2;
  while (size-- > 0) {
    cout << " ";
  }
  cout << sym << endl;
}
void draw_rectangle(int len, int wide, char sym) {
  int i;
  draw_solid_line(wide, sym);
  if (len > 2) {
    for (i = 1; i <= len - 2; i++)
      draw_hollow_line(wide, sym);
  }
  draw_solid_line(wide, sym);
}


```

2. Write function divisors that receive an integer number and return its divisors using pointer
array on main including 1 and itself.

```cpp 
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
```

3. Write a logical function perfect_Square that receives a positive integer number and checks if it is a perfect square or not.
Note: perfect square numbers are 4, 9,16,25,36 etc….
Write a main function that makes use of the perfect_Square function to find and print all perfect
squares between n1 and n2. n1 and n2 are end values of a range introduced by the user

```cpp
bool isPerfectSquare(int n){
  return sqrt(n) == int(sqrt(n));
}

void printPerfectSquares(int n1, int n2){
  for (int i = n1; i <= n2; i++){
    if (isPerfectSquare(i))
      std::cout << i << std::endl;
  }
}

int main (int argc, char *argv[]) {
  

  return 0;
}

```

4. Write a logical function, is_prime, that takes an integer number and determines if the number is prime or not.

```cpp
bool isPrime(int n) {
  for (int i = 2; i < n; i++){
    if (n % i == 0) return false;
  }
  return true;
}
   
```
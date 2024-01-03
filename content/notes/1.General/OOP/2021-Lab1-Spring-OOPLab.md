---
id: 2021-Lab1-Spring-OOPLab
aliases:
  - Lab 1
tags: []
date: "2024-01-03"
title: 2021-Lab1-Spring-OOPLab
---

# Lab 1

## Task 1 
Write the C++ code for a function swap(), which swaps the values of two integer variables.
Note: you cannot create global variables, and cannot pass integer variables by reference in the function.
Hint: Pointers

```cpp 

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main (int argc, char *argv[]) {
  int a, b;
  std::cin >> a >> b;
  cout << "a = " << a << " b = " << b << endl;

  swap(&a, &b);

  cout << "a = " << a << " b = " << b << endl;

  return 0;
}


```

## Task 2 
Given two integers x and y, find their sum using pointers.

```cpp 

int sum(int *a, int *b) {
  return *a + *b;
}

int main (int argc, char *argv[]) {
  int a, b;
  std::cin >> a >> b;
  cout << "a = " << a << " b = " << b << endl;
  cout << "sum = " << sum(&a, &b) << endl;

  return 0;
}

```

Run this code and check if there is any issue, also detect dangling pointer and memory leak.

```cpp
    int *ptr = new int;  // Allocating memory for an integer
    std::cout << "Enter Int Value: ";
    std::cin >> *ptr;
    std::cout << "Value is: " << *ptr << std::endl;
    std::cout << "Pointer Value is: " << ptr << std::endl;
    
    delete ptr;  // Deallocating memory

    // Accessing memory after deletion (Dangling Pointer)
    // This is undefined behavior and can lead to crashes or unexpected results
    std::cout << "After Del,,Value is: " << *ptr << std::endl;
    std::cout << "After Del,,Pointer Value is: " << ptr << std::endl;

    // Dynamically allocating a float without assigning it to any pointer
    // This causes a memory leak as there's no way to free this memory
    std::cout << "Dynamically occupied Float Variable: " << new float << std::endl;

    int *ptr1 = new int;  // Allocating memory for an integer
    *ptr1 = 9;
    std::cout << *ptr1 << std::endl;

    // Incrementing the pointer causes a memory leak
    // The original memory allocated for ptr1 is lost, and there's no way to free it
    ptr1++;
    std::cout << *ptr1 << std::endl;

    // There's no delete statement for ptr1, causing a memory leak
    // If you intended to deallocate memory, you should use delete ptr1;
    
    std::cout << "Find Memory Leak" << std::endl;

    // It's good practice to delete dynamically allocated memory at the end of the program
    // to avoid memory leaks, but in this case, ptr1 is already lost due to the increment operation
    // delete ptr1;

    return 0;
```

## Task 3 
Introduce 2 variables i (int), j (float) and initialize to 5, 1.5 respectively.
Introduce 2 variables xPtr (int*), yPtr (float*) and assign address of i, j respectively.
Print values of i, j and addresses in xPtr, yPtr.
xPtr ++;  yPtr ++; 
Print addresses in xPtr,yPtr.
xPtr --; yPtr --; 
Print addresses in xPtr, yPtr.
xPtr = xPtr + 3; yPtr = yPtr + 4;
Print addresses in xPtr, yPtr.

## Task 6:
Create two float pointers in the main function and write C++ code for the following functions and call them in order from main.
1- A function allocate(), which creates dynamic variables length and width and assigns their addresses to pointers created in main.
2- A function input() that takes input from the user in already created dynamic variables length and width.
3- A function Print() that prints values of dynamic variables length and width.
4- A function Area() that takes dynamic variables as parameters and returns the area of the rectangle.
5- A function deallocate() which deallocates the memory of dynamic variables length and width and update pointers too.

```cpp

float* allocate(){
  return new float;
}

void input(float *a){
  cin >> *a;
}

void print(float a){
  cout << a;
}

float area(float *a, float *b){

  return (*a)*(*b);
}

void deallocate(float *a){
  delete a;
}

int main() {
    float *x = allocate();
    float *y = allocate();
    input(x);
    input(y);
    print(area(x,y));
    return 0;
}

```

# All Lab Manuals Lab 1 ?

## Q2 
Q2. If you have two fractions, a/b and c/d, their sum can be obtained from the
formula a/b + c/d = a*d + b*c / b*d
For example, 1/4 + 2/3 is
1/4 + 2/3 = 1*3 + 4*2 / 4*3 = 3+8 / 12 = 11/12
Write a program that encourages the user to enter two fractions and then displays their sum
in fractional form. The interaction with the user might look like this:
Enter first fraction:
1/2 Enter Second
Fraction: 2/5 Sum =
9/10

```cpp
int* pairs(string frac){
  string buf;
  int *set = new int[2];
  for (int i = 0; i < frac.length(); i++) {
    buf += frac[i];
    if (frac[i] == '/') {
      set[0] = stoi(buf);
      buf.clear();
    }
  }
  set[1] = stoi(buf);
  return set;
}

int main (int argc, char *argv[]) {
  string frac;

  cin >> frac;
  
  int *set = pairs(frac);
  
  cin >> frac;
  int *set2 = pairs(frac);
  
  int newSet[2];
  newSet[0] = set[0]*set2[1] + set[1]*set2[0];
  newSet[1] = set[1]*set2[1];

  cout << newSet[0] << "/" << newSet[1] << endl;
  delete[] set;
  delete[] set2;
  return 0;
}

```

## Q8
Q8. Suppose you give a dinner party for six guests, but your table seats only four.
In how many ways can four of the six guests arrange themselves at the table? Any
of the six guests can sit in the first chair. Any of the remaining five can sit in the
second chair. Any of the remaining four can sit in the third chair, and any of the
remaining three can sit in the fourth chair. (The last two will have to stand.) So the
number of possible arrangements of six guests in four chairs is 6*5*4*3, which is
360. Write a program that calculates the number of possible arrangements for any
number of guests and any number of chairs. (Assume there will never be fewer
guests than chairs.) Don’t let this get too complicated. A simple for loop should do
it

```cpp 

long long int no_perm(int n, int r) {
  if (r == 0 && n != 0) return 1;
  if (r != 0 && n == 0) return 0;
  return n*no_perm(n-1, r-1);
}

int main(int argc, char *argv[]) {
  int n, r;
  cin >> n >> r;
  cout << no_perm(n, r) << endl;
  return 0;
}

```

## Q9 

Q9. Write a C program to read an amount (integer value) and break the amount into smallest possible number of bank notes. Note: The possible banknotes ar 100, 50, 20, 10, 5, 2 and 1.

```cpp 

  int notes[7] = {100,50,20,10,5,2,1};
  int amnt;
  cin >> amnt;
  for (int i = 0; i < 7; i++){
    if (amnt == 0) break;
    cout << amnt/notes[i] << " nota(s) de R$ " << notes[i] << ",00\n";
    amnt -= amnt/notes[i]*notes[i];
  }

```
- Should use `amnt%=notes[i]`

## Q10 
Q10. Take a number from user and add 1 to each digit.
e.g. Input : 58973
Output : 69084

```cpp 

  int num;
  cin >> num;
  int cnt = 0;
  int newNum = 0;
  while (num != 0){
    int dig = num%10;
    if (dig+1 == 10) dig = -1;
    newNum = (dig+1)*int(pow(10, cnt++)) + newNum;
    num /= 10;
  }
  cout << newNum << endl;

```

## Q12 

Q12. write a program to convert a number into sentence
e.g. input : 123
Output : One hundred and twenty three

```cpp 

  string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string tenths[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  string powers[11] = {"hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion"};
  
  string number;
  cin >> number; 
  int length = number.length();
  for (int i = 0; i < number.length(); i++) {
    if (number[i] != 0){
      if (length - i > 2){
        cout << digits[number[i] - '0' - 1] << " " << powers[length - i - 3] << " ";
      } else if (length - i == 2){
        cout << tenths[number[i] - '0'] << " ";
      } else {
        cout << digits[number[i] - '0' - 1] << " ";
      }
    }
  }


```

---
title: BCS - Karachi 02
date: 2023-10-18
tags:
  - assignment
  - pf
  - uni
---
### Question: 01 \[10 points]
You are given a 2D array that represents the batting performance of a cricket team. Each row in the array
corresponds to a different batsman, and each column represents an inning played by that batsman. The
values in the array represent the runs scored by each batsman in each inning.
Write a C program to perform the following tasks:
1) Input the number of batsmen and the number of innings from the user.
2) Input the batting performance for each batsman in each inning.
3) Calculate and display the following statistics for each batsman.
- Total runs scored.
- Average runs per inning
- Highest score in a single inning
- Number of centuries (innings with a score of 100 or more)
- Number of half-centuries (innings with a score of 50-99)
Your program should display the statistics for each batsman individually.

```c
#include <stdio.h>

int main (){
  int bt, in;
  // Inputs for batters and number of innings they played
  scanf("%d%d", &bt, &in);

  // The performance array to store the information
  int perf[bt][in];

  // It takes the input values
  for (int i=0; i < bt; i++){
    for(int j=0; j < in; j++){
      printf("For the Batsman %d, %d inning: ", i, j);
      scanf("%d",&perf[i][j]);
    }
  }

  // Total 
  for (int i=0; i < bt; i++){
    int sum = 0, max = -1, cent = 0, hCent=0;
    for(int j=0; j < in; j++){
      printf("For the Batsman %d, %d inning: ", i, j);
      scanf("%d", &perf[i][j]);
      sum += perf[i][j];
      if (max < perf[i][j]){max = perf[i][j];}
      if (perf[i][j] >= 100){cent++;}
      else if (perf[i][j] >= 50){ hCent++;}
    }
    int avg = sum/in;
    printf("Batsman #%d", i+1);
    printf("\tTotal runs: %d \n", sum);
    printf("\tAverage: %d", avg);
    printf("\tHighest: %d", max);
    printf("\tCenturies: %d", cent);
    printf("\tHalf Centuries: %d", hCent);
  }
  return 0;
}

```

### Question: 02 \[10 points]
You are tasked with implementing a program to find the largest square submatrix of 1s in a given binary
matrix. Write a C program that does the following:
1. Input a binary matrix (a 2D array of 0s and 1s) from the user. The matrix can be of any size.
2. Find and display the largest square submatrix of 1s in the input matrix.
3. Display the dimensions (rows and columns) of the largest square submatrix found.
4. If there are more than one largest square matrix, then find any one of them.

```c
#include <stdio.h>

// Function to check a subarray with a given range
int check(int y, int x, int r, int size, int arr[size][size]) {
    int h = x + r;
    int v = y + r;

    if (h > size || v > size) {
        return -1;
    }

    for (int i = y; i < v && i < size; i++) {
        for (int j = x; j < h && j < size; j++) {
            if (arr[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to find the maximum subarray
int subarr(int size, int arr[size][size]) {
    int max = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 1) {
                int s = 1;
                while (check(i, j, s, size, arr) > 0) {
                    s++;
                }

                if (max < s - 1) {
                    max = s - 1;
                }
            }
        }
}

    printf("Max: %d", max);
    return max;
}

int main() {
    int size = 5;
    int arr[5][5] = {
      {1, 0, 1, 0, 0},
      {1, 1, 1, 1, 1},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
      {1, 1, 0, 1, 1}
    };

    subarr(size, arr);

    return 0;
}

```

### Question: 03 \[20 points]
You are assisting a traveler who is planning a trip and needs to book a flight for a specific day and time
slot. The traveler is looking for the most convenient day and time slot where flights are available. You have
access to a 2D array representing the flight availability for different days and time slots.
The 2D array below represents the availability of flights for different days of the week and two time slots:
Morning and Evening. Each row corresponds to a day, and each column corresponds to a time slot. A value
of 1 indicates that the flight is available (not full) for that time slot, and 0 indicates that the flight is full.

![](notes/1.General/PF%20Fast/Assignments/attachments/Pasted%20image%2020231018204449.png)

1. Analyze the flight availability for each day and time slot. Determine the day and time slot where the traveler has the highest chance of booking a flight on the basis user preferences i.e. based on time and price.
2. The traveler is flexible with the day of travel but prefers the morning time slot. Determine the day(s) when a flight is available in the morning and suggest the best option for booking based on this preference.
3. Considering the traveler's preference for an evening flight, identify the day(s) when an evening flight is available and suggest the best option for booking based on this preference.
4. The traveler is inquiring about flights on a specific day. Confirm if flights are available or not and provide the prices if available.

```c
#include <stdio.h>

void day(int n){
  switch(n){
    case 0:
      printf("\nMon");
      break;
    case 1:
      printf("\nTues");
      break;
    case 2:
      printf("\nWed");
      break;
    case 3:
      printf("\nThurs");
      break;
    case 4:
      printf("\nFri");
      break;
  }
}

void PriceTime(char time, int price, int sched[5][4]){
  if(time == 'm' || time == 'M'){
    for (int i=0; i<5; i++){
        if(sched[i][1] == price){
          printf("For Price %d", price);
          day(i);
        }
    }
  } else if (time == 'e' || time == 'E'){
    for (int i=0; i<5; i++){
        if(sched[i][3] == price){
          printf("For Price %d", price);
          day(i);
        }
    }
  }
}

void dayAnalysis(char time, int sched[5][4]){
  int min = 0;
  switch(time){
    case 'm':
    case 'M':
      printf("Morning Flights: \n");
      for (int i = 0; i < 5; i++){
        if(sched[i][0] == 1){
          day(i);
          printf(": %d", sched[i][1]);
          if (sched[min][1] > sched[i][1]){
            min = i;
          };
        }
      }
      printf("\nThe Cheapest Flight Would be on ");
      day(min);
      printf(" - $%d\n", sched[min][1]);
      break;
    case 'e':
    case 'E':
      printf("Evening Flights: \n");
      min = 1;
      for (int i = 0; i < 5; i++){
        if(sched[i][2] == 1){
          day(i);
          printf(": %d" ,sched[i][3]);
          if (sched[min][3] > sched[i][3]){
            min = i;
          };
        }
      }
      printf("\nThe Cheapest Flight Would be on ");
      day(min);
      printf(" - $%d\n", sched[min][3]);
      break;

  }

}

void printSched(char time,int sched[5][4], int d){
  printf("Day  Availability  Price\n");
  if (d == -1){
    if (time == 'E' || time == 'e'){
      for (int i = 0; i < 5; i++){
        day(i);
        printf("\t%d   \t   %d\n", sched[i][2], sched[i][3]);
      }
    } else if (time == 'm' || time == 'M'){
      for (int i = 0; i < 5; i++){
        day(i);
        printf("\t%d   \t   %d\n", sched[i][0], sched[i][1]);
      }
    }
  } else {
    if (time == 'E' || time == 'e' || time == '-'){
      for (int i = 0; i < 5; i++){
        if((d-1) == i){
        printf("Evening ----- \n");
          day(i);
          printf("\t%d   \t   %d\n", sched[i][2], sched[i][3]);
        }
      }
    } 
    if (time == 'm' || time == 'M' || time == '-'){
      for (int i = 0; i < 5; i++){
        if((d-1) == i){
        printf("\nMorning ----- \n");
          day(i);
          printf("\t%d   \t   %d\n", sched[i][0], sched[i][1]);
        }
      }
    }
  
  }
}


int main(){
  int sched[5][4] = {
  {1, 300, 0, -1},
  {1, 320, 1, 310},
  {0, -1, 1, 280},
  {1, 380, 0, -1},
  {1, 375, 1, 400}
  };
  char time;
  int price, d;

  printf("1.Flight Availability Analysis\n2.Morning Flight Preference\n3.Evening Flight Preference\n4.Specific Day Inquiry\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      scanf(" %c", &time);
      printSched(time, sched, -1);
      scanf("%d", &price);
      PriceTime(time, price, sched);
      break;
    case 2:
      dayAnalysis('m', sched);
      break;
    case 3:
      dayAnalysis('e', sched);
      break;
    case 4:
      // A specific day
      for(int i = 0; i < 5; i++){day(i);printf(" --- %d", i+1); }
      printf("\nChoose Day: ");
      scanf("%d", &d);
      printSched('-', sched, d);
      break;
  }
  }

```
### Question 04 \[20 points]
You are given a maze represented by a 2D array. The maze consists of walls represented by 'W', open
paths represented by 'O', the starting point represented by 'S', and the exit represented by 'E'. The
objective is to find a path from the starting point to the exit.
char maze\[N]\[M] = {
{'S', 'O', 'O', 'W', 'W'},
{'O', 'W', 'O', 'O', 'W'},
{'O', 'O', 'O', 'W', 'O'},
{'W', 'W', 'O', 'W', 'O'},
{'W', 'W', 'O', 'E', 'W'}
};
Write a C program to traverse the maze of 5 x 5 and find a path from the starting point to the exit.
Constraints
- There will be at least one path from the starting point to the exit. In case of more than one path
then consider only one.
- You can visit only right and down direction.
- Output will be only indexes of correct path.

Input Original Maze:
S O O W W
O W O W W
W O O W O
W W O W O
W W O E W
Output Maze after traversal:
0,0 0,1 0,2 1,2 2,2 3,2 4,2 4,3

```c
#include <stdio.h>
int search(int N, int M, char maze[N][M], int x, int y, int ans[20], int pos){
  printf("Searching a %d %d \n", y, x);

  if (y >= N || x>= M || maze[y][x] == 'W'){return 0;}
  
  if(maze[y][x] == 'E'){
    ans[pos] = y;
    ans[pos+1] = x;
    return 1;
  }
  if(search(N,M, maze, x+1,y, ans, pos+2)){
    ans[pos] = y;
    ans[pos+1]= x;
    return 1;
  }
  if (search(N,M,maze,x,y+1, ans, pos+2)){
    ans[pos] = y;
    ans[pos+1] = x;
    return 1;
  }

  return 0;
}

int main(){

  char maze[5][5] = {
    {'S', 'O', 'O', 'W', 'W'},
    {'O', 'W', 'O', 'O', 'W'},
    {'O', 'O', 'O', 'W', 'O'},
    {'W', 'W', 'O', 'W', 'O'},
    {'W', 'W', 'O', 'E', 'W'}
  };
  int ans[20] = {0};
  int pos = 0;
  for (int i = 0; i < 5; i++){
    for (int j=0; j < 5; j++){
      if (maze[i][j] == 'S'){
        if (search(5, 5, maze, j, i, ans, pos)){
          for (int i = 0; i < 20; i+=2){
            printf("%d,%d ", ans[i], ans[i+1]);
          }
          printf("FOUND\n");
        }else{printf("NOOTT\n");}
      };
    }
  }
}

```

Question 05 \[20 points]
Ramanujan-Hardy Numbers 2-way are numbers that are the sum of two cubes two different ways.
Following are the first few Ramanujan-Hardy 2-way numbers:
1729, 4104, 13832, 20683, 32832, 39312, 40033, 46683, 64232, 65728, 110656, 110808, 134379, 149389,
165464, 171288, 195841, 216027, 216125, 262656, 314496, 320264, 327763, 373464, 402597, 439101,
443889, 513000, 513856, 515375, 525824, 558441, 593047, 684019, 704977

E.g., 1729 = 12^3 + 1^3 = 9^3 + 10^3.
A. Write a C program to find all Ramanujan-Hardy numbers less than n^3.
B. Draw a trace table on a paper for the input 1729.

```c
#include <stdio.h>
#include <math.h>

int main(){

 int n = 1729;
  printf("%ld\n", n);
  int prev = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        for (int l = 0; l < n; l++){
          if (i != j && i != k && i != l && j != k && j!=l && k!=l && prev != (pow(i, 3)+pow(j,3))){
            int sum = pow(i, 3) + pow(j,3);
            int sum2 = pow(k,3) + pow(l,3);
            if (sum == sum2){printf("%d ", sum); prev=sum;}
          }
        }
      }
    }
  }

}

```

### Question 06 \[10 points]
Given a 1D array of N integers, and a target integer t.
Write a ‘C’ program to find all different number pairs in the array that have sum equal to t.
Sample Input:
List: 1, 8, 10, 12, 7, 4, 3 and t: 11
Sample Output:
Pairs: (1, 10), (7,4), (8,3)

```c
#include <stdio.h>
#include <math.h>

int main(){
  int arr[7] = {1,8,10,12,7,4,3};
  int t;
  scanf("%d", &t);
  for (int i = 0; i < 7; i++){
    for (int j = i; j < 7; j++){
      if ((arr[i]+arr[j]) == t){
        printf("(%d,%d) ",arr[i],arr[j]);
      }
    }
  }
}

```

### Question 07: \[10 points]
Your task is to developing a program to manage and sort shirt details for a clothing store. The shirt details
include the age and price for each shirt. Write a C program that sorts the shirt details based on age in
ascending order and, within the same age, sorts them based on price in descending order.
You are given 2D array: ages (representing the age of each shirt) and prices (representing the price of each
shirt). Assume any number of shirts and its prices by yourself.
Your expected output will show two different sorted list i.e., Sorted list in ascending order with respect to
Age and Sorted list in descending order with respect to Price.

```c
#include <stdio.h>
#include <math.h>

int main(){
  int shirts;
  printf("How many shirts?\n");
  scanf("%d", &shirts);
  int data[shirts][2];

  for (int i = 0; i < shirts; i++){
    printf("Shirt #%d\n", i);
      printf("Input Age: ");
      scanf("%d", &data[i][0]);
      printf("Input Price: ");
      scanf("%d", &data[i][1]);
  }
  
  for (int i = 0; i < shirts; i++){
    int min = i;
    for (int j = i; j < shirts; j++){
      if(data[min][0] > data[j][0]){
        min = j;
      }
    }
    int t = data[min][0];
    data[min][0] = data[i][0];
    data[i][0] = t;

    for (int j = 0; j < shirts; j++){
      if(data[i][0] == data[j][0]){
        int max = j;
        for (int k = j; k < shirts; k++){
            if (data[max][1] < data[k][1]){
              max = k;
            }
        }
      int t = data[max][1];
      data[max][1] = data[j][1];
      data[j][1] = t;
      }
    }
  }

  for (int i = 0; i < shirts; i++){
    printf("%d : %d\n", data[i][0], data[i][1]);

  }
}

```

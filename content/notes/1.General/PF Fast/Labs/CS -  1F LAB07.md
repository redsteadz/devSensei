
## Q1
Take Two numbers from user and divide both numbers but do not use the division operator.

```c
#include <stdio.h>
S
int main(){

  int a,b, div=0;
  scanf("%d%d", &a, &b);

  while ( (b%a) != b){
    if (b >= 0){
      b = b - a;
      div++;
    } else{
      break;
    }
  }
  printf("THe div is = %d", div);
  return 0;
}

```


## Q2

Given an array of integers of size N and an integer “d”, the task is to rotate the array
elements to the left by d positions. Note: Solve the question without declaring another
array. (The input array itself must be modified).
Input: {1, 2, 3, 4, 5, 6, 7}, d = 2
Output: {3, 4, 5, 6, 7, 1, 2}
```c
#include <stdio.h>

int main(){
  int d, size;
  scanf("%d%d", &size, &d);
  int arr[size];
  for (int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < d; i++){
    int t = arr[0];
    for (int j = 0; j < size-1; j++){
      arr[j] = arr[j+1];
    }
    arr[size-1] = t;
  for (int i = 0; i < size; i++){
    printf("%d", arr[i]);
  }
  printf("\n");
  }

  for (int i = 0; i < size; i++){
    printf("%d", arr[i]);
  }


  return 0;
}
```

## Q3
Take a number from user and count the sum of their digits.
Input: 206
Output: 8
Input: 4569
Output: 24
```c
#include <stdio.h>
#include <math.h>

int main(){
  int n, sum = 0;
  scanf("%d", &n);
  int th = log10(n) + 1;
  for (int i = 0; i < th; i++){
    int dig = n % 10;
    sum += dig;
    // printf("%d", dig);
    n /= 10;
  }

  printf("The sum is %d", sum);

  return 0;
}
```


## Q4

Take a 2D array(Matrix) as input from user and check that array is symmetric or not. If array
is symmetric then print “Array is Symmetric” with array if not, then print “array is not
symmetric” with given array.
Note: A symmetric matrix is a matrix that is equal to its transpose. Where elements in
first row are equal to elements in first column and so on.
Formal Definition: Aij = Aji.

```c
#include <stdio.h>

int main(){
  int r, c;
  int is = 1;
  scanf("%d%d", &r, &c);
  int arr[r][c];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < r; i++){
    int j;
    for (j = i; j < c; j++){
      if (arr[i][j] != arr[j][i]){
      is = 0;
        break;
      }
    }
    if (is == 0){
      break;

    }
  }
  
  if (is == 1){printf("IT IS \n");}
  else{printf("IT ISN'T \n");}
  
  printf("The matrix is ");
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      printf("%d", arr[i][j]);
    }
    printf("\n");
  }
    
}
```

## Q5
Print the following pattern on C console:

```c
#include <stdio.h>

int main(){
  int n = 5; 


  for (int i = 0; i < n; i++){
    for(int j = 0; j < (n - i - 1); j++){
      printf(" ");
    }
    
   int x = 2*i + 1;
    printf("*");
    if (i == 0){x = 0;}

    for (int j = 0; j < (x-2); j++){
      printf(" ");
    }
    if (i != 0){printf("*");};
  
    printf("\n");
  }
    
  for (int i = 0; i < (n-1); i++){
    for(int j = 0; j < (i+1); j++){
      printf(" ");
    }
    
    printf("*");

    for (int j = 0; j < (n-2*i); j++){
      printf(" ");
    }
    if (i != (n-2)){printf("*");};
  
    printf("\n");
  }
}

```

## Q6
Take an array with N elements as input, and then output the frequency of each element
present in the array. Example:
Input: {2, 4, 2, 3, 5, 5, 4, 4}
Output:
Frequency of 2 = 2
Frequency of 4 = 3
Frequency of 3 = 1
Frequency of 5 = 2

```c
#include <stdio.h>
int main(){
  int n, max = -100000;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    if (arr[i]>max){
      max = arr[i];
    }
  }
  int freq[max+1];
  
  for (int i = 0; i <= (max+1); i++){
    freq[i] = 0;
  }
  for (int i = 0; i < n; i++){
    freq[arr[i]]++;
    // printf("%d Should be incremented in freq by %d \n", arr[i], freq[arr[i]]);
  }
  for (int i = 0; i <= max; i++){
    if (freq[i] > 0){
      printf("Frequency of %d is %d\n", i, freq[i]);
    }

  }

}
```

## Q7
Take 2 2x2 matrices as input in a 2D array. Then, multiply the 2 matrices and print the final
output matrix. Use the following image as a guide:
```c
#include <stdio.h>

int main(){

  int arr[2][2];
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  
  int arr2[2][2];
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      scanf("%d", &arr2[i][j]);
    }
  }

  int arr3[2][2] = {{0, 0}, {0,0}};

  for (int r = 0; r < 2; r++){
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++){
        arr3[i][j] += arr[i][r] * arr2[r][j];
      }

    }
  }

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
   printf("%d ", arr3[i][j]);
    }
    printf("\n");
  }

}
```


## Q8
Take an array with N elements as input, and sort the array into ascending order and then
print the sorted version.
Input: {6, 3, 2, 7, 1, 5}
Output: {1, 2, 3, 5, 6, 7}

```c
#include <stdio.h>

int main(){
  int n;

  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n; i++){
    printf("%d", arr[i]);
  }

  for (int i = 0; i < n; i++){
    int max = arr[i];
    int t = arr[i];
    int max_pos = i;
    for(int j = i; j < n; j++){
      if (max < arr[j]){
        max = arr[j];
        max_pos = j;
      }
    }
    arr[i] = max;
    arr[max_pos] = t;
  for (int i = 0; i < n; i++){
    printf("\n %d", arr[i]);
  }
  printf("\n");
  }

  for (int i = 0; i < n; i++){
    printf("%d", arr[i]);
  }
}
```


## Q9
Junaid wants to keep track of all mobile phone bills in his X company branches. Let Y be
the number of company mobile phones in each branch. Create a 2D array for bill amount,
where keep track of branch ID in row subscript, mobile phone IDs in column subscript. Ask
users to enter a bill for all mobile phones in all branches. Your program should print the
following:
- Total bill for all branches
- Total bill for each branch
- Branch ID where maximum bill arrived
- Branch and Mobile Phone IDs where bill is highest of all mobile phones.

```c
#include <stdio.h>

int main(){
  int x, y;
  int t_all = 0, b_id_max = 0, m_max = 0, bm_max;  
  scanf("%d%d", &x, &y);
  int t_branch[x];
  for (int i = 0; i < x; i++){
    t_branch[i] = 0;
  }
  int arr[x][y];

  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      scanf("%d", &arr[i][j]);
      t_all += arr[i][j];
      t_branch[i] += arr[i][j];
      if (arr[i][m_max] < arr[i][j]){
        m_max = j;
      }
    }

    if (t_branch[i] > t_branch[b_id_max]){
      b_id_max = i;
    }

    } 
printf("The total bill for all %d \n", t_all);
for (int i = 0; i < x; i++){
  printf("\nThe total bill for %d Branch is %d -- Maximum Mobile ID of this branch is %d", i+1, t_branch[i], m_max);
}
printf("The max branch ID is %d", b_id_max);

  return 0;
  }

```


## Q10

Given an unsorted array A of size N that contains only non-negative integers, find a
continuous sub-array which adds to a given number S. In case of multiple subarrays, return
the subarray which comes first on moving from left to right.
Input:
Enter Number S = 12
Array: {1, 2, 3, 7, 5}

```c

#include <stdio.h>

int main(){
  int n, s, flag=0, loc_min=0, loc_max=0;
  scanf("%d%d", &n, &s);

  int arr[n];

  for (int i = 0; i < n; i++){
    scanf("%d", &arr[n]);
  }

  for(int i = 0; i < n; i++){
    int j, sum = 0;
    for (j = i; j < n; j++){
     sum += arr[j]; 
     printf("SUm is %d \n", sum);
     if (sum == s){
       flag = 1;
      break;
     } 
    }

    if (flag == 1){
      loc_min = i;
      loc_max = j;
      break;
    }
  }

  printf("The elements from index %d to %d", loc_min, loc_max);
}
```
## Q11
You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

- `maxLocal[i][j]` is equal to the **largest** value of the `3 x 3` matrix in `grid` centered around row `i + 1` and column `j + 1`.

In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return _the generated matrix_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/06/21/ex1.png)

**Input:** grid = \[\[9,9,8,1],\[5,6,2,6],\[8,2,6,4],\[6,2,2,2]]
**Output:** \[\[9,9],\[8,6]]
**Explanation:** The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png)

**Input:** grid = \[\[1,1,1,1,1],\[1,1,1,1,1],\[1,1,2,1,1],\[1,1,1,1,1],\[1,1,1,1,1]]
**Output:** \[\[2,2,2],\[2,2,2],\[2,2,2]]
**Explanation:** Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

**Constraints:**

- `n == grid.length == grid[i].length`
- `3 <= n <= 100`
- `1 <= grid[i][j] <= 100`

```c
#include <stdio.h>

int main(){
  int r = 5;
  // scanf("%d", &r);
  // int arr[10][10] = {{20,8,20,6,16,16,7,16,8,10},{12,15,13,10,20,9,6,18,17,6},{12,4,10,13,20,11,15,5,17,1},{7,10,14,14,16,5,1,7,3,11},{16,2,9,15,9,8,6,1,7,15},{18,15,18,8,12,17,19,7,7,8},{19,11,15,16,1,3,7,4,7,11},{11,6,5,14,12,18,3,20,14,6},{4,4,19,6,17,12,8,8,18,8},{19,15,14,11,11,13,12,6,16,19}};
  // int arr[4][4] = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
  int arr[5][5] = {{1,1,1,1,1}, {1,1,1,1,1}, {1,1,2,1,1}, {1,1,1,1,1}, {1,1,1,1,1}};
  // int arr[3][3] = {{2,5,5},{3,2,5},{1,2,3}};
  // for (int i = 0; i < r; i++){
    // for (int j = 0; j < r; j++){
      // scanf("%d", &arr[i][j]);
    // }
  // }

  int res[r-2][r-2];

    for (int main_r = 0; main_r < (r-2); main_r++){
      for (int main_c = 0; main_c < (r-2); main_c++){
      int max = -10000;
        for (int sub_r = main_r; sub_r < main_r+3; sub_r++){
          for (int sub_c = main_c; sub_c < main_c+3; sub_c++){
            printf("Array Val %d, Pos %d, %d for the main block of %d %d\n", arr[sub_r][sub_c], sub_r, sub_c, main_r, main_c);
            if (arr[sub_r][sub_c] > max){
              max = arr[sub_r][sub_c];
              printf("The max chosen %d\n",max);
            }
          }
        }
        res[main_r][main_c] = max;
      }
    }

for (int i = 0; i < (r-2); i++){
    for (int j = 0; j <(r-2) ; j++){
      printf("%d ", res[i][j]);
    }
    printf("\n");
}
  
}
```


---
title: A simple example of TicTacToe
date: 2023-10-05
tags:
  - algorithms
  - general
  - patterns
---
If we were to break the _big_ task of making a tictactoe game into smaller ones it would be 
1. Making the Board
2. Taking options and replacing positions
3. Finding out the victor/tie

## Making the board

Making the board is simple enough by using some ideas of for loops and arrays we can make a simple looking board as such

```c
#include <stdio.h>

int main(){
	// The board would consist of 3x3 characters
	char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
	
	printf("Borad\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf(" %c |", board[i][j]); // Prints the character of with a border |
		};
		printf("\n"); // New line for the new row
	}
}
```

**Output:**
Board:
 \- | - | - |
 \- | - | - |
 \- | - | - |

- Using If conditions you can making it have the left border as well, Visually speaking a lot of things is possible with a lot more variety and much more appeal. But this is just to show how it can be operational

## Taking inputs and making replacements

What we can do here is simply, replace the character at the x, y position as our characters are entirely within an array

```c
#include <stdio.h>

int main(){
	
	char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
	int loc;
	scanf("%d", &loc); // Implies the location
	int y = loc % 10;
	int x = loc / 10;
	
	board[x][y] = 'X'; // This would replace it with X no matter what
	printf("Borad\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf(" %c |", board[i][j]); 
		};
		printf("\n");
	}
}
```

In order to keep track of 
1. If it should be X or O
2. The game should end
We can declare a `sel` variable which will simply keep track of how many selections we've done
- If `sel` is even It can be 'X'
- Odd -> 'O'

Furthermore to change the value of X and O, We can declare an `opt` variable to simply store what character we are on



```c
#include <stdio.h>

int main(){
	
	char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
	int loc, sel = 1; // As the first time selection will be 1st
	char opt = '-'; // Default value is null
	
	while (sel <= 9){ // A loop to keep asking locations
	    
	scanf("%d", &loc); 
	int y = loc % 10;
	int x = loc / 10;
	if (board[y][x] = '-'){ // Checks if the position hasn't already been picked
	if (sel % 2 == 0){ // switches between X and O as selection continues
	    opt = 'X';  
	} else {
	    opt = 'O';
	}}
	
	board[x][y] = opt;
	printf("Borad\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf(" %c |", board[i][j]); 
		};
		printf("\n");
	}
	sel++; // Increments the selections
	}
}
```

Now to handle an inconvenience issue, Currently, We are taking inputs x and y with respect to 0 as the initial value. But that isn't what we usually do
![](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2019.49.50.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2019.49.50.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2019.49.50.excalidraw.dark.svg)%%

We can do this by just taking such and such inputs and decrementing x and y by 1

```c
	int y = loc % 10; // Taking x and y values starting from 1
	int x = loc / 10;
	x--;
	y--;
```

Like so

## Winner or Not ? 

This is where the idea becomes mildly interesting, Some things to keep in mind
1. Check the victor when a location has been placed
2. Check if the declared `opt` is same for _specific portions_

We can divide the victories into specific portions

- Vertical
	- Where the y axis (row) the same
		- So keeping x of `loc`, we can increment j (y value) from 0 to 2 to see if the vertical for that specific X position is the same
		- ![](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.02.59.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.02.59.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.02.59.excalidraw.dark.svg)%%

- Horizontal
	- Where the x axis (column) the same
		- So keeping y of `loc`, we can increment i (x value) from 0 to 2 to see if the vertical for that specific Y position is the same
	- ![](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.08.27.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.08.27.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.08.27.excalidraw.dark.svg)%%
- Diagonal
	- Where the x++ and y-- are the same 
		- No value from the `loc` will be relevant
	- ![](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.11.55.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.11.55.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.11.55.excalidraw.dark.svg)%%
- Anti-Diagonal
	- Where the x++ and y++ are the same
		- No value from the `loc` will be relevant
	- ![](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.16.02.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.16.02.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Project/attachments/A%20simple%20example%20of%20TicTacToe%202023-10-05%2020.16.02.excalidraw.dark.svg)%%


In terms of code it would look like this 

```c
	// Column
	
	for (int i = 0; i < 3; i++){
		if (board[x][i] != opt){
			break;
		} else if (i == 2) {
			printf("WIN WIN WIN %c", opt);
			win = 1;
		}
	}
	
	// Vertical
	for (int i = 0; i < 3; i++){
		if (board[i][y] != opt){
			break;
		} else if (i == 2){
			printf("Winnn %c", opt);
			win = 1;
		} 
	}
	
	// Diagonal
	for(int i=0,j=0; i < 3; i++){
		if (board[i][j] != opt){
			break;
		} else if (i==2){
			printf("WINNN %c", opt);
			win = 1;
		}
		j++;
	}
	
	// Anti Diagonal
	for (int i = 0, j = 2; i < 3; i++){
		if (board[i][j] != opt){
			break;
		} else if (i == 2){
			printf("Winnnnnn %c", opt);
			win = 1;
		}
		j--;
	}
	
```

We can keep track of if a person won or not by simply having a int variable `win` and placing it in the condition of while loop, To function as long as it has a value of `0` (No victor yet)

The overall code for this would look something like this

```c

#include <stdio.h>

int main(){
	char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
	int sel = 1, loc;
	int win = 0;
	
	while (sel < 8 && win == 0){
	
	int loc;
	scanf("%d", &loc);
	char opt;
	int y = loc % 10;
	int x = loc / 10;
	x--;
	y--;
	
	if (board[x][y] == '-'){	
		if (sel % 2 == 0){
			opt = 'X';
		} else {
			opt = 'O';
		}
	};
	
	board[x][y] = opt;
	
	// Board
	
	printf("Board \n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n");
	}
	
	// Column
	
	for (int i = 0; i < 3; i++){
		if (board[x][i] != opt){
			break;
		} else if (i == 2) {
			printf("WIN WIN WIN %c", opt);
			win = 1;
		}
	}
	
	// Vertical
	for (int i = 0; i < 3; i++){
		if (board[i][y] != opt){
			break;
		} else if (i == 2){
			printf("Winnn %c", opt);
			win = 1;
		} 
	}
	
	// Diagonal
	for(int i=0,j=0; i < 3; i++){
		if (board[i][j] != opt){
			break;
		} else if (i==2){
			printf("WINNN %c", opt);
			win = 1;
		}
		j++;
	}
	
	// Anti Diagonal
	for (int i = 0, j = 2; i < 3; i++){
		if (board[i][j] != opt){
			break;
		} else if (i == 2){
			printf("Winnnnnn %c", opt);
			win = 1;
		}
		j--;
	}
	
	sel++;
	}
}
```

We can take this entire `check`, Place it in a function and then into the while loop, Making the overall code more _elegant_ 
But that requires some understanding from later on stuffs!
---
title: BCS - Karachi 01
date: 2023-09-11
tags:
  - pf
  - assignment
  - karachi
---
## Task 1 (a):
Create an algorithm and then write pseudocode for the following problems:
**a)** To find Greatest Common Divisor (GCD) of two given numbers.

```cpp
/* 
1. Start
2. Input Num1 and Num2
3. declare count = 1
4. declare gcd;
5. while (count != (Num1 && Num2))
	1. if(Num1%count == 0 && Num2%count == 0){
		1. gcd = count
	2. }
	3. count++;
6. Output gcd
7. END
*/

int main(){
	int num1, num2, gcd, count;
	cin >> num1;
	cin >> num2;
	
	while(count <= num1 & count <= num2){
		if(num1%count==0 && num2%count==0){
			gcd = count;
		};
	};
	
	cout << gcd;
	return 0;
}
```

![](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.32.10.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.32.10.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.32.10.excalidraw.dark.svg)%%

**b)** To take 3 numbers A, B and C as input and find if the sum of numbers A and B is greater than the
number C.

```cpp
/*
1. Start
2. Input A, B, C
3. sum = A + B
4. if (sum > C)
	1. Output "C is bigger than sum of A and B"
5. else
	1. Output "C is smaller or equal to the sum of A and B"

NI LIKHUNGA ISKA CODEEEEE
*/
```

![](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.52.53.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.52.53.excalidraw.md), and the [dark exported image](notes/1.General/PF%20Fast/Assignments/attachments/BCS%20-%20Karachi%2001%202023-09-11%2021.52.53.excalidraw.dark.svg)%%

**c)** To find the smallest number in a given list of 10 numbers.
```cpp
#include <vector>
#include <string>
/* 
1. Start
2. declare min = 10000000
3. declare list
4. for (i, list){
	1. if (list[i] < min)
		1. min = list[i]
5. }
6. OUTPUT min

*/

int main(){
	int min = 1000000;
	vector <int> list = {
		5,2,5,7,3,8,36,74,23
	};
	for (int i=0; i< 10; i++){
		if (list[i] < min){
			min = list[i];
		};
	};
	
	cout << min << endl;
	
	return 0;
}

```

**d)** Given a list of 5 numbers, rearrange them in descending order.

```cpp
#include <vector>
#include <string>
using namespace std;

/*
1. Start
2. declare list
3. for (i=0, list.size()){
	1. set max = MAX(i, list.size())
	2. swap( list[max], list[i] )
4. }
5. END

*/

int main(){
	int max;
	vector <int> list = {
		5,2,5,7,3,8,36,74,23
	};
	for (int i=0; i < list.size(); i++){
		// Takes the ith value as the maximum
		max = i;
			// Makes the loop continue from ith pos, to find the largest 
		for (int x = i; x < list.size(); x++){
			// Checks if larger
			if (list[x] > list[max]){
				max = x;
			};	
		};
		int t = list[i];
		list[i] = list[max];
		list[max] = t;
	};
	
	for(int i=0; i < list.size(); i++){
		cout << list[i] << endl;
	};
	
	return 0;
}
```


**e)** To find the number of even integers in a given list of numbers.

```cpp
/* 
1. Start
2. Set even = 0;
3. declare list
4. for (i=0; i<list.size(); i++){
	1. if(list[i] % 2 == 0){ even++}
5. }
6. OUTPUT even
7. END
KYN BNAUN ME CPP ME CODE ? FREE ME ? 
*/
```

## Task 2:
For each of the following variables, write the most appropriate data type. Also provide a brief reason for
selecting the data type.
a) Age - **Integer**
b) Temperature - **float**
c) Longitude - **float**
d) Third letter of your name - **char**
e) Wind speed - **float**

## Task 3:
Mr. Rahim works at the cash counter of a retail store. For every customer he serves at the counter, he asks for their name and counts the items they bought. For each of these items he adds the price to the customer’s bill, with that bill also containing the customer’s name. If the bill exceeds 10k, Mr. Rahim is obliged to give the customer a 5% discount. Also, at the end of the day, Mr. Rahim should write the total revenue for the day i.e., the grand total of all the bills combined.
Draw a detailed flowchart for Mr. Rahim’s activities.

```cpp
int main(){
	int count, price, total = 0, discount = 0, cont = 1, gTotal;
	
	while(cont == 1){
		cout << "How many Items are there ? ";
		cin >> count; 
		for (int i = 1; i <= count ; i++){
			cout << "What is the price of the item no # " << i << " ";
			cin >> price;
			total = total + price;
		};
		if (total >= 10000){
			total = total*0.95;
		};
		gTotal = gTotal + total;
		cout << "The total is " << endl << total;
		cout << "Total sales for the day till now are " << endl << gTotal;
		cout << "Continue ? " << endl;
		cin >> cont;
	}
	return 0;
}
```

## Task 4:
Write a program that takes an integer, as an input from its user and print its binary equivalent value on screen. You are required to write the pseudocode or algorithm or flowchart to show the pre-programming process along with the code written in C program.

```c
#include <stdio.h>
#include <math.h>

int main(){
	int num, bit, count = 1, binary = 0;
	printf("BHAI NUMBER TO DO ");
	scanf("%d", &num);
	while(num != 0){
		bit = num % 2;
		binary = binary + bit*pow(10, count);
		count++;
		num = num/2;
		
	};
	printf("%d ", binary);
	
	return 0;
}
```

## Task 5
Mr. Salman ran a small grocery business. He works on 15% profit on sale of each item. He also deduct
18% GST on each sale that he made. Write a program that prompt user to input price of five items
individually and then print the sales receipt including all necessary details as shown below:
OUTPUT:

SALMAN grocery Store
--------------------------------------------------
Description | Price
---------------------------------------------------
Item 1 | 25
Item 2 | 165
Item 3 | 200
Item 4 | 350
Item 5 | 75
---------------------------------------------------
Item Total | 815
G.S.T | 146.7
----------------------------------------------------
Grand Total | 961.7

Total Profit Earned | 122.25

```c
#include <stdio.h>

int main(){
	int i1, i2, i3, i4, i5;
		printf("Input price of Item1 ");
		scanf("%d", &i1);
		printf("Input price of Item2 ");
		scanf("%d", &i2);
		printf("Input price of Item3 ");
		scanf("%d", &i3);
		printf("Input price of Item4 ");
		scanf("%d", &i4);
		printf("Input price of Item5 ");
		scanf("%d", &i5);
	
	int total = i1+i2+i3+i4+i5;
	printf("SALMAN grocery Store\n");
	printf("--------------------\n");
	printf("Item 1    |   %d\n", i1);
	printf("Item 2    |   %d\n", i2);
	printf("Item 3    |   %d\n", i3);
	printf("Item 4    |   %d\n", i4);
	printf("Item 5    |   %d\n", i5);
	printf("--------------------\n");
	printf("ItemTotal |   %d\n", total);
	printf("GST       |   %.1f\n", total*0.18);
	printf("--------------------\n");
	printf("GrandTotal|   %.1f\n", 1.18*total );
	printf("Profit    |   %.1f\n", total*0.15);
	return 0;
}
```
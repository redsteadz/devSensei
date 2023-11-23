---
title : "Bitewise Operators"
description: "The bitewsie operators offered in C++"
date : "2023-08-24"
tags: 
- dsa
- fundamentals
- cpp
---

Bitewise operators work on a bit level and not number leve

## AND (&) Operator
| a   | b   | result |
| --- | --- | ------ |
| 0   | 0   | 0      |
| 1   | 0   | 0      |
| 0   | 1   | 0      |
| 1   | 1   | 1      |

![](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.28.40.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.28.40.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.28.40.excalidraw.dark.svg)%%

## OR (|) Operator
| a   | b   | result |
| --- | --- | ------ |
| 0   | 0   | 0      |
| 1   | 0   | 1      |
| 0   | 1   | 1      |
| 1   | 1   | 1      |
![](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.30.47.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.30.47.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Bitewise%20Operators%202023-08-24%2015.30.47.excalidraw.dark.svg)%%

## XOR (^) Operator
| a   | b   | result |
| --- | --- | ------ |
| 0   | 0   | 0      |
| 1   | 0   | 1      |
| 0   | 1   | 1      |
| 1   | 1   | 1      |

## NOT (~) Operator
| a   | result |
| --- | ------ |
| 0   | 1      |
| 1   | 0      |
| 0   | 1      |
| 1   | 0      |

```cpp
int main(){
	int a = 6; //......... 110
	int b = 3; //......... 011
	
	// AND
	cout << (a&b) << endl; //........ 010? -> 2
	
	// OR
	cout << (a|b) << endl; // ....... 111? -> 7
	
	// NOT
	cout << ~a << endl << ~b << endl; //........ 
	
	// XOR
	cout << (a^b) << endl;   // ....... 101? -> 5
return 0;
}
```

## Left Shift 5 << 1
Shift the bits of x << n times to **left**
- This usually means that you are multiplying a number by 2, every step of the way.
- But it is also possible that the number becomes negative when x is large
	- Because the first bit represents the sign of the number, left shift is capable of turning it into negative
- Will shifting beyond the storage space cause an overflow error ?  
- Padding for +ve numbers is with 0
- Padding for -ve numbers is with ??? &rarr; Depends on Compiler
 
## Right Shift x >> n
Shift the bits of x << n times to **right**
- This usually means that you are dividing a number by 2, every step of the way.
	- A decimal number is rounded down 
- But it is also possible that the number becomes 0 when x is very small
- Will shifting beyond the storage space cause an overflow error ?  
- Padding for +ve numbers is with 0
- Padding for -ve numbers is with ??? &rarr; Depends on Compiler 

## Post and Pre increment/Decrement
- Post means do something after execution
```cpp
int main(){
	int i = 4;
	int a = i++; // Post -> So a should have the value of 4, and when declared, i increments to 5
	cout << a << endl;
	cout << i << endl;
return 0;
}
```

- Pre means do something before execution
```cpp
int main(){
		int i = 4;
		int a = ++i; // Pre means i has been incremented before declaration
		cout << a << endl;
		cout << i << endl;
	return 0;
}
```

```cpp
// Increment
i++ // Post increment
++i // Pre increment

// Decrement
i-- // Post decrement
--i // Pre increment
```

## For loops
```cpp
for(/* init Variables ; conditions ; operation */){
	// Body
	break // Breaks the loop
	continue // Continue the loop
	// This part inaccessilbe now
}
```

### The Fibonacci Series
0 , 1, 1, 2, 3, 5, 8, 13, 21 . . . . 

```cpp 
int main(){
	int n = 6;
	int x = 0;
	int y = 1;
	cout << x << " " << x << " ";
	for (int i = 1; i <= 6; i++){
		int sum = x+y;
		cout << sum << " ";
		x = y;
		y = sum;
	}
	return 0;
}
```

- Reverse Integer

```cpp
int main(){
	int x = 1534236469;
	int r = 0;
	while( x != 0){
		r = r*10 + x%10;
		cout << "R shit = " << r << endl;
		x = x/10;
		cout << "X shit = " << x << endl;
	};
	cout << r << endl;
	return 0;
}
```


- Compliment of Base 10 int
```cpp
#include <math.h>

class Solution {
public:
    int bitwiseComplement(int n) {
    int check = n>>1;
    int sum = 1;
    int count = 1;
	
	// Loop to find the max_relevant bit, and hence the corresponding number that bits activated till that point
    while (check != 0){
        check = check >> 1;
        sum = sum + pow(2, count);
        count++;
    };    
    int inv = (~n&sum);
    return inv;
    }
};

int main(){
	Solution i;
	cout<< i.bitwiseComplement(5) << endl;
	return 0;
}
```

The idea is to take the inverse of the value then multiplying the activated bits with the max bits for the number **e.g**

![](notes/1.General/CPP%20DSA/attachments/4%20Bitewise%20Operators%202023-09-05%2020.36.39.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/4%20Bitewise%20Operators%202023-09-05%2020.36.39.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/4%20Bitewise%20Operators%202023-09-05%2020.36.39.excalidraw.dark.svg)%%


- Binary to Decimal
```cpp
#include <math.h>

int main(){
	int bit, dec, n, count = 0;
	cout << "Input your Binary number: ";
	cin >> n;
	
	while (n !=0){
		bit = n%10;
		n = n/10;
		dec = dec + bit * pow(2, count);
		count++;
	};
	cout << "The equivelant decimal number is: " << dec << endl;
	
	return 0;
}
```

- Decimal to Binary
```cpp
#include <math.h>
int main(){	
	int n, sum = 0, rev_sum = 0, count = 0;
	cout << "Enter the integer: ";
	cin >> n;
	while(n != 0){
		sum = sum + (n%2) * pow(10, count);
		n = n/2;
		count++;
	};
	cout << sum << endl;
	return 0;
}
```

- sqrt(n) where n is an integer
```cpp
int main(){
	float n;
	cout << "Input your integer: ";
	cin >> n;
	float apx = n, prev;
	
	while ( prev != apx ){
			prev = apx;
			apx = (apx + n/apx)/2.0;
			cout << apx << endl;
	};
	
	cout << apx;
	return 0;
}
```
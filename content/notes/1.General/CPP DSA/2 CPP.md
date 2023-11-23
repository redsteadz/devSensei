---
title: "CPP Programming Language"
description: "C++ as a programming language"
date: "2023-08-20"
---

## Generic Operators

For C++,
```cpp

#include<iostream>
using namespace std;

// Represents the main function that is ran when file is compiled
int main(){
	cout << "BRUH" << endl;
	// <<   -> write
	// >>   -> read
	// endl -> new line
	// `\n` -> new line
	// ;    -> Ends the line of code
	return 0;
};
```

## Data Types and Variables
- For declaring a variable
- `[DATATYPE] [NAME] = [VALUE]`

|Data Type|Meaning|Size (in Bytes)|
|---|---|---|
|`int`|Integer|2 or 4|
|`float`|Floating-point|4|
|`double`|Double Floating-point|8|
|`char`|Character|1|
|`wchar_t`|Wide Character|2|
|`bool`|Boolean|1|
|`void`|Empty|0|

- Char can only store 1 character 
- The values are stored in terms of bits
	- Numbers in binary
	- Characters according to ASCII -> Binary

## Typecasting
One type can be converted to another using this method

```cpp
#include<iostream> 
using namespace std;
int main(){
	int a = 'a'; // Converts it to the respective Denary value according to ASCII table
	char b = 97;
	cout << "The ASCII value of a is :" << a << endl;
	cout << "The char value of 97 is :" << b << endl;
	
	// Successfully ending a program
	return 0;
}
```

Due to the difference in sizes for the datatypes, It is possible to overflow a datatype, In which case it uses the final x amount of byte where x depicts the amount of bytes that data type can store
For example `char` stores 1 byte, so 
- max val = $2^8 - 1$ 
- min val = 0
For an `int` stores 4 bytes, so
- max val = $2^{32} - 1$
- min val = 0

```cpp 
int main(){
	char a = 4952; 
	cout << a << endl;
	return 0;
}
```

An error is observed:
`In file included from input_line_3:1: /tmp/temp_1692542671892.cpp:7:11: warning: implicit conversion from 'int' to 'char' changes value from 4952 to 88 [-Wconstant-conversion] char a = 4952;`

Our number 4952 in terms of binary is:
`10011 01011000`
The last 8 bits (size of `char`) make up the value of 88, Which in ASCII means `X`

## How Negative Numbers are stored
- 1st bit denotes the sign
	- +ve = 0
	- -ve = 1
- `-5`
	- Ignore -ve sign and convert to binary `101`
	- Take 2's compliment and store
![](notes/1.General/CPP%20DSA/attachments/CPP%202023-08-20%2020.36.31.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/CPP%202023-08-20%2020.36.31.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/CPP%202023-08-20%2020.36.31.excalidraw.dark.svg)%%

The value is stored in the compliment form, And when printed. Stored numbers 2's compliment is taken again (Converting it into a normal binary form), And the first bit of the original data gives the sign

This helps in saving an additional slot for a useless value
as $-0 = 0$ If the first bit always represented the numbers sign, It would be wasted in this case
Hence 2's compliment is used
The range for it starts from $-2^{31} <= x <= 2^{31} -1$ instead of starting from $-2^{31} -1$
This can be "first bit for sign" can be ignored by using the `unsigned` operator
```cpp
int main(){
	unsigned int a = 23; // A unsigned +ve number
	unsigned int b = -23; // A unsigned -ve number
	cout << a << endl;
	cout << b << endl;
	return 0;
}
```
- **Note that the negative number is huge because the first value is taken to be RELEVANT/Unsigned**

## Operator

|Operator|Operation|
|---|---|
|`+`|Addition|
|`-`|Subtraction|
|`*`|Multiplication|
|`/`|Division|
|`%`|Modulo Operation (Remainder after division)|

|Operator|Example|Equivalent to|
|---|---|---|
|`=`|`a = b;`|`a = b;`|
|`+=`|`a += b;`|`a = a + b;`|
|`-=`|`a -= b;`|`a = a - b;`|
|`*=`|`a *= b;`|`a = a * b;`|
|`/=`|`a /= b;`|`a = a / b;`|
|`%=`|`a %= b;`|`a = a % b;`|

| Operator | Meaning                  | Example                     |
| -------- | ------------------------ | --------------------------- |
| \==     | Is Equal To              | `3 == 5` gives us **false** |
| `!=`     | Not Equal To             | `3 != 5` gives us **true**  |
| `>`      | Greater Than             | `3 > 5` gives us **false**  |
| `<`      | Less Than                | `3 < 5` gives us **true**   |
| `>=`     | Greater Than or Equal To | `3 >= 5` give us **false**  |
| `<=`     | Less Than or Equal To    | `3 <= 5` gives us **true**  |

***NEXT &rarr;*** [[notes/1.General/CPP DSA/3 Patterns|3 Patterns]]
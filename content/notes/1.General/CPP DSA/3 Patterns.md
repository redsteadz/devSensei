---
title: "Pattern Problems in C++"
description: "Some pattern practing C++"
tags:
- patterns
- cpp
- fundamentals
---

### Decrementing Block of size (n)
f(3) = 321
		  321
		  321

f(2) = 21
		  21

```cpp
int main(){
	int n = 3;
	//cin >> n;
	int j = 1;
	while (j <= n){
		int i = n;
		while (i > 0){
			cout << i;
			i = i - 1;
		};
		cout<<endl;
		j = j + 1;
	}
	return 0;
}
```

### Block of size n of incrementing numbers

```cpp
int main(){
	int n = 3;
	int i = 1;
	int inc = 1;
	while (i <= n){
		int j = 1;
		while (j<=n){
			cout<<inc<<" ";
			inc = inc + 1;
			j = j + 1;
		}
	i = i + 1;
	cout << endl;
	};
	return 0;
}
```

### Triangle Pattern

For star
```cpp
int main(){
	int n = 10;
	int i = 1;
	while (i <= n){
		int count = 1;
		while (count <= i){    // Print * i number of times
			cout << "*";
			count++;
		};
		cout<< endl;
		i++;
	};
	return 0;
}
```

For num of rows
```cpp
int main(){
	int n = 10;
	int i = 1;
	while (i <= n){
		int count = 1;
		while (count <= i){    // Print * i number of times
			cout << i;
			count++;
		};
		cout<< endl;
		i++;
	};
	return 0;
}
```

For this 
![](notes/1.General/CPP%20DSA/attachments/Pasted%20image%2020230821232837.png)

```cpp
int main(){
	int n = 4;
	int r = 1;
	while (r <= 4){
		int c = 1;
		int num = r;
		while(c <= r){
			cout << num;
			num++;
			c++;
		};
		r++;
		cout << endl;
	}
	return 0;
}
```

- [x] Do this without `int num = r` #task


### Blocked Letters Itteration
![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.43.39.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.43.39.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.43.39.excalidraw.dark.svg)%%

```cpp
int main(){
	int n = 3;
	char chr = 65;
	int r = 1;
	while (r <= 3){
		int c = 1;
		while(c <= 3){
			cout << chr << " ";
			c++;
		};
		chr++;
		cout << endl;
		r++;
	};
	return 0;
}
```

![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.51.43.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.51.43.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.51.43.excalidraw.dark.svg)%%

```cpp
int main(){
	int n = 3;
	int r = 1;
	while (r <= n){
		char ch = 65;
		int c = 1;
		while(c <= n){
			cout << ch << " ";
			c++;
			ch++;
		};
		r++;
		cout << endl;
	};
	return 0;
}
```


![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.55.42.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.55.42.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.55.42.excalidraw.dark.svg)%%
```cpp
int main(){
	int n = 3;
	int r = 1;
	char ch = 65;
	while(r <= n){
		int c = 1;
		while (c <= n){
			cout << ch << " ";
			c++;
			ch++;
		};
		cout << endl;
		r++;
	};
	return 0;
}
```



![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.59.08.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.59.08.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-21%2023.59.08.excalidraw.dark.svg)%%

```cpp
int main(){
	int n = 3;
	int r = 1;
	char ch = 65;
	while (r <= n){
		int c = 1;
		while (c <= n){
			char chr = ch+c-1;
			cout << chr << " ";
			c++;
		};
		cout << endl;
		ch++;
		r++;
	};
	return 0;
}
```

![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-23%2010.31.39.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-23%2010.31.39.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-23%2010.31.39.excalidraw.dark.svg)%%

```cpp
int main() {
  int n;
//  char ch = 65;
  int i = 1;
  cin >> n;
  while (i <= n) {
    int c = 1;
    while (c <= i) {
	  char ch = 65 + i - 1;
      cout << ch << ' ';
      c++;
    };
    cout << endl;
   // ch++;
    i++;
  };
  return 0;
};
```


## Alphabetical Triangles
![](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-24%2009.13.59.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-24%2009.13.59.excalidraw.md), and the [dark exported image](notes/1.General/CPP%20DSA/attachments/Patterns%202023-08-24%2009.13.59.excalidraw.dark.svg)%%

```cpp
int main(){
	int n = 4;
	int r = 1;
	while (r <= n){
		int c = 1;
		char ch = ('A' + n - r);
		while(c <= r){
			cout << ch << " ";
			c++;
			ch++;
		};
		cout << endl;
		r++;
	};
	return 0;
};
```

## Patterns with Spaces
![](notes/1.General/CPP%20DSA/attachments/Pasted%20image%2020230824092745.png)

```cpp
int main(){
	int n = 4;
	char sp = 32;
	int r = 1;
	while (r <= n){
		int c = 1;
		int i = 1;
		while (i <= (n - r)){
			cout << " ";
			i++;
		};
		while(c <= r){
			cout<< "*";
			c++;
		};
		cout << endl;
		r++;
	};
	return 0;
}
```

![](notes/1.General/CPP%20DSA/attachments/Pasted%20image%2020230824094056.png)
 ```cpp
 int main(){
	int n = 4;
	int r = 1;
	while (r <= n){
		int c = 1;
		int num = 1;
		int sp = 1;
		// Spaces
		while (sp <= (n-r)){
			cout << " ";
			sp++;
		};


		// Increment
		while (c <= r){
			cout << num;
			c++;
			num++;
		};
		num--;

		// Decrement
		while (num > 1){
			num--;
			cout << num;
		}
		cout << endl;
		r++;
	};
	return 0;
}
```

![](notes/1.General/CPP%20DSA/attachments/Pasted%20image%2020230824101032.png)

```cpp
int main(){
	int n = 5;
	int r = 1;
	while (r <= n){
		int c = 1;
			while (c <= (n - r + 1)){
				cout << c;
				c++;
			};
		int i = 1;
			while ( i <= (r-1)*2){
				cout << "*";
				i++;
			};
			while (c > 1){
				c--;
				cout << c;
			};
		cout << endl;
		r++;
	};
	return 0;
};
```

***NEXT &rarr;*** [[notes/1.General/CPP DSA/4 Bitewise Operators|4 Bitewise Operators]]
---
title: QuickSort
date: 2023-10-01
tags:
  - algorithm
  - quicksort
  - sort
---

The idea of QuickSort is by allowing the elements to sort themselves by finding their respective correct positions
The algorithm can be divided into 2 steps
- Sorting + Returning the Pivot
- Recursively executing this with the new High and Low values

![](notes/1.General/Algorithms/attachments/QuickSort%202023-10-01%2019.43.42.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/Algorithms/attachments/QuickSort%202023-10-01%2019.43.42.excalidraw.md), and the [dark exported image](notes/1.General/Algorithms/attachments/QuickSort%202023-10-01%2019.43.42.excalidraw.dark.svg)%%

```cpp
#include <vector>

void swap(vector <int>& arr, int s1, int s2){
    int t = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = t;
}

int partition(vector <int>& arr, int L, int H){
    int piv = L;
    int i = L;
    int j = H;
    while (i<j){
	    while ( arr[i] <= arr[piv] && i<H-1){ i++; };
	    cout << "The Left thing: " << arr[i] << endl;
	    while (arr[j] > arr[piv] && j > L){j--;}
	    cout << "The Right thing: " << arr[j] << endl;
	    if (i<j){
	        swap(arr, i, j);
	        cout << "Swapping " << i << " " << j << endl;
	    };
    };
    swap(arr, piv, j);
    
    return j;
}

void quickSort(vector <int>& arr, int L, int H){
    if (L < H){
       int piv = partition(arr, L, H);
        quickSort(arr, L, piv-1);
        quickSort(arr, piv+1, H);
    }
}

int main(){
	vector <int> a {4, 6, 2, 5, 7, 9, 1, 3};
	
    quickSort(a, 0, a.size()-1);
	for (int i =0 ; i < a.size(); i++){
		cout << " " << a[i];
	}
	
	return 0;

}
```

## More Efficient version would be

```cpp
void swap(vector <int>& arr, int a, int b){
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

int partition(vector<int>& arr, int l, int h) {
    int pivot = arr[h];  // Choose the pivot element (you don't need the 'i' parameter)
    int x = l - 1;       // Initialize x to be one less than the low index

    for (int y = l; y <= h - 1; y++) {
        if (arr[y] > pivot) {
            x++;  // Increment x
            swap(arr, x, y);  // Swap arr[x] and arr[y]
        }
    }

    swap(arr, x + 1, h);  // Swap the pivot element with arr[x+1]
    
    return x + 1;  // Return the updated position of the pivot
}

int quickSort(vector<int>& arr, int l, int h, int k) {
    if (l <= h) {
        int piv = partition(arr, l, h);

        quickSortt(arr, l, piv - 1, k);
		quickSelect(arr, piv + 1, h, k);
    }
    return 0; // Handle the case when k is out of range
}
```


This new and \*improved idea is basically finding the values larger than the pivot and swapping them with the iterator x which changes position every time a new relative maxima is found, at the end, the final position of the maxima + 1 will be where the pivot is placed, 
Then the same normal quickSort algorithm is observed
This removes the unnecessary two loops that must've ran before and now can be done using a single loop

Another change that could be implemented in this case would be to change the quickSort function making it as such

```cpp
int quickSelect(vector<int>& arr, int k) {
    int l = 0;
    int h = arr.size() - 1;

    while (l <= h) {
        int piv = partition(arr, l, h);

        if (k < piv) {
            h = piv - 1;
        } else if (k > piv) {
            l = piv + 1;
        } else {
            return arr[piv];
        }
    }
    
    return -1; // Handle the case when k is out of range
}
```

Although quickSort is a neat method to work with, It is still slower for larger arrays and becomes inefficient, That's why we can now look at 
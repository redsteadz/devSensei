---
title: "Snail"
tags:
- js
- codewars
- programming
---


# Snail
Given an `n x n` array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

```
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
```

For better understanding, please follow the numbers of the next array consecutively:

```
array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
```

This image will illustrate things more clearly:

![](http://www.haan.lu/files/2513/8347/2456/snail.png)

NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array `[[]]`.

## My solution
```javascript
snail = function(array) {
    // enjoy
    let arr = array
    let snail = []
    while (arr[0] != null && arr.length !== 0){ // Continue till the array is empty
    let cr = []; let cl = []; // Reset the coloumn right and left (cr, cl)

      for (i=1; i<arr.length-1; i++){
              cr.push(arr[i].pop())     // Takes the right most value of column
              cl.unshift(arr[i].shift())// Takes the left most value of column
            }
  
    snail.push(arr.shift()) // Inputs Top

    snail.push(cr) // Inputs Right

    if(arr[0] != null){         //
          let last_r = arr.pop()// Inputs Bottom Value
          last_r.reverse()      //
          snail.push(last_r)}   //
    
      snail.push(cl)// Inputs Left

      arr.length == 1 ? snail.push(arr.shift()) : null // Inputs Center Value
      cr = []
      cl= [] 
    }
  return snail.flat()
}

console.log(snail([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15], [16, 17, 18, 19, 20], [21, 22, 23, 24, 25]]))
```


![](notes/2.CodeQ/4%20kyu/attachments/Snail%202023-01-13%2000.53.26.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/2.CodeQ/4%20kyu/attachments/Snail%202023-01-13%2000.53.26.excalidraw.md), and the [dark exported image](notes/Codedojo/4%20kyu/attachments/Snail%202023-01-13%2000.53.26.excalidraw.dark.svg)%%
## Algorithm
Snail = Top + Right + Bottom.reversed() + Left - Repeat till Array is empty

In order to do this question, I made the array it self a condition. The algorithm will stop when the array is empty
So the while loop:
```javascript
while (arr[0] != null && arr.length !== 0)
```
Makes sure that happens
After words you We will make a new loop That goes through the array, excluding the first and last subarray (They are the top and bottom pieces)
Hence the lines
```javascript
 let cr = []; let cl = []; // Reset the coloumn right and left (cr, cl)

      for (i=1; i<arr.length-1; i++){
              cr.push(arr[i].pop())     // Takes the right most value of column
              cl.unshift(arr[i].shift())// Takes the left most value of column
            }
```
arr[i] represents a subarray, and so we can use this logic

Lets look at this step by step
- **cr (Column Right)**
	- the array.pop() method "pops" The last value of array and returns it
	- We take this value and "push" it to cr which will push its last value
- **cl(Column Left)**
	- The array.shift() method "shifts" the first value and returns it
	- We are taking this value and "unshifting" it the first value of Column left
 This can be illustrated in a diagram like so
![](notes/2.CodeQ/4%20kyu/attachments/Snail%202023-01-13%2017.46.07.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/2.CodeQ/4%20kyu/attachments/Snail%202023-01-13%2017.46.07.excalidraw.md), and the [dark exported image](notes/Codedojo/4%20kyu/attachments/Snail%202023-01-13%2017.46.07.excalidraw.dark.svg)%%
 Now we have left and right columns in an array cl and cr
 Now it's easy!
```javascript
snail.push(arr.shift()) // Inputs Top

snail.push(cr) // Inputs Right

if(arr[0] != null){         //
    let last_r = arr.pop()// Inputs Bottom Value
	last_r.reverse()      //
	snail.push(last_r)}   //
    
snail.push(cl)// Inputs Left

arr.length == 1 ? snail.push(arr.shift()) : null // Inputs Center Value
cr = []
cl= [] 
    }
return snail.flat()
}
```
1. Inputs the top/first sub array in the array
2. Inputs the Right sub array in the array
3. Inputs the Bottom Value IF array is not yet empty
4. Inputs the Left Value
5. Checks if array only has 1 subarray remaining, This would mean a centter value. So just add that
6. array.flat() Flattens the subarray in to their elements so
```javascript
let array = [1, [2], [3,4]]
console.log(array.flat())
```


## Just better !
```javascript
snail = function(array) {
  var result;
  while (array.length) {
    // Steal the first row.
    result = (result ? result.concat(array.shift()) : array.shift());
    // Steal the right items.
    for (var i = 0; i < array.length; i++)
      result.push(array[i].pop());
    // Steal the bottom row.
    result = result.concat((array.pop() || []).reverse());
    // Steal the left items.
    for (var i = array.length - 1; i >= 0; i--)
      result.push(array[i].shift());
  }
  return result;
}
```

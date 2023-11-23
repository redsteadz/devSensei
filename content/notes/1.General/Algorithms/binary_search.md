---
title: "Binary Search"
description: "The binary search algorithm it's understanding and some of it's application"
date: "2023-08-11"
tags:
- fundamental
- binary_search
- algorithm
- general
---

## Description 
This search basically searches through the array by starting from the middle, checking if the value is > or < than middle. Henceforth make a new middle in that range -- Repeat this processHere's a step-by-step description of using binary search to play the guessing game:

1. Let *min* = 1, and *max* = n.
2. Guess the average of max and min, rounded down so that it is an integer.
3. If you guessed the number, stop. You found it!
4. If the guess was too low, set min to be one larger than the guess.
5. If the guess was too high, set max to be one smaller than the guess.
6. Go back to step two.
### Visual Representation
![](notes/1.General/attachments/binary_search%202023-08-11%2017.24.49.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/attachments/binary_search%202023-08-11%2017.24.49.excalidraw.md), and the [dark exported image](notes/1.General/attachments/binary_search%202023-08-11%2017.24.49.excalidraw.dark.svg)%%

### Javascript:

```js
var doSearch = function(array, targetValue) {
    var min = 0;
    var max = array.length - 1;
    var guess;
    while( min <= max ){
        guess = Math.floor((min + max)/2) ;
        if( array[guess] === targetValue){ return guess; }
        else if( array[guess] < targetValue ){ min = guess + 1; }
        else{ max = guess - 1;}
    }
    return -1;
};
```

![](notes/1.General/attachments/Pasted%20image%2020230811222815.png)


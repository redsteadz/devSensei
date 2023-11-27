---
title: Maps in react
description: How the array.maps is used in react
tags:
  - react
  - fundamentals
date: 2014-11-14
---

```js
array = [1, 2, 3]

function App(){
	return(
		array.map((item)=>{
			<h1> item </h1>
		})
	)
}
```

## Pointers:
- The `map()` method creates a new array by performing a function on each array element.
- The `map()` method does not execute the function for array elements without values.
- The `map()` method does not change the original array.

### Example
```js
const numbers1 = [45, 4, 9, 16, 25];  
const numbers2 = numbers1.map(myFunction);  
  
function myFunction(value, index, array) {  
  return value * 2;  
}
console.log(numbers2)
```

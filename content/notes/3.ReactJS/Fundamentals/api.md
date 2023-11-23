---
title: "API-React"
tags:
- react
- api
- fundamentals
---

API can be fetched through javascript by the following code
```js
    const url = "API url"
    
    const [data, setData] = useState(["List/Data set with default data to prevent errors"]);
    async function fetchInfo(){ 
        const res = await fetch(url);
        const d = await res.json();
        return setData(d); 
        }
    useEffect(()=>{
        fetchInfo();
    }, [])
```
The thing to keep in mind here is that JS is an asynchronous language, so it basically doesn't give a damn what process is happening before and just process the function on another thread while it continues processing the rest of the data

What this means is that
```js
function call(){
	console.log("HEY I AM A FUNCTION")
	// A LOT OF GIBBERISH CALCULATIONS
}
console.log("And I was outside of the function")
```
At the end, `call()` will be called after because it was taking more time to process, while the program continues to process data and gets to outside function



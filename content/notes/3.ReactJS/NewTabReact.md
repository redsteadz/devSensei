---
title: NewTabReact
tags:
  - react
  - projects
  - how-to
  - step-by-step
date: 2023-10-20
---

I've seen some really cool NewTab front pages for featured on github for [r/unixporn](https://www.reddit.com/r/unixporn/)
LIKE
- [Bento](https://github.com/migueravila/Bento)
- [markdown--new-tab](https://github.com/plibither8/markdown-new-tab)
- [devo](https://github.com/karakanb/devo)
- [mue](https://github.com/mue/mue)

## The Design

![Safari • Dark Mode ON 1](notes/3.ReactJS/attachments/Safari_dark_mode.png)


## Simple Features
- AutoScrapped Quotes
- Weather
- Chess Puzzle from lichess API

### Component BreakDown
![](notes/3.ReactJS/attachments/NewTabReact%202023-07-01%2001.26.09.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/3.ReactJS/attachments/NewTabReact%202023-07-01%2001.26.09.excalidraw.md), and the [dark exported image](notes/3.ReactJS/attachments/NewTabReact%202023-07-01%2001.26.09.excalidraw.dark.svg.md)%%

## Make the Basic Structure of the App

### NavBar
This one is actually oddly simple, as the basic structure of the navbar is only based on GoogleSearch being hooked too the input, some border style and we are done

```js
import './Navbar.css'

function Navbar() {
  return (
  <div className='nav_container'>
     <nav className='nav_bar'> <input className="search_bar" type="?" placeholder=' Google Search '/>  </nav> 
  </div>
  );
}

export default Navbar;
```

CSS
```css
.nav_container {
    display: flex;
    justify-content: center;
    margin: 30px 0 30px 0;
}

.search_bar{
    border: 3px solid cyan;
    width: 300px;
    height: 30px;
    border-radius: 20px;
    text-align: center;
    font-size: large;
    background-image: url("searchIcon.svg");
    background-repeat: no-repeat;
    background-size: contain;
    background-position: right;

}
```

![](notes/3.ReactJS/attachments/Peek%202023-07-27%2018-24.gif)


### Input entry to Google search
Simple HTML was just applied !
```html
 <form action="http://www.google.com/search" method="get">
	<input className="search_bar" name="q" type="text" placeholder=' Google Search '/>
</form>
```

## The Action Attribute

The `action` attribute defines the action to be performed when the form is submitted.

Usually, the form data is sent to a file on the server when the user clicks on the submit button.

In the example below, the form data is sent to a file called "action_page.php". This file contains a server-side script that handles the form data:

**Notes on GET:**

- Appends the form data to the URL, in name/value pairs
- NEVER use GET to send sensitive data! (the submitted form data is visible in the URL!)
- The length of a URL is limited (2048 characters)
- Useful for form submissions where a user wants to bookmark the result
- GET is good for non-secure data, like query strings in Google

**Notes on POST:**

- Appends the form data inside the body of the HTTP request (the submitted form data is not shown in the URL)
- POST has no size limitations, and can be used to send large amounts of data.
- Form submissions with POST cannot be bookmarked

### Logic of Za URL forms (Google)
![](notes/3.ReactJS/attachments/NewTabReact%202023-07-27%2018.36.48.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/3.ReactJS/attachments/NewTabReact%202023-07-27%2018.36.48.excalidraw.md), and the [dark exported image](notes/ReactJS/attachments/NewTabReact%202023-07-27%2018.36.48.excalidraw.dark.svg)%%


### Making a theme generated background paper
Not possible ?
Found [BGJar](https://bgjar.com/) to for really nice background patterns!

### Implementing a Working clock
#### An Updating Clock and "useEffect" - ChatGPT

To implement an updating clock in React, you can follow these steps:
1. Create a new React component for the clock. For example, you can name it "Clock".
2. In the component, initialize a state variable to hold the current time. This can be done using the `useState` hook.
```jsx
   import React, { useState } from "react";

   const Clock = () => {
     const [time, setTime] = useState(new Date());

     return (
       <div>{time.toLocaleString()}</div>
     );
   };

   export default Clock;
```

3. Next, you need to update the time every second. This can be achieved using the `setInterval` function. At the same time, you should handle the cleanup of the interval when the component unmounts. To do this, you can use the `useEffect` hook.

   ```jsx
   import React, { useState, useEffect } from "react";

   const Clock = () => {
     const [time, setTime] = useState(new Date());

     useEffect(() => {
       const timerID = setInterval(() => setTime(new Date()), 1000);
       return () => {
         clearInterval(timerID);
       };
     }, []);

     return (
       <div>{time.toLocaleString()}</div>
     );
   };

   export default Clock;
   ```


4. Finally, you can render the `Clock` component in your main app component or any other component where you want to display the clock.


```jsx
   import React from "react";
   import Clock from "./Clock";

   const App = () => {
     return (
       <div>
         <h1>Current Time:</h1>
         <Clock />
       </div>
     );
   };

   export default App;
```

With these steps, the clock component will update the displayed time every second while using React's state and hooks.

### The [[notes/3.ReactJS/Fundamentals/useEffect|useEffect]]
The `useEffect` hook is a built-in hook in React that allows you to perform side effects in functional components. Side effects are any code that needs to be executed outside the normal flow of the component, such as fetching data, subscribing to events, or manually modifying the DOM.

The `useEffect` hook takes two parameters: a callback function and an optional dependency array. The callback function is executed after the component renders, and it can return a cleanup function that will be executed before the component is unmounted or re-rendered. The dependency array specifies the values that the effect depends on, and it allows you to control when the effect should run or be skipped.

Here's an example of using `useEffect` to fetch data from an API:

```javascript
import React, { useEffect, useState } from "react";

function MyComponent() {
  const [data, setData] = useState([]);

  useEffect(() => {
    // Fetch data from API
    fetch("https://api.example.com/data")
      .then((response) => response.json())
      .then((data) => setData(data));
  }, []);

  return (
    <div>
      {data.map((item) => (
        <p key={item.id}>{item.name}</p>
      ))}
    </div>
  );
}
```

In this example, the effect will run only once, immediately after the component renders for the first time, because the dependency array is empty. If you specify a dependency array with values, the effect will run whenever any of those values change.

[[notes/3.ReactJS/Fundamentals/useEffect|useEffect]] is a powerful tool for managing side effects in functional components and helps to keep the logic of the component organized and easy to understand.



![](notes/3.ReactJS/attachments/Pasted%20image%2020230731164437.png)

*The actual progress is a bit different due to the different styles give to this !*

## Hooking up [[notes/3.ReactJS/Fundamentals/api|api]]
Now that we have the overall structure built, We can start to implement the API that take the data from the respective API of 
- [Quotable](https://github.com/lukePeavey/quotable)
- [OpenWeather](https://openweathermap.org/api)
The general code for getting the JSON from an API is; #snippet 

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

The interesting this that Javascript is an async language, the thing doesn't wait for one code to execute and goes on to the next, Meaning calling to retreive the data through

```jsx
<h1 className='qotd base'>  {data[0]["content"]}  <br></br>  <span className='author'> {data[0]["author"]} </span> </h1>
```

It would give an error if it weren't for the default values of data that we gave in the `useState`

## BottomSection
Just a list of links for ease of use the JSX and CSS of which are;

In order to get the icons, using [[notes/3.ReactJS/Fundamentals/react-icons|react-icons]] was a blessing !


```jsx
function Links(){
    return (
        <div className='link_section'>
            <div classname='link_box1'>
                <ul className='link_list'>
                    <span className='icon'><MdSportsEsports size={"3em"}/></span>
                    <li className='link_item'><a className='links' href=""> YouTube </a></li>
                    <li className='link_item'><a className='links' href=""> Netflix </a></li>
                    <li className='link_item'><a className='links' href=""> DopeBox </a></li>
                    <li className='link_item'><a className='links' href=""> 9anime </a></li>
                </ul>
            </div>
            <div classname='link_box2'>
                <ul className='link_list'>
                    <span className='icon'><BsFillGearFill size={"3em"}/></span>
                    <li className='link_item'><a className='links' href=""> links! </a></li>
                    <li className='link_item'><a className='links' href=""> links! </a></li>
                    <li className='link_item'><a className='links' href=""> links! </a></li>
                    <li className='link_item'><a className='links' href=""> links! </a></li>
                </ul>
            </div>
        </div>
    )
}
```

## Result;

![](notes/3.ReactJS/attachments/screencapture-localhost-3000-2023-08-01-02_27_15.png)


## Adding a GitHubCalendar 
[Reference](https://grubersjoe.github.io/react-github-calendar/)
[Activity-Calendar](https://grubersjoe.github.io/react-activity-calendar/?path=/docs/react-activity-calendar--docs)

So first we just need to install the component so that we can import it

```bash
npm install react-github-calendar
```

Then add it to your respective Application

```js 
import GitHubCalendar from 'react-github-calendar'

function App(){
	return(// You apps
		<GitHubCalendar username='USERNAME' blockSize={24} style={{fontFamily:'Montserrat', margin:'3vh', fontWeight:'600', borderColor:'white'}} theme={colourTheme} transformData={Filter}/>
	)
}
```

This function gives an entire graph for the whole year, but this can be changed by using filtering and `transformData`

### Filtering the last 6 months

```js
const selectLastHalfYear = contributions => {
  const currentYear = new Date().getFullYear();
  const currentMonth = new Date().getMonth();
  const shownMonths = 6;

  return contributions.filter(activity => {
    const date = new Date(activity.date);
    const monthOfDay = date.getMonth();

    return (
      date.getFullYear() === currentYear &&
      monthOfDay > currentMonth - shownMonths &&
      monthOfDay <= currentMonth
    );
  });
};
```

`transformData={}` runs a function on an array of data (contributions), then we can have a constant for the current year and month. Using this data we can filter it out

`filter()` is a function which runs over the items of the data returning the satisfied data. Then checks if
- The year of data === This year
- monthofData is greater than the previous **6** months
- monthofData is less than or the same as the currentMonth

### [[notes/3.ReactJS/Fundamentals/Responsive_Design|Responsive_Design]]


Learn it if you need to !
The whole idea about making a "responsive" design was to hook up values window size to the scale of the components [[notes/3.ReactJS/Fundamentals/Measurement values|Measurement values]]

# Finale

![](notes/3.ReactJS/attachments/screencapture-localhost-3000-2023-08-01-19_12_41.png)


## Implementing the Loop for links
We can go over the key values of an object by 
```js
const link1 = [{
        name:"YouTube" ,
        link:"https://youtube.com/"
    },{
        name:"DopeBox" ,
        link:"https://dopebox.to/"
    },{
        name:"Netflix" ,
        link:"https://netflix.com/"
    },{
        name:"9anime" ,
        link:"https://netflix.com/"
    },]

  let Link1 = linkList1.map((obj)=>{
        return (<li className='link_item'><button className='links' onClick={()=>{window.open(obj.link)}}> {obj.name} </button></li>)
    })
```

[[Reacts Best Practice]]

# Deployment
Simply followed this incredible guide! 
[react-gh-pages](https://github.com/gitname/react-gh-pages)

Definitely need to learn how to properly, easily make responsive design.. Maybe by using a framework?

# Task Board
## Done
- [x] Make [[notes/3.ReactJS/NewTabReact|NewTabReact]] Responsive #task  [completion:: 2023-08-01]
- [x] Transform this into loops by taking data from a list of links #task  [completion:: 2023-08-04]
- [x]  QOTD and Weather API to [[notes/3.ReactJS/NewTabReact|NewTabReact]] #task  [completion:: 2023-07-31]
- [x] A safe and easy way to import API keys to the public repo
	- [Using .env in gh-pages](https://stackoverflow.com/questions/53648652/how-to-use-environment-variables-in-github-page)
	- [dotenv React](https://www.smashingmagazine.com/2023/05/safest-way-hide-api-keys-react/)
- [x] The mobile UI is bad! need to fix it #task
- [x] Make the search icon an object instead of background #task  [completion:: 2023-08-06]

## Problems
- [x] Fixing the App for best practices! #task

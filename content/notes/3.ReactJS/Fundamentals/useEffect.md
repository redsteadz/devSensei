---
title: useEffect
date: 2023-08-12
tags:
  - react
  - hooks
  - fundamental
---
[001. Resources](notes/5.Resources/001.%20Resources.md)
- [w3schools](https://www.w3schools.com/react/react_useeffect.asp)
- [reactDev](https://react.dev/reference/react/useEffect)
- [blog](https://dmitripavlutin.com/react-useeffect-explanation/)
- ![](https://www.youtube.com/watch?v=0ZJgIjIuY7U)
## Syntax
```js
function callback(){
// The SIDE EFFECT
	return() =>{
		// The Cleanup of the side effect
		cleanup()
	};
}
useEffect(callback[, dependencies])
```

- `callback` is a function that contains the side-effect logic. `callback` is executed right after the DOM update.
- `dependencies` is an optional array of dependencies. `useEffect()` executes `callback` only if the dependencies have changed between renderings.

>[!multi-column]
>>[!blank-container]
>>The **Effect** part basically gives an idea about what this is ! It basically creates a side-effect when a component is mounted; but that is not the limitation of this Hook. It is capable of running with condition like:
>>1. Whenever the component is mounted and unmounted
>>2. The dependency has a changed between re rendering
>
>>[!blank-container]
>>![](notes/3.ReactJS/Fundamentals/attachments/07063bf82fd4717b63fce29e0001b5c6%203.gif ) 
## Easy Explanation;
You know those potion effect in minecraft ? 
Well, usually they are independent of whatever or wherever the hell the player is ! 
the `callback` is the effect of those potions, and the action of throwing/drinking the potion is dependent on;
- Mounting/Unmounting the component (Regeneration potion for fighting, Regeneration potion after fighting)
- Dependencies (If health is low, then drink them potions)
- The `cleanup()` function can be thought of as drinking milk to remove all effects! (But that `cleanup()` can technically be anything)



A **side effect** is any action that is independent of the output
While props / states work on the output directly and the functionality of the component, `useEffect` releases a `callback` function which is can remain disconnected to the changes of component

### Flowchart
![](notes/3.ReactJS/Fundamentals/attachments/useEffect%202023-07-29%2002.05.22.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/3.ReactJS/Fundamentals/attachments/useEffect%202023-07-29%2002.05.22.excalidraw.md), and the [dark exported image](notes/3.ReactJS/Fundamentals/attachments/useEffect%202023-07-29%2002.05.22.excalidraw.dark.svg)%%
[Source](https://dmitripavlutin.com/d0532a1ba251b6730f64aff0a02b0925/react-useeffect-hook-cleanup.svg)

A thing to not here is that there is another `cleanup()` return which is capable running when the component is unmounted !
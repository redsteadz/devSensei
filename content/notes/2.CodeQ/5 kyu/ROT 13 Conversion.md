---
title: "ROT 13 Conversion"
tags:
- js
- codewars
- programming

---

# ROT13 conversion
- [ROT13](https://www.codewars.com/kata/52223df9e8f98c7aa7000062/train/javascript)
How can you tell an extrovert from an introvert at NSA? Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it? According to Wikipedia, ROT13 ([http://en.wikipedia.org/wiki/ROT13](http://en.wikipedia.org/wiki/ROT13)) is frequently used to obfuscate jokes on USENET.

Hint: For this task you're only supposed to substitue characters. Not spaces, punctuation, numbers etc.

Test examples:

```
"EBG13 rknzcyr." -->
"ROT13 example."

"This is my first ROT13 excercise!" -->
"Guvf vf zl svefg EBG13 rkprepvfr!"
```
## My Solutions:
````javascript
function rot13(str) {
  var lett = "abcdefghijklmnopqrstuvwxyz"
  let sh = str.split("")
  for (i=0; i<sh.length; i++){
    index = lett.indexOf(sh[i].toLowerCase())
    if (index != -1){
      jumped = index + 13
      jumped >= 26 ? jumped -=26 : jumped=jumped
      sh[i] == sh[i].toUpperCase() ? sh[i] = lett[jumped].toUpperCase() :sh[i] = lett[jumped]
    }
  }
  return sh.join("")
}

console.log(rot13("Depression"))
````
## Recommended:
```javascript
function rot13(str) {
  return str.replace(/[a-z]/ig, function(x){
    return String.fromCharCode(x.charCodeAt(0) + (x.toLowerCase() <= 'm' ? 13: -13));
  });
}
console.log(rot13("Depression"))
```

> [!info]-
> 
> `str.replace(/[a-z]/ig, f(x))` 
> - Regular Expression [a-z] takes all the alphabets, not case sensitive and replaces is it according to f(x)
>   
>`return String.fromCharCode(x.charCodeAt(0) + (x.toLowerCase() <= 'm' ? 13: -13));
  });`
> - Returns the Char + 13 if alphabet is smaller then m, or Char - 13 if alphabet is larger then 'm'; As Unicode characters are consecutive, it works for capitalised and non capitalised!





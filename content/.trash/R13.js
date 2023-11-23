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

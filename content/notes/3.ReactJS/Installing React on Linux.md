
---
title: "Installing React on Linux"
tags:
- react
- basic
- how-to
- fundamentals
- install
---
React comes with NodeJS so basically only NodeJS needs to be installed for it to start functioning

```
sudo pacman -S nodejs
```
Does the trick!

## Setting up VS Code
List of extensions used in React and their overall summary:
- Auto Rename Tag
	- Automatically rename paired HTML/XML tag, same as Visual Studio IDE does
- Bracket Pair color DLW
	- Gives each brackets unique colors
		- `Ctrl + Shift + P` Search for "Toggle Bracket Color DLW"
- Live Server
	- For Launching a local development server with live reload feature for static & dynamic pages.
- ES7+ React/Redux
	- JavaScript and React/Redux snippets in ES7+ with Babel plugin features for [VS Code](https://code.visualstudio.com/ "https://code.visualstudio.com/")
- Thunder Client
	- Thunder Client is a lightweight Rest API Client Extension for Visual Studio Code

## Possible issues
```
npm ERR! network Invalid response body while trying to fetch [https://registry.npmjs.org/postcss-import](https://registry.npmjs.org/postcss-import): Socket timeout  
npm ERR! network This is a problem related to network connectivity.  
npm ERR! network In most cases you are behind a proxy or have bad network settings.

```

An issue that is probably related to NPM version

#### Solution:
Install a different version of **npm** and use that instead, In linux it is easy to do by using **nvm**
```
paru -S nvm
// -- OR -- //
yay -S nvm
```

Choose the npm version from the list that is offered by nvm
```
nvm ls-remote
```

This lists versions of npm, Choose the one you'd want to use and install by, for example for a version of node 14.17.5
```
nvm install 14.17.5
...
# Use by
nvm use 14.17.5
```

Run the command of create-react-app again !


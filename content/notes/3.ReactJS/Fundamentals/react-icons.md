---
title: React-icons
tags:
  - fundamentals
  - react
  - react_pkg
  - docs
date: 2023-09-21
---

Include popular icons in your React projects easily with react-icons, which utilizes ES6 imports that allows you to include only the icons that your project is using.

Installation (for standard modern project)
`npm install react-icons --save`
Usage
```js
import { FaBeer } from 'react-icons/fa';
class Question extends React.Component {
  render() {
    return <h3> Lets go for a <FaBeer />? </h3>
  }
}
```

# Installation (for meteorjs, gatsbyjs, etc)
If your project grows in size, this option is available. This method has the trade-off that it takes a long time to install the package. Suitable for MeteorJS, Gatsbyjs etc.
`npm install @react-icons/all-files --save`
## Usage
```js
import { FaBeer } from "@react-icons/all-files/fa/FaBeer";
class Question extends React.Component {
  render() {
    return <h3> Lets go for a <FaBeer />? </h3>
  }
}
```

The icons can be found [here](https://react-icons.github.io/react-icons/)

# Customizing the icons [configuration](https://github.com/react-icons/react-icons#configuration)
## Configuration

You can configure react-icons props using [React Context API](https://reactjs.org/docs/context.html).

_Requires **React 16.3** or higher._

```js
import { IconContext } from "react-icons";

<IconContext.Provider value={{ color: "blue", className: "global-class-name" }}>
  <div>
    <FaFolder />
  </div>
</IconContext.Provider>;
```

|Key|Default|Notes|
|---|---|---|
|`color`|`undefined` (inherit)||
|`size`|`1em`||
|`className`|`undefined`||
|`style`|`undefined`|Can overwrite size and color|
|`attr`|`undefined`|Overwritten by other attributes|
|`title`|`undefined`|Icon description for accessibility|

## [](https://github.com/react-icons/react-icons#migrating-from-version-2---3)Migrating from version 2 -> 3

### [](https://github.com/react-icons/react-icons#change-import-style)Change import style

Import path has changed. You need to rewrite from the old style.

```js
// OLD IMPORT STYLE
import FaBeer from "react-icons/lib/fa/beer";

function Question() {
  return (
    <h3>
      Lets go for a <FaBeer />?
    </h3>
  );
}
```

```js
// NEW IMPORT STYLE
import { FaBeer } from "react-icons/fa";

function Question() {
  return (
    <h3>
      Lets go for a <FaBeer />?
    </h3>
  );
}
```

Ending up with a large JS bundle? Check out [this issue](https://github.com/react-icons/react-icons/issues/154).

### [](https://github.com/react-icons/react-icons#adjustment-css)Adjustment CSS

From version 3, `vertical-align: middle` is not automatically given. Please use IconContext to specify className or specify an inline style.

#### [](https://github.com/react-icons/react-icons#global-inline-styling)Global Inline Styling

```tsx
<IconContext.Provider value={{ style: { verticalAlign: 'middle' } }}>
```

#### [](https://github.com/react-icons/react-icons#global-classname-styling)Global `className` Styling

Component

```tsx
<IconContext.Provider value={{ className: 'react-icons' }}>
```

CSS

```css
.react-icons {
  vertical-align: middle;
}
```

### [](https://github.com/react-icons/react-icons#typescript-native-support)TypeScript native support

Dependencies on `@types/react-icons` can be deleted.

#### [](https://github.com/react-icons/react-icons#yarn)Yarn

```shell
yarn remove @types/react-icons
```

#### [](https://github.com/react-icons/react-icons#npm)NPM

```shell
npm remove @types/react-icons
```



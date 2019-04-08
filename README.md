This is [Bucklescript](https://bucklescript.github.io/) bindings for [react-dropdown](https://github.com/fraserxu/react-dropdown).

# Install, [npm](https://www.npmjs.com/package/bs-react-dropdown)

```
npm install --save bs-react-dropdown
```

# Setup

Add bs-react-dropdown to `bs-depenencies` in your `bsconfig.json`!

```js
{
  /* ... */
  "bs-dependencies": [
    "bs-react-dropdown"
  ],
  /* ... */
}
```

# Dropdown option type

```re
type dropdownOption = {
  label: string,
  value: string,
  className: option(string),
};
```

# Basic usage

```re
open Dropdown;

let component = ReasonReact.statelessComponent(__MODULE__);

let options: dropdownOptions = [|
  {label: "label1", value: "value1", className: Some("class1")},
  {label: "label2", value: "value2", className: Some("class2")},
|];

let make = _children => {
  ...component,
  render: self => {
    <Dropdown options />;
  },
};
```

Check reducer component [example](https://github.com/ixzzd/bs-react-dropdown/tree/master/examples/reducer_component.re)


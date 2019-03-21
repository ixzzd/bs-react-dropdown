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

# Usage simple stateless component
```re
open Dropdown;
let component = ReasonReact.statelessComponent(__MODULE__);
let options: inputOptions = [|
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

# Usage reducer component
```re
open Dropdown;

type state = {placeholder: string};

type action =
  | UpdatePlaceholder(string);

let component = ReasonReact.reducerComponent(__MODULE__);

let options: inputOptions = [|
  {label: "label1", value: "value1", className: Some("class1")},
  {label: "label2", value: "value2", className: Some("class2")},
|];

let make = _children => {
  ...component,
  initialState: () => {placeholder: "i am placeholder"},
  reducer: (action, _) =>
    switch (action) {
    | UpdatePlaceholder(placeholder) =>
      ReasonReact.Update({placeholder: placeholder})
    },
  render: self => {
    <Dropdown
      options
      placeholder={self.state.placeholder}
      onChange={option => self.send(UpdatePlaceholder(valueGet(option)))}
    />;
  },
};
```

# Helpers

You have to use getters for receive attributes from option (`valueGet(option)` and `labelGet(option)`)

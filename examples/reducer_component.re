open Dropdown;

type state = {value: option(string)};

type action =
  | UpdateValue(string);

let component = ReasonReact.reducerComponent(__MODULE__);

let options: dropdownOptions = [|
  {label: "label1", value: "value1", className: Some("class1")},
  {label: "label2", value: "value2", className: Some("class2")},
|];

let make = _children => {
  ...component,
  initialState: () => {value: None},
  reducer: (action, _) =>
    switch (action) {
    | UpdateValue(value) => ReasonReact.Update({value: Some(value)})
    },
  render: self => {
    <Dropdown
      options
      value={self.state.value}
      onChange={outputOption => {
        self.send(UpdateValue(outputOption.value));
      }}
    />;
  },
};

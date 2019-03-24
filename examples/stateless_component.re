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

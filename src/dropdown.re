[@bs.module "react-dropdown"]
external dropdown: ReasonReact.reactClass = "default";

[@bs.deriving {jsConverter: newType}]
type dropdownOption = {
  label: string,
  value: string,
  className: option(string),
};
type dropdownOptions = array(dropdownOption);

[@bs.obj]
external makeProps:
  (
    ~options: array(abs_dropdownOption),
    ~className: string=?,
    ~placeholder: string=?,
    ~baseClassName: string=?,
    ~controlClassName: string=?,
    ~placeholderClassName: string=?,
    ~menuClassName: string=?,
    ~arrowClassName: string=?,
    ~disabled: bool=?,
    ~value: option(string)=?,
    ~onFocus: bool => unit=?,
    ~onChange: abs_dropdownOption => unit=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~options: dropdownOptions,
      ~className=?,
      ~placeholder=?,
      ~baseClassName=?,
      ~controlClassName=?,
      ~placeholderClassName=?,
      ~menuClassName=?,
      ~arrowClassName=?,
      ~disabled=?,
      ~value=?,
      ~onFocus=?,
      ~onChange=?,
      _children,
    ) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=dropdown,
    ~props=
      makeProps(
        ~options=options |> Array.map(opt => dropdownOptionToJs(opt)),
        ~className?,
        ~placeholder?,
        ~baseClassName?,
        ~controlClassName?,
        ~placeholderClassName?,
        ~menuClassName?,
        ~arrowClassName?,
        ~disabled?,
        ~value?,
        ~onFocus?,
        ~onChange?,
        (),
      ),
    _children,
  );
};

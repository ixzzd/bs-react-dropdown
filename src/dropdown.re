[@bs.module "react-dropdown"]
external dropdown: ReasonReact.reactClass = "default";

[@bs.deriving {jsConverter: newType}]
type inputOption = {
  label: string,
  value: string,
  className: option(string),
};
[@bs.deriving abstract]
type outputOption = {
  label: string,
  value: string,
};

[@bs.obj]
external makeProps:
  (
    ~options: array(abs_inputOption),
    ~className: string=?,
    ~placeholder: string=?,
    ~baseClassName: string=?,
    ~controlClassName: string=?,
    ~placeholderClassName: string=?,
    ~menuClassName: string=?,
    ~arrowClassName: string=?,
    ~disabled: bool=?,
    ~value: abs_inputOption=?,
    ~onFocus: bool => unit=?,
    ~onChange: outputOption => unit=?
  ) =>
  _ =
  "";

let make =
    (
      ~options,
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
        ~options=options |> Array.map(opt => inputOptionToJs(opt)),
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
      ),
    _children,
  );
};

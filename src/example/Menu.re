let component = ReasonReact.statelessComponent("Menu");

let make = (~ref=(_) => (), _children) => {
  ...component,
  render: _self =>
    <div
      ref
      style=(
        ReactDOMRe.Style.make(
          ~width="100%",
          ~height="100%",
          ~display="inline-block",
          ~background="indianred",
          (),
        )
      )>
      <p> (ReasonReact.string("Menu")) </p>
    </div>,
};

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~display="grid",
          ~gridTemplateColumns="1fr 5fr",
          ~gridTemplateRows="60px 1fr",
          (),
        )
      )>
      <HoverSource> ...(r => <Menu ref=r />) </HoverSource>
      <div>
        <button className="Button">
          (ReasonReact.string("Example button"))
        </button>
        <p> (ReasonReact.string("Hello")) </p>
      </div>
    </div>,
};

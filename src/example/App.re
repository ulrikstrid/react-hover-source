let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <HoverSource>
        ...<div
             style=(
               ReactDOMRe.Style.make(
                 ~width="100%",
                 ~height="60px",
                 ~background="indianred",
                 (),
               )
             )>
             <p> (ReasonReact.string("Menu")) </p>
           </div>
      </HoverSource>
      <HoverSource>
        ...<div> <p> (ReasonReact.string("Hello")) </p> </div>
      </HoverSource>
    </div>,
};

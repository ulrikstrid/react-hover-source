type timerId;
[@bs.val] external setTimeout : (unit => unit, int) => timerId = "setTimeout";

/* State declaration */
type state = {show: bool, outline: bool};

/* Action declaration */
type action =
  | Toggle
  | ToggleOutline;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("HoverSource");

let make = children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {show: false, outline: false},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    | ToggleOutline => ReasonReact.Update({...state, outline: !state.outline})
    },
  didMount: self => {
    let keyDownListener = (e) => {
      setTimeout(() => self.send(ToggleOutline), 1200) |> ignore;
      switch (Webapi.Dom.KeyboardEvent.key(e)) {
    | "Alt" => self.send(ToggleOutline)
    | _ => ()
    }};
    Webapi.Dom.Document.addKeyDownEventListener(keyDownListener, Webapi.Dom.document);
    self.onUnmount(() => Webapi.Dom.Document.removeKeyDownEventListener(keyDownListener, Webapi.Dom.document));
  },
  render: self => {
    let display = self.state.show ? "block" : "none";
    let outline = self.state.outline ? "0 0 3px 3px rgba(135,206,235,0.6)" : "none";

    <div
      onMouseOver=(_event => self.send(Toggle))
      onMouseOut=(_event => self.send(Toggle))
      style=(ReactDOMRe.Style.make(~transition="box-shadow 1s ease-in-out", ~boxShadow=outline, ()))>
      <pre
        className="language-html"
        style=(
          ReactDOMRe.Style.make(
            ~display,
            ~position="fixed",
            ~top="40px",
            ~padding="10px",
            ~border="2px solid black",
            ~zIndex="10",
            (),
          )
        )>
        <code dangerouslySetInnerHTML=({ "__html":
          Prism.highlight(HtmlBeautify.htmlBeautify(
            ReactDOMServerRe.renderToStaticMarkup(children)
            ), Prism.html
          )
        }) />
      </pre>
      children
    </div>;
  },
};

let default = ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));

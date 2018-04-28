# react-hover-source

A component to show the generated html from a react component on hover. Useful in style guide like scenarios where you build components in react and want to use them as plain html.

When pressing the alt key all components wrapped in a HoverSource component will be highlighted.

## Usage

```ocaml
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
```

```js
import * as React from "react";

const App = () => (
  <div>
    <HoverSource>
      <div
        style={{
          width: "100%",
          height: "60px",
          background: "indianred"
        }}
      >
        <p> Menu </p>
      </div>
    </HoverSource>
    <HoverSource>
      <div>
        <p> Hello </p>
      </div>
    </HoverSource>
  </div>
);
```

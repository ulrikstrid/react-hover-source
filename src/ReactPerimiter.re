[@bs.module "react-perimeter"]
external reactPerimiter : ReasonReact.reactClass = "default";

let make = (~padding: int, ~onBreach, ~onLeave, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactPerimiter,
    ~props={"padding": padding, "onBreach": onBreach, "onLeave": onLeave},
    children,
  );

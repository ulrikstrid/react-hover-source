type bounds = {. "top": int, "right": int, "bottom": int, "left": int};


type state = {
  isBreached: bool,
  childRef: ref(option(ReasonReact.reactRef)),
  bounds: bounds
};

type action =
  | Breach
  | Leave
  | SetBounds(bounds);

let setSectionRef = (theRef: Js.Nullable.t(ReasonReact.reactRef), {ReasonReact.state}) => {
  Js.log(theRef);
  state.childRef := Js.Nullable.toOption(theRef);
};

let component = ReasonReact.reducerComponent("ReactPerimeter");

let make = (~onBreach: unit => unit, ~onLeave: unit => unit, children) => {
  ...component,
  initialState: () => {
    isBreached: false,
    bounds: {"top": 0, "right": 0, "bottom": 0, "left": 0},
    childRef: ref(None)
  },
  didMount: self => {
    let handleMouseMove = (event, {ReasonReact.state}) => {
      let clientX = Webapi.Dom.MouseEvent.clientX(event);
      let clientY = Webapi.Dom.MouseEvent.clientY(event);
    
      let offsetY = Webapi.Dom.Window.pageYOffset(Webapi.Dom.window);
    
      if (clientX > (state.bounds##left) && clientX < (state.bounds##right) && clientY > (state.bounds##top - offsetY) && clientY < (state.bounds##bottom - offsetY)) {
        if (state.isBreached === false) {
          onBreach();
        }
      } else {
        if (state.isBreached === true) {
          onLeave();
        }
      }
    };

    switch (self.state.childRef^) {
    | Some(r) => {
      Js.log(r);
      self.send(SetBounds(ReasonReact.refToJsObj(r)##getBoundingClientRect()));
    }
    | None => ();
    };
    Webapi.Dom.Window.addMouseMoveEventListener(
      self.handle(handleMouseMove),
      Webapi.Dom.window,
    );
  },
  reducer: (action, state) =>
    switch (action) {
    | Breach => ReasonReact.Update({...state, isBreached: true})
    | Leave => ReasonReact.Update({...state, isBreached: false})
    | SetBounds(bounds) => ReasonReact.Update({...state, bounds})
    },
  render: (self) => children(self.handle(setSectionRef)),
};

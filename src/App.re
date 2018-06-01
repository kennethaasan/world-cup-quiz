[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <p className="App-intro">
        (
          ReasonReact.string(
            "Siden er under contruction, og vil vaere ferdig innen VM-start!",
          )
        )
      </p>
    </div>,
};

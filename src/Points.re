let make = (~points, _children) => {
  ...ReasonReact.statelessComponent("Points"),
  render: _self =>
    <MaterialUI.Typography
      component=(`String("span"))
      color=(
        switch (points) {
        | 0 => `Error
        | _ => `Primary
        }
      )
      style=(ReactDOMRe.Style.make(~display="inline", ()))>
      ("Poeng: " |> ReasonReact.string)
      (points |> string_of_int |> ReasonReact.string)
    </MaterialUI.Typography>,
};

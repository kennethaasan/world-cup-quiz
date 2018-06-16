let make = (~blueprint, _children) => {
  ...ReasonReact.statelessComponent("Blueprint"),
  render: _self =>
    <MaterialUI.Typography
      component=(`String("span"))
      color=`Inherit
      style=(ReactDOMRe.Style.make(~display="inline", ()))>
      ("Fasit: " |> ReasonReact.string)
      (blueprint |> ReasonReact.string)
    </MaterialUI.Typography>,
};

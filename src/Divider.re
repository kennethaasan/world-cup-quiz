let make = _children => {
  ...ReasonReact.statelessComponent("Divider"),
  render: _self =>
    <MaterialUI.Typography
      component=(`String("span"))
      color=`Inherit
      style=(ReactDOMRe.Style.make(~display="inline", ()))>
      (" | " |> ReasonReact.string)
    </MaterialUI.Typography>,
};

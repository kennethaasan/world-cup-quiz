let make = (~answer, _children) => {
  ...ReasonReact.statelessComponent("Answer"),
  render: _self =>
    <MaterialUI.Typography
      component=(`String("span"))
      color=`Inherit
      style=(ReactDOMRe.Style.make(~display="inline", ()))>
      ("Svar: " |> ReasonReact.string)
      (answer |> ReasonReact.string)
    </MaterialUI.Typography>,
};

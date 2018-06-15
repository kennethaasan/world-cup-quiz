let make = _children => {
  ...ReasonReact.statelessComponent("Nav"),
  render: _self =>
    <MaterialUI.AppBar position=`Static>
      <Router.Link route=Users>
        <MaterialUI.Toolbar>
          <MaterialUI.Typography variant=`Title color=`Inherit>
            ("VM-Konkurranse 2018" |> ReasonReact.string)
          </MaterialUI.Typography>
        </MaterialUI.Toolbar>
      </Router.Link>
    </MaterialUI.AppBar>,
};

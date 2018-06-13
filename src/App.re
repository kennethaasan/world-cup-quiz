module GetUsers = [%graphql
  {|
  query {
    users {
      id
      name
      points
      questions {
        question
        answer
        blueprint
        points
      }
    }
  }
|}
];

module GetUsersQuery = ReasonApollo.CreateQuery(GetUsers);

let renderMessage = message =>
  <MaterialUI.List>
    <MaterialUI.ListItem>
      <MaterialUI.Typography variant=`Body1 color=`Secondary>
        (message |> ReasonReact.string)
      </MaterialUI.Typography>
    </MaterialUI.ListItem>
  </MaterialUI.List>;

let make = _children => {
  ...ReasonReact.statelessComponent("App"),
  render: _self =>
    <div>
      <MaterialUI.AppBar position=`Static>
        <MaterialUI.Toolbar>
          <MaterialUI.Typography variant=`Title color=`Inherit>
            ("VM-Konkurranse 2018" |> ReasonReact.string)
          </MaterialUI.Typography>
        </MaterialUI.Toolbar>
      </MaterialUI.AppBar>
      <GetUsersQuery>
        ...(
             ({result}) =>
               <div>
                 (
                   switch (result) {
                   | NoData => renderMessage("Finner ingen brukere.")
                   | Error(e) =>
                     Js.Console.log(e);
                     renderMessage("Noe gikk galt!");
                   | Loading => renderMessage("Laster...")
                   | Data(response) =>
                     <MaterialUI.List>
                       (
                         response##users
                         |> Array.map(user =>
                              <MaterialUI.ListItem key=user##id>
                                <MaterialUI.Typography
                                  variant=`Body1 color=`Default>
                                  (user##name |> ReasonReact.string)
                                </MaterialUI.Typography>
                              </MaterialUI.ListItem>
                            )
                         |> ReasonReact.array
                       )
                     </MaterialUI.List>
                   }
                 )
               </div>
           )
      </GetUsersQuery>
    </div>,
};

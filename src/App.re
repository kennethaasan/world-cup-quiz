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

let make = _children => {
  ...ReasonReact.statelessComponent("App"),
  render: _self =>
    <div>
      <MaterialUI.AppBar position=`Static color=`Inherit>
        <MaterialUI.Toolbar>
          <MaterialUI.Typography variant=`Title color=`Inherit>
            (ReasonReact.string("VM-Konkurranse 2018"))
          </MaterialUI.Typography>
        </MaterialUI.Toolbar>
      </MaterialUI.AppBar>
      <GetUsersQuery>
        ...(
             ({result}) =>
               <div>
                 (
                   switch (result) {
                   | NoData => "Finner ingen brukere." |> ReasonReact.string
                   | Error(e) =>
                     Js.Console.log(e);
                     "Noe gikk galt!" |> ReasonReact.string;
                   | Loading => "Laster..." |> ReasonReact.string
                   | Data(response) =>
                     <MaterialUI.List>
                       (
                         response##users
                         |> Array.map(user =>
                              <MaterialUI.ListItem key=user##id>
                                (user##name |> ReasonReact.string)
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

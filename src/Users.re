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
  ...ReasonReact.statelessComponent("Users"),
  render: _self =>
    <GetUsersQuery>
      ...(
           ({result}) =>
             switch (result) {
             | NoData => renderMessage("Finner ingen brukere.")
             | Error(e) =>
               Js.Console.log(e);
               renderMessage("Noe gikk galt!");
             | Loading => renderMessage("Laster...")
             | Data(response) =>
               <MaterialUI.Table>
                 <MaterialUI.TableBody>
                   (
                     response##users
                     |> Array.map(user =>
                          <MaterialUI.TableRow key=user##id>
                            <MaterialUI.TableCell>
                              <MaterialUI.Typography
                                variant=`Body1 color=`Default>
                                (user##name |> ReasonReact.string)
                              </MaterialUI.Typography>
                            </MaterialUI.TableCell>
                            <MaterialUI.TableCell>
                              <MaterialUI.Typography
                                variant=`Body1 color=`Primary>
                                (
                                  user##points
                                  |> string_of_int
                                  |> ReasonReact.string
                                )
                              </MaterialUI.Typography>
                            </MaterialUI.TableCell>
                          </MaterialUI.TableRow>
                        )
                     |> ReasonReact.array
                   )
                 </MaterialUI.TableBody>
               </MaterialUI.Table>
             }
         )
    </GetUsersQuery>,
};

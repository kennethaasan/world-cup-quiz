module GetUser = [%graphql
  {|
  query getUser($user_id: ID!) {
    user(user_id: $user_id) {
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

module GetUserQuery = ReasonApollo.CreateQuery(GetUser);

let make = (~user_id, _children) => {
  ...ReasonReact.statelessComponent("User"),
  render: _self => {
    let getUserQuery = GetUser.make(~user_id, ());
    <GetUserQuery variables=getUserQuery##variables>
      ...(
           ({result}) =>
             switch (result) {
             | NoData => Users.renderMessage("Finner ikke brukeren.")
             | Error(e) =>
               Js.Console.log(e);
               Users.renderMessage("Noe gikk galt!");
             | Loading => Users.renderMessage("Laster...")
             | Data(response) =>
               switch (response##user) {
               | None => Users.renderMessage("Finner ikke brukeren.")
               | Some(user) =>
                 <MaterialUI.List>
                   <MaterialUI.ListItem>
                     <MaterialUI.Typography variant=`Title color=`Primary>
                       (user##name |> ReasonReact.string)
                     </MaterialUI.Typography>
                   </MaterialUI.ListItem>
                   (
                     user##questions
                     |> Array.map(question =>
                          <MaterialUI.ListItem key=question##question>
                            <MaterialUI.ListItemText
                              primary=(
                                question##question |> ReasonReact.string
                              )
                              secondary=(
                                question##answer |> ReasonReact.string
                              )
                            />
                          </MaterialUI.ListItem>
                        )
                     |> ReasonReact.array
                   )
                 </MaterialUI.List>
               }
             }
         )
    </GetUserQuery>;
  },
};

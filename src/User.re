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

let make = _children => {
  ...ReasonReact.statelessComponent("User"),
  render: _self => {
    let getUserQuery = GetUser.make(~user_id="1", ());
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
               | Some(user) => user##name |> ReasonReact.string
               }
             }
         )
    </GetUserQuery>;
  },
};

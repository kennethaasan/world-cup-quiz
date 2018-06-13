[%bs.raw {|require('./App.css')|}];

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
    <GetUsersQuery>
      ...(
        ({result}) =>
          <div>
            <h1>
              ("Velkommen til VM-Konkurranse 2018" |> ReasonReact.string)
            </h1>
            (
              switch (result) {
              | NoData => "Finner ingen brukere." |> ReasonReact.string
              | Error(e) =>
                Js.Console.log(e);
                "Noe gikk galt!" |> ReasonReact.string;
              | Loading => "Laster..." |> ReasonReact.string
              | Data(response) =>
                response##users
                |> Array.map((user) =>
                  <div key=user##id>(user##name |> ReasonReact.string)</div>)
                |> ReasonReact.array
              }
            )
          </div>
        )
    </GetUsersQuery>,
};

type routes =
  | Users
  | User(string)
  | NotFound;

let routeToString =
  fun
  | Users => "/"
  | User(user_id) => "/user/" ++ user_id
  | NotFound => "/404";

let urlToRoute: ReasonReact.Router.url => routes =
  url =>
    switch (url.path) {
    | [] => Users
    | ["user", user_id] => User(user_id)
    | _ => NotFound
    };

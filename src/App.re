let make = _children => {
  ...ReasonReact.statelessComponent("App"),
  render: _self =>
    <div>
      <Nav />
      <Router.WithRouter>
        ...(
             (~currentRoute) =>
               switch (currentRoute) {
               | Users => <Users />
               | User(user_id) => <User user_id />
               | _ => <NotFound />
               }
           )
      </Router.WithRouter>
    </div>,
};

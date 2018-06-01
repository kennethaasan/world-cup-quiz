[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <App message="Velkommen til VM-Konkurranse 2018" />,
  "root",
);

register_service_worker();
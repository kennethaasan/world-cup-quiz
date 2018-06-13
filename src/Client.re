let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink =
  ApolloLinks.createHttpLink(~uri="https://graphql.vm.kennethaasan.no", ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

const FISHNET_URL =
  "https://misc.fn.sportradar.com/sportradar/no/Etc:UTC/gismo";
const WORLD_CUP_SEASON_ID = 48238;
const WORLD_CUP_TOURNAMENT_ID = 3948;

const fetch = require("node-fetch");

async function getFeed(url) {
  const response = await fetch(url);

  if (!response.ok) {
    throw new Error(
      `Fishnet request ${url} failed with status: ${
        response.status
      } with this status text: ${response.statusText}`
    );
  }

  const json = await response.json();

  if (!json || !json.doc || !json.doc[0] || !json.doc[0].data) {
    throw new Error(
      `Fishnet feed ${url} responds with: ${JSON.stringify(json)}`
    );
  }

  return json.doc[0].data;
}

async function getGroupStageFixtures() {
  const fixtures = await getFeed(
    `${FISHNET_URL}/stats_season_fixtures2/${WORLD_CUP_SEASON_ID}`
  );

  const matchesById = fixtures.matches.reduce((m, match) => {
    m[match._id] = match;
    return m;
  }, {});

  const groupStage = Object.keys(fixtures.tables).map(tableId => {
    return {
      ...fixtures.tables[tableId],
      matches: fixtures.tables[tableId].matches.map(matchId => {
        return matchesById[matchId];
      })
    };
  });

  return groupStage;
}

async function getTeams() {
  const teams = await getFeed(
    `${FISHNET_URL}/stats_season_teams2/${WORLD_CUP_SEASON_ID}`
  );

  return teams.teams;
}

async function getOddsOutrights() {
  const oddsOutrights = await getFeed(`${FISHNET_URL}/odds_outrights/4`);

  const tournamentOddsOutrights = oddsOutrights.outrights.filter(
    outright => outright.tournamentid === WORLD_CUP_TOURNAMENT_ID
  );

  return tournamentOddsOutrights;
}

module.exports = {
  getGroupStageFixtures,
  getTeams,
  getOddsOutrights
};

const { getTeams } = require("./fishnet");

async function getAlternativesTeams(groupStage) {
  const teams = await getTeams();

  return teams.filter(team => team.iscountry === true).map(team => {
    return {
      alternative: team.name
    };
  });
}

module.exports = {
  getAlternativesTeams
};

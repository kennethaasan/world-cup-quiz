const { getGroupStageFixtures } = require("./fishnet");

async function getQuestionsGroupStage() {
  const groupStageFixtures = await getGroupStageFixtures();

  return groupStageFixtures.map(group => {
    return {
      name: group.name,
      matches: group.matches.map(match => {
        return {
          question: `${match.teams.home.name} - ${match.teams.away.name}`
        };
      })
    };
  });
}

module.exports = {
  getQuestionsGroupStage
};

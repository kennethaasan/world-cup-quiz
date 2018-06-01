const { getOddsOutrights } = require("./fishnet");

async function getQuestionsTournament() {
  const oddsOutrights = await getOddsOutrights();

  return oddsOutrights.map(outright => {
    return {
      question: outright.name,
      alternatives: Object.keys(outright.competitors).map(competitorId => {
        const competior = outright.competitors[competitorId];
        return competior.name;
      })
    };
  });
}

module.exports = {
  getQuestionsTournament
};

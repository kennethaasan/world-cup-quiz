const { getQuestionsGroupStage } = require("./questions-group-stage");
const { getQuestionsTournament } = require("./questions-tournament");
const { getAlternativesTeams } = require("./alternatives-teams");
const fs = require("fs");

async function googleForms() {
  const [
    questionsGroupStage,
    questionsTournament,
    alternativesTeams
  ] = await Promise.all([
    getQuestionsGroupStage(),
    getQuestionsTournament(),
    getAlternativesTeams()
  ]);

  fs.writeFileSync(
    "questions.json",
    JSON.stringify({
      questions_group_stage: questionsGroupStage,
      questions_tournament: questionsTournament,
      alternatives_teams: alternativesTeams
    })
  );
}

googleForms();

process.on("unhandledRejection", reason => {
  throw reason;
});

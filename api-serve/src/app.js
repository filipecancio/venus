const express = require("express");
const cors = require("cors");

const app = express();

app.use(express.json());
app.use(cors());

const repo = {
    title:"Eugenio Challenge Hub",
    hackathin_logo_url: "https://www.eugeniochallengehub.io/wp-content/themes/challengehub/img/logo.png",
    eugenio_logo_url: "https://www.eugeniochallengehub.io/wp-content/themes/challengehub/img/eugenio.gif",
    repo_url:"https://github.com/filipecancio/eugenio-challenge"
};

app.get("/", (request, response) => {
  return response.json(repositories);
});

module.exports = app;
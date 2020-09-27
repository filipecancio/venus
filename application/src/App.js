import React from 'react';
import './App.css';

const repo = {
  title:"Eugenio Challenge Hub",
  hackathin_logo_url: "https://www.eugeniochallengehub.io/wp-content/themes/challengehub/img/logo.png",
  eugenio_logo_url: "https://www.eugeniochallengehub.io/wp-content/themes/challengehub/img/eugenio.gif",
  repo_url:"https://github.com/filipecancio/eugenio-challenge"
};

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={repo.eugenio_logo_url} className="App-logo" alt="logo" />
        <p>
          A aplicação está em desenvolvimento.
        </p>
        <a
          className="App-link"
          href={repo.repo_url}
          target="_blank"
          rel="noopener noreferrer"
        >
          repositório
        </a>
      </header>
    </div>
  );
}

export default App;

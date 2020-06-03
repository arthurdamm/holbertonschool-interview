#!/usr/bin/node

const request = require('request');
const filmUrl = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(filmUrl, (error, response, body) => {
  if (error) {
    return;
  }
  const film = JSON.parse(body);
  const urlToName = {};
  film.characters.forEach(characterUrl => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        return;
      }
      const character = JSON.parse(body);
      urlToName[character.url] = character.name;
      if (Object.keys(urlToName).length === film.characters.length) {
        film.characters.forEach(characterUrl =>
          console.log(urlToName[characterUrl]));
      }
    });
  });
});

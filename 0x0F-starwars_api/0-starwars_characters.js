#!/usr/bin/node

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(url, function (error, response, body) {
  if (error) {
    return;
  }
  const json = JSON.parse(body);
  const urlToName = {};
  for (const characterUrl of json.characters) {
    request(characterUrl, function (error, response, body) {
      if (error) {
        return;
      }
      const character = JSON.parse(body);
      urlToName[character.url] = character.name;
      if (Object.keys(urlToName).length === json.characters.length) {
        for (const characterUrl of json.characters) {
          console.log(urlToName[characterUrl]);
        }
      }
    });
  }
});

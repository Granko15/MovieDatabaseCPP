#pragma once

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

#include "film.h"
#include "viewer.h"

class FilmDatabase{
    std::map<std::string , Film> filmMap;

public:

    FilmDatabase();

    void printOutFilms();
    bool readFilmsFromFile(const std::string &filename);

    std::map<std::string , Film> &getFilmMap(){return filmMap;};

    Film* getFilm(const std::string filmTitle);
    std::vector<Film*> getFilmsOfEra(int favYear);
    std::vector<Film*> getFilmsOfCategory(std::string favCategory);
};
#include <iostream>
#include <sstream>
#include <fstream>
#include "filmDatabase.h"

FilmDatabase::FilmDatabase() {
    readFilmsFromFile("movies.txt");
}

bool FilmDatabase::readFilmsFromFile(const std::string &filename) {                                       ////ok
    std::ifstream inFile;
    inFile.open(filename);

    if(inFile.fail()){
        return false;
    }

    char separator = '|';
    std::string filmLine = "";
    while (getline(inFile,filmLine)){

        double filmRating = std::stod(filmLine.substr(0,filmLine.find(separator)));          ////read rating
        filmLine.erase(0,filmLine.find(separator)+1);

        std::string filmTitle = filmLine.substr(0,filmLine.find(separator));                    ////read title
        filmLine.erase(0,filmLine.find(separator)+1);

        int filmYear = std::stoi(filmLine.substr(1,filmLine.find(separator)-1));            ////read year
        filmLine.erase(0,filmLine.find(separator)+1);

        Film newFilm(filmTitle, filmRating, filmYear);

        std::string filmCategories = filmLine.substr(0,filmLine.length()-1);

        std::string newCategory = "";

        for(auto character : filmCategories){                                                     ////read categories
            if(character == '+'){
                newFilm.addCategory(newCategory);
                newCategory = "";
                continue;
            }
            newCategory += character;
        }

        filmMap.insert({newFilm.getTitle(),newFilm});                                           ////add film to db
    }
    return true;
}

void FilmDatabase::printOutFilms(){                                                     ////kontrolny vypis databazy
    for(auto iter = filmMap.begin(); iter != filmMap.end(); iter++){
        std::cout << iter->second.getRating() << " | " << iter->second.getTitle() << " | "
                  << iter->second.getYear() << " | " << iter->second.getCategories() << std::endl;
    }
}

Film* FilmDatabase::getFilm(const std::string filmTitle){                                          ////get film from db
    if(filmMap.empty()){
        return nullptr;
    }
    for(auto iter = filmMap.begin(); iter != filmMap.end(); ++iter){
        if(iter->second.getTitle() == filmTitle){
            return &iter->second;
        }
    }
    return nullptr;
}

std::vector<Film*> FilmDatabase::getFilmsOfEra(int favYear) {
    std::vector<Film*> favoriteFilmsOfEra;
    int era = favYear - (favYear % 10);                                                    ////zaokruhlit rok nadol
    for(auto &film : filmMap){
        if(era <= film.second.getYear() && era + 9 >= film.second.getYear() ){
            favoriteFilmsOfEra.push_back(&film.second);
        }
    }
    return favoriteFilmsOfEra;
}

std::vector<Film*> FilmDatabase::getFilmsOfCategory(std::string favCategory) {
    std::vector<Film*> favoriteCatFilms;
    for(auto &film : filmMap){
        if(film.second.getCategory(favCategory) != ""){
            favoriteCatFilms.push_back(&film.second);
        }
    }
    return favoriteCatFilms;
}
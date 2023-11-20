#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>

#include "film.h"

Film::Film() {
    setDefaultCategories("categories.txt");
}

Film::Film(std::string title, double rating, int year):
    Title(std::move(title)),
    Rating(rating),
    Year(year){
    setDefaultCategories("categories.txt");
};

void Film::setDefaultCategories(const std::string &filename) {
    std::ifstream inFile;
    inFile.open(filename);

    if(inFile.fail()){
        return;
    }

    std::string catLine = "";
    while (getline(inFile,catLine)){
        catLine.erase(catLine.size() - 1);          ////remove "\r"
        filmCatMap.insert({catLine, false});
    }
}

std::string Film::putTitle(std::string movieTitle) {    ////OK
    if (movieTitle.empty()){
        return DUMMY_STRING;
    }
    setTitle(movieTitle);
    return getTitle();
}

int Film::putYear(int movieYear) {                      ////OK
    if(movieYear < firstFilmYear || movieYear > currentYear){
        return -1;
    }
    setYear(movieYear);
    return getYear();
}

double Film::putRating(double movieRating) {            ////OK
    if (movieRating < 0.0 || movieRating > 10.0){
        return -0.1;
    }
    setRating(movieRating);
    return getRating();
}

bool Film::addCategory(std::string movieCategory) {      ////OK
    for (auto& currCategory : filmCatMap){
        if (currCategory.first == movieCategory && !currCategory.second){
            currCategory.second = true;
            return true;
        }
    }
    return false;
}

std::string Film::getCategory(const std::string categoryName) {       ////OK
    if(filmCatMap.empty()){
        return DUMMY_STRING;
    }
    for(auto iter = filmCatMap.begin(); iter != filmCatMap.end(); iter++){
        if(iter->first == categoryName && iter->second){
            return iter->first;
        }
    }
    return DUMMY_STRING;
}

std::string Film::getCategories() {                     ////OK

    if (filmCatMap.empty()){
        return DUMMY_STRING;
    }

    std::string categoryList = "";
    for (const auto& category : filmCatMap){
        if(category.second) {
            if (categoryList.empty()) {
                categoryList += category.first;
            } else {
                categoryList += ',' + category.first;
            }
        }
    }
    return categoryList;
}
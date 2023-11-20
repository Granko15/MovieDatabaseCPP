#pragma once

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "film.h"
///class Viewer
class Viewer{
    std::string Nickname = "";
    std::vector<std::string> favoriteMovies;
    int favoriteEra = 0;

public:

    Viewer(){};
    Viewer(std::string Nickname,std::vector<std::string> favoriteMovies,int favoriteEra);
    void setDefaultCategories(const std::string &filename);

    void setNickname(std::string viewerNick){Nickname = std::move(viewerNick);};
    void addFavMovie(const std::string& favMovie){favoriteMovies.push_back(favMovie);};

    std::string putNickname(const std::string viewerNick);
    bool addFavCategory(const std::string favCategory);
    std::string putFavMovie(const std::string favMovie);
    int putFavEra(int favEra);

    std::string getNickname(){return Nickname;};
    std::string getFavCategory(const std::string categoryName);
    std::string getFavCategories();
    std::string getFavMovies();
    int getFavEra(){ return favoriteEra; };
};
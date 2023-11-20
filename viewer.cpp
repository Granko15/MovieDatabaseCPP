#include <iostream>
#include <sstream>
#include <fstream>

#include "viewer.h"

Viewer::Viewer(std::string Nickname,std::vector<std::string> favoriteMovies,int favoriteEra):
    Nickname(Nickname),
    favoriteMovies(std::move(favoriteMovies)),
    favoriteEra(favoriteEra){};

std::string Viewer::putNickname(const std::string viewerNick){    ////OK
    if (viewerNick.empty()){
        return DUMMY_STRING;
    }
    for (auto ch : viewerNick) {
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            continue;
        } else {
            return DUMMY_STRING;
        }
    }
    setNickname(viewerNick);
    return getNickname();
};

std::string Viewer::putFavMovie(const std::string favMovie){          ////OK
    Film FavMovie;
    if (FavMovie.putTitle(favMovie).empty()){
        return DUMMY_STRING;
    }
    addFavMovie(favMovie);
    return favMovie;
};

int Viewer::putFavEra(int favEra){                              ////OK
    Film FavYear;
    if (FavYear.putYear(favEra) == -1){
        return -1;
    }
    favoriteEra = favEra;
    return favEra;
};

std::string Viewer::getFavMovies(){                             ////OK
    if (favoriteMovies.empty()){
        return DUMMY_STRING;
    }
    std::string favMovieList = "";
    for (auto movie : favoriteMovies){
        if (favMovieList.empty()){
            favMovieList += movie;
        }else{
            favMovieList += '|' + movie;
        }
    }
    return favMovieList;
};

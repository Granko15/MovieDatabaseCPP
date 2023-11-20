
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "filmDatabase.h"
#include "film.h"
#include "viewer.h"


class Watchlist{
    std::vector<Film*> myWatchlist;
    FilmDatabase database;
    Viewer viewer;

public:

    Watchlist(Viewer viewer);

    std::vector<Film*> getWatchlist(){ return myWatchlist; };

    void printOutDatabase();
    void printRecommendations();
    void addFilmToWatchlist(Film *film);
    void addFilmWithCat(std::string category);
    void addFilmOfEra(int era);

    Film* getFilmFromList(const std::string filmTitle);
    FilmDatabase* getDatabase(){return &database;};

    void markAsSeen(std::string filmTitle);

    std::string viewerName(){ return viewer.getNickname(); };
};

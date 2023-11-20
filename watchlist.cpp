#include <iostream>
#include <sstream>

#include "watchlist.h"

Watchlist::Watchlist(Viewer viewer) :
        viewer(std::move(viewer)){};

void Watchlist::printOutDatabase() {
    for(auto &film : database.getFilmMap()){
        std::string seen = "Not Seen";
        if(film.second.getSeen()){
            seen = "Watched";
        }
        std::cout << film.second.getTitle() << " | " << film.second.getYear() << " | IMDB Rating : "
                  << film.second.getRating() << " | " << film.second.getCategories() << " | " << seen << std::endl;
    }
}

void Watchlist::printRecommendations() {
    if(myWatchlist.empty()){
        std::cout << "Watchlist is empty!" <<std::endl;
        return;
    }
    std::cout << viewerName() <<" watchlist:"<<std::endl;
    int index = 1;
    for(auto &film : myWatchlist){
        std::string seen = "Not Seen";
        if(film->getSeen()){
            seen = "Watched";
        }
        std::cout << index << ". " << film->getTitle() << " | " << film->getYear() << " | IMDB Rating : "
        << film->getRating() << " | " << film->getCategories() << " | " << seen << std::endl;
        index++;
    }
}

void Watchlist::addFilmToWatchlist(Film *film) {
    if(film->getSeen()){
        return;
    }
    myWatchlist.push_back(film);
}

Film* Watchlist::getFilmFromList(const std::string filmTitle) {
    for(auto &film : myWatchlist){
        if(film->getTitle() == filmTitle){
            return film;
        }
    }
    return nullptr;
}

void Watchlist::addFilmWithCat(std::string category) {
    myWatchlist = database.getFilmsOfCategory(category);
}

void Watchlist::addFilmOfEra(int era) {
    myWatchlist = database.getFilmsOfEra(era);
}

void Watchlist::markAsSeen(std::string filmTitle) {
    for(auto &film : myWatchlist){
        if(film->getTitle() == filmTitle){
            film->setAsSeen();
        }
    }
}
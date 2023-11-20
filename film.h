#pragma once

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>


///film class
const int firstFilmYear = 1888;                    /// the first surviving film year
const int currentYear = 2022;                      /// current year

const double DUMMY_DOUBLE = 0.0;
const int DUMMY_INT = 0;
const std::string DUMMY_STRING = "";

class Film{
    std::string Title = "";
    double Rating = 0.0;
    int Year = 0;
    bool Seen = false;
    std::map<std::string,bool> filmCatMap;

public:

    Film();
    Film(std::string title, double rating, int year);
    void setDefaultCategories(const std::string &filename);


    void setTitle(std::string movieTitle){Title = std::move(movieTitle);};
    void setYear(int movieYear){Year = movieYear;};
    void setRating(double movieRating){Rating = movieRating;};
    void setAsSeen(){Seen = true; } ;

    std::string putTitle(std::string movieTitle);
    int putYear(int movieYear);
    double putRating(double movieRating);
    bool addCategory(std::string movieCategory);

    std::string getTitle(){return Title;};
    bool getSeen(){return Seen;};
    int getYear(){return Year;};
    double getRating(){return Rating;};
    std::string getCategory(const std::string categoryName);
    std::string getCategories();
    std::map<std::string,bool> &getFilmCatMap() { return filmCatMap; }
};



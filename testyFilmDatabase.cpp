#include <iostream>
#include "gtest/gtest.h"

#include "filmDatabase.h"

using namespace ::testing;

TEST(TestDatabase, readFromFile) {
    FilmDatabase database;
    ASSERT_EQ(false,database.getFilmMap().empty());
    ASSERT_EQ(true, database.readFilmsFromFile("movies.txt"));
}

TEST(TestDatabase, filmNotInDatabase){
    FilmDatabase database;
    ASSERT_EQ("Pulp Fiction",database.getFilm("Pulp Fiction")->getTitle());
    ASSERT_EQ(nullptr,database.getFilm("JoJo Rabbit"));
}

TEST(TestDatabase, filmsFrom90s){
    FilmDatabase database;
    ASSERT_EQ("American Beauty",database.getFilmsOfEra(1998)[0]->getTitle());
}

TEST(TestDatabase, fantasyFilms){
    FilmDatabase database;
    ASSERT_EQ("Avatar",database.getFilmsOfCategory("Fantasy")[0]->getTitle());
}
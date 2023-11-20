#include <iostream>
#include "gtest/gtest.h"

#include "film.h"

using namespace ::testing;

TEST(TestFilm, EmptyTitle) {
    Film film;
    ASSERT_EQ("",film.putTitle(""));
}

TEST(TestFilm, CorrectTitle) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
}

TEST(TestFilm, NumberInTitle) {
    Film film;
    ASSERT_EQ("12 Angry Men",film.putTitle("12 Angry Men"));
}

TEST(TestFilm, DashInTitle) {
    Film film;
    ASSERT_EQ("WALL-E",film.putTitle("WALL-E"));
}

TEST(TestFilm, ApostropheInTitle) {
    Film film;
    ASSERT_EQ("Schindler's List",film.putTitle("Schindler's List"));
}

TEST(TestFilm, SpecialLetterInTitle) {
    Film film;
    ASSERT_EQ("Léon",film.putTitle("Léon"));
}

TEST(TestFilm, SpecialCharInTitle) {
    Film film;
    ASSERT_EQ("8½",film.putTitle("8½"));
}

TEST(TestFilm, WrongYear) {
    Film film;
    ASSERT_EQ("John Wick: Chapter 4",film.putTitle("John Wick: Chapter 4"));
    ASSERT_EQ(-1,film.putYear(2023));
}

TEST(TestFilm, CorrectYear) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ(2003,film.putYear(2003));
}


TEST(TestFilm, WrongRating) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ(2003,film.putYear(2003));
    ASSERT_EQ(-0.1,film.putRating(12));
}

TEST(TestFilm, CorrectRating) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ(2003,film.putYear(2003));
    ASSERT_EQ(8.8,film.putRating(8.8));
}

TEST(TestFilm, DuplicateCategory) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ(2003,film.putYear(2003));
    ASSERT_EQ(8.8,film.putRating(8.8));
    film.addCategory("Fantasy");
    film.addCategory("Mystery");
    ASSERT_EQ(false,film.addCategory("Fantasy"));
}

TEST(TestFilm, AddNewCategory) {
    Film film;
    ASSERT_EQ("The Lord of the Rings: The Return of the King",film.putTitle("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ(2003,film.putYear(2003));
    ASSERT_EQ(8.8,film.putRating(8.8));
    film.addCategory("Fantasy");
    ASSERT_EQ(true,film.addCategory("Mystery"));
}

TEST(TestFilm, EmptyCategoryList) {
    Film film;
    film.putTitle("The Lord of the Rings: The Return of the King");
    film.putYear(2003);
    film.putRating(8.8);
    ASSERT_EQ("",film.getCategories());
}

TEST(TestFilm, OneCategoryInList) {
    Film film;
    film.putTitle("The Lord of the Rings: The Return of the King");
    film.putYear(2003);
    film.putRating(8.8);
    film.addCategory("Fantasy");
    ASSERT_EQ("Fantasy",film.getCategories());
}

TEST(TestFilm, ListOfCategories) {
    Film film;
    film.putTitle("The Lord of the Rings: The Return of the King");
    film.putYear(2003);
    film.putRating(8.8);
    film.addCategory("Fantasy");
    film.addCategory("Mystery");
    ASSERT_EQ("Fantasy",film.getCategory("Fantasy"));
    ASSERT_EQ("",film.getCategory("Crime"));
    ASSERT_EQ("Fantasy,Mystery",film.getCategories());
}
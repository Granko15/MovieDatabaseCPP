#include <iostream>
#include "gtest/gtest.h"

#include "viewer.h"

using namespace ::testing;

TEST(TestViewer, EmptyNickname) {
    Viewer viewer;
    ASSERT_EQ("",viewer.putNickname(""));
}

TEST(TestViewer, WrongCharInNickname) {
    Viewer viewer;
    ASSERT_EQ("",viewer.putNickname("_Gwynbleidd_"));
}

TEST(TestViewer, CorrectNickname) {
    Viewer viewer;
    ASSERT_EQ("Granko15", viewer.putNickname("Granko15"));
}

TEST(TestViewer, WrongYearOfEra) {
    Viewer viewer;
    viewer.putNickname("Gwynbleidd");
    Film FavYear;
    ASSERT_EQ(1980,viewer.putFavEra(1980));
    ASSERT_EQ(-1,viewer.putFavEra(1800));
}

TEST(TestViewer, GetFavEra) {
    Viewer viewer;
    viewer.putNickname("Gwynbleidd");
    viewer.putFavEra(1992);
    ASSERT_EQ(1992,viewer.getFavEra());
}

TEST(TestViewer, WrongTitleOfFavMovie){
    Viewer viewer;
    viewer.putNickname("Gwynbleidd");
    ASSERT_EQ("WALL·E",viewer.putFavMovie("WALL·E"));
}

TEST(TestViewer, ListOfFavMovies){
    Viewer viewer;
    viewer.putNickname("Gwynbleidd");
    ASSERT_EQ("The Lord of the Rings: The Return of the King",viewer.putFavMovie("The Lord of the Rings: The Return of the King"));
    ASSERT_EQ("Inception",viewer.putFavMovie("Inception"));
    ASSERT_EQ("Pulp Fiction",viewer.putFavMovie("Pulp Fiction"));
    ASSERT_EQ("The Good, the Bad and the Ugly",viewer.putFavMovie("The Good, the Bad and the Ugly"));
    std::string FavList = "The Lord of the Rings: The Return of the King|Inception|Pulp Fiction|The Good, the Bad and the Ugly";
    ASSERT_EQ(FavList,viewer.getFavMovies());
}



#include <iostream>
#include "gtest/gtest.h"

#include "watchlist.h"

using namespace ::testing;

TEST(TestWatchlist, constructorTest){
    Viewer Granko;
    Granko.setNickname("Granko");
    Watchlist grankoWatchlist(Granko);
    grankoWatchlist.printRecommendations();
    std::cout<<std::endl;
    ASSERT_EQ("Granko",grankoWatchlist.viewerName());
}

TEST(TestWatchlist, oneFilmInWatchlist){
    Viewer Granko;
    Granko.setNickname("Granko");
    Watchlist grankoWatchlist(Granko);
    Film newFilm("Pulp Fiction",8.9,1994);
    newFilm.addCategory("Crime");
    newFilm.addCategory("Drama");
    grankoWatchlist.addFilmToWatchlist(&newFilm);
    grankoWatchlist.printRecommendations();
    std::cout<<std::endl;
    ASSERT_EQ("Pulp Fiction",grankoWatchlist.getFilmFromList("Pulp Fiction")->getTitle());
}

TEST(TestWatchlist, getFilmFromList){
    Viewer Granko;
    Granko.setNickname("Granko");
    Watchlist grankoWatchlist(Granko);
    Film newFilm("Pulp Fiction",8.9,1994);
    newFilm.addCategory("Crime");
    newFilm.addCategory("Drama");
    grankoWatchlist.addFilmToWatchlist(&newFilm);
    std::cout<<std::endl;
    ASSERT_EQ("Pulp Fiction",grankoWatchlist.getFilmFromList("Pulp Fiction")->getTitle());
}


TEST(TestWatchlist, categoryTest){
    Viewer Granko;
    Granko.setNickname("Granko");
    Watchlist grankoWatchlist(Granko);
    grankoWatchlist.addFilmWithCat("Fantasy");
    std::cout<<"Fantasy films:"<<std::endl;
    grankoWatchlist.printRecommendations();
    std::cout<<std::endl;
    ASSERT_EQ("Fantasy",grankoWatchlist.getFilmFromList("Avatar")->getCategory("Fantasy"));
}

TEST(TestWatchlist, eraTest){
    Viewer Granko;
    Granko.setNickname("Granko");
    Granko.putFavEra(1975);
    Watchlist grankoWatchlist(Granko);
    grankoWatchlist.addFilmOfEra(Granko.getFavEra());
    std::cout<<"Films from 1970-1979:"<<std::endl;
    grankoWatchlist.printRecommendations();
    std::cout<<std::endl;
    ASSERT_EQ("A Clockwork Orange",grankoWatchlist.getFilmFromList("A Clockwork Orange")->getTitle());
}

TEST(TestWatchlist, watchedFilmsTest) {
    Viewer Granko;
    Granko.setNickname("Granko");
    Watchlist grankoWatchlist(Granko);
    grankoWatchlist.addFilmWithCat("Fantasy");
    std::cout << "Watched/Unseen:" << std::endl;
    grankoWatchlist.markAsSeen("Monty Python and the Holy Grail");
    grankoWatchlist.markAsSeen("The Lord of the Rings: The Fellowship of the Ring");
    grankoWatchlist.printRecommendations();
    ASSERT_EQ(true,grankoWatchlist.getFilmFromList("Monty Python and the Holy Grail")->getSeen());
    ASSERT_EQ(true, grankoWatchlist.getDatabase()->getFilm("Monty Python and the Holy Grail")->getSeen());
    ASSERT_EQ(true,grankoWatchlist.getFilmFromList("The Lord of the Rings: The Fellowship of the Ring")->getSeen());
    ASSERT_EQ(true, grankoWatchlist.getDatabase()->getFilm("The Lord of the Rings: The Fellowship of the Ring")->getSeen());
}
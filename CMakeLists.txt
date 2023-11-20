cmake_minimum_required(VERSION 3.20)
project(semestralny)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        film.cpp
        viewer.cpp
        filmDatabase.cpp
        watchlist.cpp

        testyFilm.cpp
        testyViewer.cpp
        testyFilmDatabase.cpp
        testyWatchlist.cpp

        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)


include_directories(GoogleTest)
add_executable(semestralny ${SOURCE_FILES})
add_custom_command(TARGET semestralny PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/movies.txt
        ${CMAKE_SOURCE_DIR}/categories.txt
        $<TARGET_FILE_DIR:semestralny>
        VERBATIM)
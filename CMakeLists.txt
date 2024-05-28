cmake_minimum_required(VERSION 3.26)
project(projet_C___5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projet_C___5
        board.cpp
        board.h
        Bonus.cpp
        Bonus.h
        GameManager.cpp
        GameManager.h
        GameUi.cpp
        GameUi.h
        main.cpp
        Tile.cpp
        Tile.h
        player.h
        player.cpp
        Run.cpp
        Run.h
)

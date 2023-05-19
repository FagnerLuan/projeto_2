cmake_minimum_required(VERSION 3.0)
project(playlist_manager VERSION 1.0 LANGUAGES CXX)
include_directories(include)
add_executable(simple_song_player
               src/main.cpp
               src/musica.cpp
               src/playlist.cpp
               src/driver.cpp)
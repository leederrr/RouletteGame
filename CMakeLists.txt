cmake_minimum_required(VERSION 3.24)
project(RouletteGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(RouletteGame main.cpp Roulette.h Roulette.cpp game_stats.py color_stats.R)

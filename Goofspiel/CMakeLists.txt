cmake_minimum_required(VERSION 3.22)
project(Goofspiel)

set(CMAKE_CXX_STANDARD 14)

add_executable(Goofspiel main.cpp Player.cpp Player.h ManualPlayer.cpp ManualPlayer.h ComputerPlayer.cpp ComputerPlayer.h Prizes.cpp Prizes.h Game.cpp Game.h)

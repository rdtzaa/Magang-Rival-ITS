cmake_minimum_required(VERSION 3.0)

project( oprec )

find_package( OpenCV REQUIRED )

add_executable( Rival_1 src/game.cpp src/tangkap_permen.cpp )

target_link_libraries( Rival_1 ${OpenCV_LIBS} )

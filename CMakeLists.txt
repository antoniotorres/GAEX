cmake_minimum_required(VERSION 2.8)
project( GAEX )
find_package( OpenCV REQUIRED )
add_executable( GAEX gaex.cpp )
target_link_libraries( GAEX ${OpenCV_LIBS} )

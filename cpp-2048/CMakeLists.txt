# CMakeList.txt : CMake project for cpp-2048, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (cpp-2048 "src/main.cpp" "cpp-2048.h" "modules/Game.ixx" "modules/Game.Board.ixx"  "modules/Game.Board.Cell.ixx" "src/Game.Board.Cell.cpp" "src/Game.Board.cpp" "src/Game.cpp" "modules/Helper.ixx" "src/Helper.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cpp-2048 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 3.19.3)

# Require C++17
set(CMAKE_CXX_STANDARD 17)

project(PaperScissorsRockGame VERSION 0.1.0
        DESCRIPTION "Paper-Scissors-Rock IMC assignment 1"
        LANGUAGES CXX)

set(SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/ComputerPlayer.cpp" 
                 "${PROJECT_SOURCE_DIR}/src/Game.cpp" 
                 "${PROJECT_SOURCE_DIR}/src/HumanPlayer.cpp" 
                 "${PROJECT_SOURCE_DIR}/src/PlayersFactory.cpp" 
                 "${PROJECT_SOURCE_DIR}/src/Rules.cpp" 
                 "${PROJECT_SOURCE_DIR}/src/RulesFactory.cpp")

set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/ComputerPlayer.hpp"
                "${PROJECT_SOURCE_DIR}/include/Game.hpp"
                "${PROJECT_SOURCE_DIR}/include/Hands.hpp"
                "${PROJECT_SOURCE_DIR}/include/HumanPlayer.hpp"
                "${PROJECT_SOURCE_DIR}/include/Player.hpp"
                "${PROJECT_SOURCE_DIR}/include/PlayersFactory.hpp"
                "${PROJECT_SOURCE_DIR}/include/Rules.hpp"
                "${PROJECT_SOURCE_DIR}/include/RulesFactory.hpp")

# Create the library
set(library_name PaperScissorsRockGame)
add_library(${library_name} ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(${library_name} PRIVATE include)

# Create the executable
set(executable_name PaperScissorsRockGameExecutable)
add_executable(${executable_name} "${PROJECT_SOURCE_DIR}/src/main.cpp" )

# Add a dependency to ensure the correct build order
add_dependencies(${executable_name} PaperScissorsRockGame)

# Add PaperScissorsRockGame link library
target_link_libraries(${executable_name} PRIVATE ${library_name})

# Add include directories
target_include_directories(${executable_name} PRIVATE include)

# IDEs should group the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
  
add_subdirectory(tests)
  
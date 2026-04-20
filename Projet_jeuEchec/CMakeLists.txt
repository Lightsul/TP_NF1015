cmake_minimum_required(VERSION 3.10)
set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)
include(cmake_cours.cmake)

project(Projet_jeuEchec CXX)

afficher_infos_generateur()

set(BILIOTHEQUE_COURS
    "bibliotheque_cours/bibliotheque_cours.cpp"
    "include/bibliotheque_cours.hpp"
    "include/CodeCoverage_bugfix.h"
    "bibliotheque_cours/verification_allocation.cpp"
    "include/verification_allocation.hpp"
    "include/debogage_memoire.hpp"
)

file(GLOB ALL_FILES
    *.cpp
    *.hpp
    modele/*.cpp
    modele/*.hpp
    vue/*.cpp
    vue/*.hpp
    ${BILIOTHEQUE_COURS}
)

configurer_options_compilation_globales()
configurer_Qt_auto_tout()
add_executable(${PROJECT_NAME} ${ALL_FILES})
set(CMAKE_PREFIX_PATH "/Users/edwin/Qt/6.11.0/macos")
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

afficher_version_Qt()
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
configurer_GoogleTest(${PROJECT_NAME})

ajouter_target_couverture(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "include")
cmake_minimum_required(VERSION 3.5)

project(r-type)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

Set(SOURCE_FILES_COMMON

        Common/include/Request.h
        Common/include/RequestNewGame.h
        Common/include/ResponseListGames.h
        Common/include/EntityEnum.h
        Common/include/GameEntity.h
        Common/include/Wall.h
        Common/include/Ship.h
        Common/include/RequestGameState.h
        Common/include/GameStateItem.h
        Common/include/RequestClientAction.h
        Common/include/ClientActionEnum.h
        Common/include/RequestEnum.h
        Common/include/Monster.h

        Common/src/Request.cpp
        Common/src/RequestNewGame.cpp
        Common/src/GameEntity.cpp
        Common/src/Wall.cpp
        Common/src/Ship.cpp
        Common/src/Monster.cpp
        Common/src/RequestGameState.cpp
        )

set(SOURCE_FILES_SERVER

        Server/include/Game.h
        Server/include/Server.h


        Server/src/Game.cpp
        Server/src/Server.cpp
        Server/src/main.cpp)

set(SOURCE_FILES_CLIENT
        Client/include/Client.h
        Client/include/Menu.h
        Client/include/Mainframe.h

        Client/src/main.cpp
        Client/src/Client.cpp
        Client/src/Menu.cpp
        Client/src/Mainframe.cpp)

add_executable(r-type_server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_COMMON})
add_executable(r-type_client ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_COMMON})

target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

target_include_directories(
        r-type_server PUBLIC

        Server/include
        Server/src

        Common/include
        Common/src
)

target_include_directories(
        r-type_client PUBLIC

        Client/include
        Client/src

        Common/include
        Common/src
)

set_property(TARGET r-type_server PROPERTY CXX_STANDARD 20)
set_property(TARGET r-type_client PROPERTY CXX_STANDARD 20)
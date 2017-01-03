cmake_minimum_required(VERSION 3.6)
project(ex4)

set(core_sockets sockets/Socket.cpp sockets/Udp.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (BOOST_ROOT CACHE PATH "/Home/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

add_library(sockets ${core_sockets})
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES Point.cpp Point.h
        Node.cpp Node.h Grid.cpp Grid.h Graph.cpp Graph.h Driver.cpp Driver.h
        TripInformation.cpp TripInformation.h Cab.cpp Cab.h LuxuryCab.cpp
        LuxuryCab.h Passenger.cpp Passenger.h TaxiCenter.cpp TaxiCenter.h
        MainFlowtxt.txt MainFlow.h BFS.cpp BFS.h
        BasicCab.h BasicCab.cpp MainFlow.cpp
        sockets/Socket.cpp sockets/Socket.h sockets/Udp.cpp sockets/Udp.h)
add_executable(client ${SOURCE_FILES} ClientMain.cpp)
add_executable(server ${SOURCE_FILES} Server.cpp)

target_link_libraries(server ${Boost_LIBRARIES} sockets)
target_link_libraries(client ${Boost_LIBRARIES} sockets)
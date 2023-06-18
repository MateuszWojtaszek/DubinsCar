cmake_minimum_required(VERSION 3.25)
project(Dubbins_Car)

set(CMAKE_CXX_STANDARD 20)


include(src/cpp_warnings.cmake)

add_executable(Dubbins_Car src/main.cpp src/Vector2d.cpp src/Vector2d.h src/Pose.cpp src/Pose.h src/Sector.cpp src/Sector.h src/PathPlanner.cpp
        src/PathPlanner.h src/Car.cpp src/Car.h src/Sector_C.cpp src/Sector_C.h src/Sector_S.cpp src/Sector_S.h)

target_compile_options(Dubbins_Car PRIVATE ${PROJECT_WARNING_FLAGS})
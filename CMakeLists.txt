cmake_minimum_required(VERSION 3.25)
project(Dubbins_Car)

set(CMAKE_CXX_STANDARD 20)
find_package(Doxygen)
if(DOXYGEN_FOUND)

set(SOURCE_FILES Dubbins_Car src/cpp/main.cpp src/cpp/Vector2d.cpp src/heders/Vector2d.h src/cpp/Pose.cpp src/heders/Pose.h src/cpp/Sector.cpp src/heders/Sector.h src/cpp/PathPlanner.cpp
        src/heders/PathPlanner.h src/cpp/Car.cpp src/heders/Car.h src/cpp/Sector_C.cpp src/heders/Sector_C.h src/cpp/Sector_S.cpp src/heders/Sector_S.h src/heders/MATH.h src/cpp/MATH.cpp)
set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

add_custom_command(
        OUTPUT ${DOXYGEN_OUTPUT}
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${DOXYGEN_INPUT}
)

add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})

add_custom_target(apidoc_forced
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

endif(DOXYGEN_FOUND)

include(src/cpp_warnings.cmake)

add_executable(Dubbins_Car src/cpp/main.cpp src/cpp/Vector2d.cpp src/heders/Vector2d.h src/cpp/Pose.cpp src/heders/Pose.h src/cpp/Sector.cpp src/heders/Sector.h src/cpp/PathPlanner.cpp
        src/heders/PathPlanner.h src/cpp/Car.cpp src/heders/Car.h src/cpp/Sector_C.cpp src/heders/Sector_C.h src/cpp/Sector_S.cpp src/heders/Sector_S.h src/heders/MATH.h src/cpp/MATH.cpp src/heders/Enums.h)

target_compile_options(Dubbins_Car PRIVATE ${PROJECT_WARNING_FLAGS})
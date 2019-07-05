# Put this CMakeLists.txt in the src folder (don't forget to rename it)

include_directories(../libs)
link_directories(../libs)
link_libraries(arduino_core)

add_executable(Oreo_Android main.cpp)
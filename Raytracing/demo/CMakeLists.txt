# Create the demo executable
add_executable(Demo main.cpp)

link_libraries(RaytracingLib ${SDL3_LIBRARIES})

# Link the library and SDL2
target_link_libraries(Demo RaytracingLib ${SDL3_LIBRARIES})
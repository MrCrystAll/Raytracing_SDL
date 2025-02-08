file(GLOB_RECURSE FILES_SRC_E "${CMAKE_SOURCE_DIR}/Raytracing/src/Raytracing/*.cpp")

# Create the library
add_library(RaytracingLib STATIC ${FILES_SRC_E})

# Link SDL3 to the library
target_link_libraries(RaytracingLib ${SDL3_LIBRARIES})

# Include the public headers
target_include_directories(RaytracingLib PUBLIC "${CMAKE_SOURCE_DIR}/Raytracing/include")
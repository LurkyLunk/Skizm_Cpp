cmake_minimum_required(VERSION 3.10)
project(AIBAR)

# Find required packages
find_package(Bullet REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PCL 1.7 REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/thirdparty/imgui)

# Include directories
include_directories(/mnt/c/Users/nasho/GitHub/AIBAREngine/include)
include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)
include_directories(/usr/include/bullet)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Source files
set(SOURCE_FILES
    src/main.cpp
)

# Create executable
add_executable(AIBAR ${SOURCE_FILES})

# Link libraries
target_link_libraries(AIBAR ${BULLET_LIBRARIES})
target_link_libraries(AIBAR ${OPENGL_LIBRARIES})
target_link_libraries(AIBAR ${GLEW_LIBRARIES})
target_link_libraries(AIBAR glfw)
target_link_libraries(AIBAR ${OpenCV_LIBS})
target_link_libraries(AIBAR ${GLUT_LIBRARIES} )
target_link_libraries(AIBAR ${PCL_LIBRARIES})




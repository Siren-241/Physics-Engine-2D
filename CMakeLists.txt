cmake_minimum_required(VERSION 3.5.0)
project(Physics_Engine VERSION 0.1.0 LANGUAGES C CXX)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

add_executable(Physics_Engine
    main.cpp
    sourceCode/Math2D.cpp
    sourceCode/objects.cpp
    sourceCode/Rigidbody.cpp
    sourceCode/SceneManager.cpp
    sourceCode/utils.cpp
    sourceCode/Renderer.cpp
    sourceCode/Collision.cpp
    sourceCode/engine.cpp
    sourceCode/Application.cpp
    )

target_link_libraries(Physics_Engine ${SDL2_LIBRARIES})
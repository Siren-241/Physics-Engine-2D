cmake_minimum_required(VERSION 3.5.0)
project(Physics_Engine VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Physics_Engine
    engine.cpp
    sourceCode/Math2D.cpp
    sourceCode/objects.cpp
    sourceCode/Rigidbody.cpp
    sourceCode/SceneManager.cpp
    sourceCode/utils.cpp

    )


cmake_minimum_required(VERSION 3.5)
project(OpenGLCourse VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

#include_directories( C:/glfw-3.3.6.bin.WIN64/include )
include_directories( C:/glfw-3.3.6.bin.WIN64/include C:/glew-2.1.0/include )
#link_directories( C:/glfw-3.3.6.bin.WIN64/lib-mingw-w64 )
link_directories( C:/glfw-3.3.6.bin.WIN64/lib-mingw-w64 C:/glew-2.1.0/lib/Release/x64 )
#link_directories( C:/glfw-3.3.6.bin.WIN64/lib-vc2019 C:/glew-2.1.0/lib/Release/x64 )

add_compile_definitions(GLEW_STATIC)

add_executable(OpenGLCourse
    OpenGLCourse.cpp
    Renderer.cpp
    VertexBuffer.cpp
    VertexArray.cpp
    VertexBufferLayout.cpp
    IndexBuffer.cpp
    )
#target_link_libraries(OpenGLCourse PRIVATE glfw3 OpenGL::GL)
target_link_libraries(OpenGLCourse PRIVATE glfw3 glew32s OpenGL::GL)

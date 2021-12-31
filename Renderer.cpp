#include "Renderer.hpp"
#include <iostream>

void GLClearError()
{
    while( glGetError() != GL_NO_ERROR );
}

 bool GLLogCall(const char *function, const char *file, int line)
{
    GLenum glError = glGetError();
    while( glError != GL_NO_ERROR )
    {
        std::cout << "GL ERROR: 0x" << std::hex << glError << std::dec << std::endl;
        std::cout << function << " " << file << ":" << line << std::endl;
        return false;
        glError = glGetError();
    }
    return true;
}

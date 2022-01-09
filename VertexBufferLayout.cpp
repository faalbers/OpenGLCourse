#include "VertexBufferLayout.hpp"
#include "Renderer.hpp"
#include  <iostream>

VertexBufferLayout::VertexBufferLayout()
    : m_Stride(0)
{
    //GLCall(glGenBuffers(1, &m_RendererID));
}

VertexBufferLayout::~VertexBufferLayout()
{
    //GLCall(glDeleteBuffers(1, &m_RendererID));
}

template<>
void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}

void VertexBufferLayout::error_(std::string message) const
{
    std::cout << "VertexBufferLayout:" << std::endl;
    std::cout << "-> " << message << std::endl;
    std::cout << "exit application ..." << std::endl;
    exit(1);
}

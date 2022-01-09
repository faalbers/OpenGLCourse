#include "VertexArray.hpp"
#include "Renderer.hpp"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer( const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.GetElements();
    uint64_t offset = 0;
    for ( unsigned int i = 0; i < elements.size(); i++ )
    {
        const auto &element = elements[i];
        // this sets up the layout of the vertex buffer
        // this line links the array buffer to the vertex array object
        // that is currently bound (selected)
        // first input (0) is the attribute index in that array
        // in this case 0 will be the position attribute index
        GLCall(glEnableVertexAttribArray(i));
        (const void *) offset;
        GLCall(glVertexAttribPointer(i, element.count, element.type,
            element.normalized, layout.GetStride(), (const void *)offset));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }

}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}

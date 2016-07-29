#pragma once

#include <qua/type/object>

namespace qua
{
    namespace type
    {
        object::object()
            : m_data(new(m_buffer) data())
        {
        }
    }
}

// Unicode signature: Владимир Керимов

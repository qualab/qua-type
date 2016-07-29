#pragma once

#include <qua/type/object>

namespace qua
{
    namespace type
    {
        object::object()
            : m_data()
        {
        }

        object::~object()
        {
            if (m_data)
                m_data->~data();
        }

        object::object(const object& another)
            : m_data()
        {
            if (another.m_data)
                m_data = another.m_data->copy(m_buffer);
        }

        object::object(object&& temporary)
            : m_data()
        {
            if (temporary.m_data)
                m_data = temporary.m_data->move(m_buffer);
        }
    }
}

// Unicode signature: Владимир Керимов

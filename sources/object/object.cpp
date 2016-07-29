#pragma once

#include "object_data.hpp"

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
    }
}

// Unicode signature: Владимир Керимов

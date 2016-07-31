#pragma once

#include <qua/type/scalar>
#include <new>

namespace qua
{
    namespace type
    {
        object::object()
            : _data()
        {
        }

        object::~object()
        {
            clear();
        }

        void object::clear()
        {
            if (_data)
            {
                _data->~data();
                _data = nullptr;
            }
        }

        object::object(const object& another)
            : _data()
        {
            *this = another;
        }

        object::object(object&& temporary)
            : _data()
        {
            *this = std::move(temporary);
        }

        object& object::operator = (const object& another)
        {
            clear();
            if (another._data)
                _data = another._data->copy(_buffer);
            return *this;
        }

        object& object::operator = (object&& temporary)
        {
            clear();
            if (temporary._data)
                _data = temporary._data->move(_buffer);
            return *this;
        }

        object::object(object::data* derived)
            : _data(derived)
        {
            if (static_cast<void*>(_data) != buffer())
                throw bad_data();
        }

        void* object::buffer()
        {
            return static_cast<void*>(_buffer);
        }

        object::bad_data::bad_data()
            : base("Bad data initialization. "
                "Data must be derived class created by placement new in the internal buffer of this object.")
        {
        }
    }
}

// Unicode signature: Владимир Керимов

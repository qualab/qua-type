﻿#pragma once

#include <qua/type/scalar>

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
            if (another._data)
                _data = another._data->copy(_buffer);
        }

        object::object(object&& temporary)
            : _data()
        {
            if (temporary._data)
                _data = temporary._data->move(_buffer);
        }

        object& object::operator = (const object& another)
        {
            clear();
            _data = another._data->copy(_buffer);
            return *this;
        }

        object& object::operator = (object&& temporary)
        {
            clear();
            _data = temporary._data->move(_buffer);
            return *this;
        }

        object::object(object::data* derived)
            : _data(derived)
        {
        }

        void* object::buffer()
        {
            return static_cast<void*>(_buffer);
        }

        template <>
        bool object::get() const
        {
        }

        template <>
        std::int8_t object::get() const
        {
        }

        template <>
        std::int16_t object::get() const
        {
        }

        template <>
        std::int32_t object::get() const
        {
        }

        template <>
        std::int64_t object::get() const
        {
        }

        template <>
        std::uint8_t object::get() const
        {
        }

        template <>
        std::uint16_t object::get() const
        {
        }

        template <>
        std::uint32_t object::get() const
        {
        }

        template <>
        std::uint64_t object::get() const
        {
        }

        template <>
        float object::get() const
        {
        }

        template <>
        double object::get() const
        {
        }

        template <>
        void object::set(bool value)
        {
            clear();
            _data = new(_buffer) scalar<bool>::data(value);
        }

        template <>
        void object::set(std::int8_t value)
            : _data(new(_buffer) scalar<std::int8_t>::data(value))
        {
        }

        template <> QUA_TYPE_PUBLIC void object::set(std::int16_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::int32_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::int64_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::uint8_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::uint16_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::uint32_t value);
        template <> QUA_TYPE_PUBLIC void object::set(std::uint64_t value);
        template <> QUA_TYPE_PUBLIC void object::set(float value);
        template <> QUA_TYPE_PUBLIC void object::set(double value);
        template <> QUA_TYPE_PUBLIC void object::set(std::nullptr_t);
    }
}

// Unicode signature: Владимир Керимов

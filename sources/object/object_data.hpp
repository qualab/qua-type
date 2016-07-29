#pragma once

#include <qua/type/object>

namespace qua
{
    namespace type
    {
        class object::data
        {
        public:
            virtual ~data() = 0;

            virtual bool is_null() const
            {
                return false;
            }
        };

        class null_data : public object::data
        {
        public:
            virtual bool is_null() const override
            {
                return true;
            }
        };
    }
}

// Unicode signature: Владимир Керимов

#ifndef CONSTANTSOBJECT_H
#define CONSTANTSOBJECT_H

#include <vector>
#include "objects/Object.h"

namespace myproject
{
    namespace object
    {
        class ObjectContainer
        {
            std::vector<Object*> m_objects;
            int m_materialCount;
            int m_lightCount;
        public:
            ObjectContainer(std::vector<Object*> objects, int matCount, int lightCount):
            m_objects{objects}, m_materialCount{matCount}, m_lightCount{lightCount}
            {}
            std::vector<Object*>& GetObject()
            {
                return m_objects;
            }
        };
    }
}

#endif

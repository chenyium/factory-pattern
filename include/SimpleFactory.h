#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include "Product.h"

class CSimpleFactory
{
public:
    CProduct* CreateProductA();
    CProduct* CreateProductB();
};

#endif

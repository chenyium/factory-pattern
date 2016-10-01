#pragma once

#include "Product.h"

// 简单工厂
class CSimpleFactory
{
public:
	CSimpleFactory()  { }
	~CSimpleFactory() { }

public:
    CProduct* CreateProduct(int nProuctType = 0);
    CProduct* CreateProductA();
    CProduct* CreateProductB();
};

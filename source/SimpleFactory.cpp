#include "SimpleFactory.h"
#include "Product.h"
#include "ProductA.h"
#include "ProductB.h"

CProduct* CSimpleFactory::CreateProductA()
{
	return new CProductA();
}

CProduct* CSimpleFactory::CreateProductB()
{
	return new CProductB();
}

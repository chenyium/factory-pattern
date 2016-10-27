#include "Factory.h"
#include "ProductA.h"
#include "ProductB.h"
#include "ProductNew.h"

CProduct* CFactoryConcrete::CreateProduct()
{
    return new CProductA();
}

CProduct* CFactoryConcreteNew::CreateProduct()
{
	return new CProductNew();
}

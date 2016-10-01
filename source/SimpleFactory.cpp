#include "SimpleFactory.h"
#include "Product.h"
#include "ProductA.h"
#include "ProductB.h"

CProduct* CSimpleFactory::CreateProduct(int nProductType)
{
	CProduct *product = NULL;

	switch (nProductType) {
        case 0:
            product = new CProductA();
            break;
        case 1:
            product = new CProductB();
            break;
        default:
            product = new CProductA();
            break;
	}

	return product;
}

CProduct* CSimpleFactory::CreateProductA()
{
	return new CProductA();
}

CProduct* CSimpleFactory::CreateProductB()
{
	return new CProductB();
}

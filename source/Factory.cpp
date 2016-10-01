#include "Factory.h"
#include "ProductA.h"
#include "ProductB.h"
#include "ProductNew.h"

CProduct* CFactoryConcrete::CreateProduct(int nProductType)
{
	CProduct *pProduct = NULL;

	switch (nProductType) {
        case 0:
            pProduct = new CProductA();
            break;
        case 1:
            pProduct = new CProductB();
            break;
        default:
            pProduct = new CProductA();
            break;
	}

	return pProduct;
}

CProduct* CFactoryConcreteNew::CreateProduct(int nProductType)
{
	return new CProductNew();
}

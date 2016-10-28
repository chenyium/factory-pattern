#include "Product.h"
#include "SimpleFactory.h"
#include "Factory.h"

void SimpleFactory();
void FactoryMethod();
void FactoryMethodTempl();
void AbstractFactory();

int main(int argc, char **argv)
{
    SimpleFactory();
    FactoryMethod();
    FactoryMethodTempl();

    return 0;
}

void SimpleFactory() 
{
    cout << "----- simple factory -----------------------------" << endl;

    CSimpleFactory simpleFactory;
    CProduct *pProduct = NULL;

    pProduct = simpleFactory.CreateProductA();
    pProduct->Function();
    delete pProduct, pProduct = NULL;

    pProduct = simpleFactory.CreateProductB();
    pProduct->Function();
    delete pProduct, pProduct = NULL;
}

void FactoryMethod()
{
    cout << "----- factory method -----------------------------" << endl;

    CProduct *pProduct = NULL;
    CFactory *pFactory = NULL;
    pFactory = new CFactoryConcrete();

    // 创建产品A
    pProduct = pFactory->CreateProduct();
    pProduct->Function();
    delete pProduct, pProduct = NULL;

    delete pFactory, pFactory = NULL;

    pFactory = new CFactoryConcreteNew();

    // 创建新产品
    pProduct = pFactory->CreateProduct();
    pProduct->Function();
    delete pProduct, pProduct = NULL;

    delete pFactory, pFactory = NULL;
}


#include "ProductA.h"
#include "ProductB.h"
void FactoryMethodTempl() 
{
    cout << "----- factory method template --------------------" << endl;

    CProduct *product = NULL;
        
    product = CFactoryTempl<CProduct, CProductA>::CreateProduct();
    product->Function();
    delete product, product = NULL;

    product = CFactoryTempl<CProduct, CProductB>::CreateProduct();
    product->Function();
    delete product, product = NULL;

    cout << "--------------------------------------------------" << endl;

    CCreator<CProduct> creator;
    creator.RegisterCreator<CProductA>("ProductA");
    creator.RegisterCreator<CProductB>("ProductB");

    product = creator.CreateProduct("ProductA");
    product->Function();
    delete product, product = NULL;

    product = creator.CreateProduct("ProductB");
    product->Function();
    delete product, product = NULL;

    creator.UnregisterCreators();
}

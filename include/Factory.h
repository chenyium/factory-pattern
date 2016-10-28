#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"

// 定义加工产品的接口
class CFactory
{
protected:
	CFactory() {}
public:
	virtual ~CFactory() {}

public:
	virtual CProduct* CreateProduct() = 0;
};

// 工厂实现
class CFactoryConcrete : public CFactory
{
public:
	CFactoryConcrete() {}
	virtual ~CFactoryConcrete() {}

public :
	virtual CProduct* CreateProduct();
};

// 新工厂
class CFactoryConcreteNew : public CFactory
{
public:
	CFactoryConcreteNew() {}
	virtual ~CFactoryConcreteNew() {}

public :
	virtual CProduct* CreateProduct();
};


template <class ProductBase, class ProductConcrete>
class CFactoryTempl
{
public:
    typedef CFactoryTempl<ProductBase, ProductConcrete> thisClass;

public:
    CFactoryTempl() {}
    virtual ~CFactoryTempl() {}

public:
    static ProductBase* CreateProduct();
};

template <class ProductBase, class ProductConcrete>
ProductBase* CFactoryTempl<ProductBase, ProductConcrete>::CreateProduct() 
{
    return new ProductConcrete();
}


#include <string>
#include <map>

template <class ProductBase>  
class CCreator  
{
public:  
    typedef ProductBase* (*PCREATEPRODUCT)();
    typedef std::map<std::string, PCREATEPRODUCT> MapRegisterCreator;  

public:
    template <typename ProductConcrete>  
    void RegisterCreator(const std::string& name);

    void UnregisterCreators();

public:
    ProductBase* CreateProduct(const std::string& name);

private:  
    MapRegisterCreator m_creators;
};

template <class ProductBase>  
template <class ProductConcrete>  
void CCreator<ProductBase>::RegisterCreator(const std::string& name) {
    m_creators[name] = CFactoryTempl<ProductBase, ProductConcrete>::CreateProduct;  
}

template <class ProductBase>  
void CCreator<ProductBase>::UnregisterCreators() {
    m_creators.clear();  
}  

template <class ProductBase>
ProductBase* CCreator<ProductBase>::CreateProduct(const std::string& name) {
    typename MapRegisterCreator::iterator it = m_creators.find(name);

    if (it != m_creators.end()) {
        PCREATEPRODUCT creator = it->second;
        if (NULL != creator)
            return creator();
    }

    return NULL;
}

#endif

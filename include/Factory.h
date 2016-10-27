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

#endif

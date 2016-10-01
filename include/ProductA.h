#pragma once

#include "Product.h"

// 产品A
class CProductA : public CProduct
{
public:
	CProductA();
	virtual ~CProductA();

public:
	virtual void Function();
};

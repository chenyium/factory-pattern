#ifndef PRODUCT_A_H
#define PRODUCT_A_H

#include "Product.h"

class CProductA : public CProduct
{
public:
	CProductA();
	virtual ~CProductA();

public:
	virtual void Function();
};

#endif

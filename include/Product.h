#pragma once

#include <iostream>
using namespace std;

// 这是一个系列产品的基类
class CProduct
{
protected:
	CProduct();
public:
	virtual ~CProduct();

public:
	virtual void Function() = 0;
};

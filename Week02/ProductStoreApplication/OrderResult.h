#pragma once
#include <string>
#include <ostream>

class OrderResult
{
private:
	std::string orderText;
	double orderProfit;
public:
	OrderResult();
	OrderResult(const std::string order_text, const double order_profit);

	friend std::ostream& operator<<(std::ostream& os, const OrderResult& obj);
};

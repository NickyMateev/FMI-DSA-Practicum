#include "OrderResult.h"


OrderResult::OrderResult() : OrderResult("empty", 0)
{
}

OrderResult::OrderResult(const std::string order_text, const double order_profit)
{
	this->orderText = order_text;
	this->orderProfit = order_profit;
}

std::ostream& operator<<(std::ostream& os, const OrderResult& obj)
{
	os << obj.orderText << std::endl;
	os << "Profit: $" << obj.orderProfit;

	return os;
}

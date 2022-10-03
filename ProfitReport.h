#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include <map>
#include <string>
#include <vector>
#include <sstream>

#include "Company.h"
#include "ProfitCalculator.h"




std::string getProfitReport(const Company* fromInclusiveComp, const Company* ToInclusiveComp,
	std::map<int, ProfitCalculator>& profitByComp) {
	std::ostringstream ostr;
	for (const Company* c = fromInclusiveComp; c<= ToInclusiveComp;c++)
	{
		int id = c->getId();
		ProfitCalculator calc = profitByComp.find(id)->second;
		ostr << c->getName() << " = " << calc.calculateProfit(*c);
		if (c!= ToInclusiveComp)
		{
			ostr << std::endl;
		}
	}
	return ostr.str();

} 




#endif // !PROFIT_REPORT_H

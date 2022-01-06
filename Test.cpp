#include "Factors.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isKPeriodic(const string& sample, string::size_type k)
{//проверяет является ли данная строка sample кратной собственной подстроке длины k

	//string shifted{ sample.cbegin() + k, sample.cend() };
	//shifted += {sample.cbegin(), sample.cbegin() + k};
	//return sample == shifted;

	for (string::size_type i{ k }; i < sample.size(); ++i) {
		if (sample[i] != sample[i % k]) {
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "Enter string: ";

	string sample;
	cin >> sample;
//если строка периодична, то её периодом могут быть только делители длины строки
	vector<unsigned> factors;
//запишем в вектор factors все делители sample.size()
	get_factors(sample.size(), factors);
//протестируем только подстроки, длины которых делят sample нацело
	for (auto num : factors) {
		if(num != sample.size())
			cout << num << ": " << isKPeriodic(sample, num) << '\n';
	}

	return 0;
}
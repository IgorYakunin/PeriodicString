#include "Factors.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isKPeriodic(const string& sample, string::size_type k)
{//��������� �������� �� ������ ������ sample ������� ����������� ��������� ����� k

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
//���� ������ ����������, �� � �������� ����� ���� ������ �������� ����� ������
	vector<unsigned> factors;
//������� � ������ factors ��� �������� sample.size()
	get_factors(sample.size(), factors);
//������������ ������ ���������, ����� ������� ����� sample ������
	for (auto num : factors) {
		if(num != sample.size())
			cout << num << ": " << isKPeriodic(sample, num) << '\n';
	}

	return 0;
}
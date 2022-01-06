#pragma
#include <vector>

void get_primes(std::vector<unsigned>&, std::vector<unsigned>::size_type);

void prime_factor_decomposition(unsigned number, std::vector<std::pair<unsigned, unsigned>>& prime_factors);

void get_factors(unsigned number, std::vector<unsigned>& factors);

template <typename RAIter, typename Value_type>
RAIter binary_search(RAIter beg, RAIter end, Value_type sample) {
	//ѕоиск максимального элемента не превосход€щего заданный в упор€доченном контейнере
	RAIter iter;
	if ((beg < end) and (*beg <= sample) and (sample <= *(end - 1))) {
		iter = beg;
		while (beg < end - 1) {
			iter = beg + (end - beg) / 2;
			if (sample < *iter) {
				end = iter;
			}
			else if (*iter < sample) {
				beg = iter;
			}
			else {
				break;
			}
		}
		if (*iter != sample)
			iter = beg;
	}
	else {
		iter = end;
	}
	return iter;
}


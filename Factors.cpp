#include "Factors.h"
#include <cmath>
#include <vector>
#include <cassert>

void get_primes(std::vector<unsigned>& primes, std::vector<unsigned>::size_type limit) {
//находит все простые числа не превышающие limit методом решета Эратосфена
	assert(1 < limit);

	using size_type = std::vector<unsigned>::size_type;

	std::vector<unsigned> sieve(limit + 1, 1);
	sieve[0] = sieve[1] = 0;

	for (size_type i = 0; i <= limit; ++i) {
		while ((i <= limit) and (sieve[i] == 0)) {
			++i;
		}
		if (limit < i) {
			break;
		}
		primes.push_back(i);
		for (size_type j = i << 1; j <= limit; j += i)
			sieve[j] = 0;
	}
}

void prime_factor_decomposition(unsigned number, std::vector<std::pair<unsigned, unsigned>>& prime_factors) {
//находти все простые делители данного числа number
	using Iterator = std::vector<unsigned>::const_iterator;

	std::vector<unsigned> primes;
	get_primes(primes, number);

	if (number == primes.back()) {
		prime_factors.push_back(std::pair<unsigned, unsigned>{number, 1});
	}
	else {
		Iterator upper_bound = binary_search(primes.begin(), primes.end(), number / 2);
		for (Iterator iter = primes.begin(); iter <= upper_bound; ++iter) {
			if (number % *iter == 0) {
				prime_factors.push_back(std::pair<unsigned, unsigned>{*iter, 1});
				while ((number /= *iter) % *iter == 0) {
					prime_factors.back().second++;
				}
			}
		}
	}
}

void get_factors(unsigned number, std::vector<unsigned>& factors) {
//находит все делители данного числа number
	std::vector<std::pair<unsigned, unsigned>> prime_factors;
	prime_factor_decomposition(number, prime_factors);

	factors.push_back(1);
	for (const auto& item : prime_factors) {
		std::vector<unsigned> temp;
		unsigned mult = 1;
		for (unsigned i = 0; i < item.second; ++i) {
			std::vector<unsigned>::const_iterator iter = factors.begin();
			mult *= item.first;
			while (iter != factors.end()) {
				temp.push_back(*iter * mult);
				++iter;
			}
		}
		for (auto item : temp) {
			factors.push_back(item);
		}
	}
}

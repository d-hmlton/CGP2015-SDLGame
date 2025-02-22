#include "RNG.h"

int RNG::numberRNG(int rangeStart, int rangeEnd) {
	uniform_int_distribution<int> distribution(rangeStart, rangeEnd);
	int outcome = distribution(_generator);

	return outcome;
}
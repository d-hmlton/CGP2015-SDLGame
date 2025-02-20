#pragma once

#include <random>
using namespace std;

class RNG {
private:
	default_random_engine _generator;

public:
	int numberRNG(int rangeStart, int rangeEnd);
};
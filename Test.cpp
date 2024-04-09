/*
 * File: Test.cpp
 * Author: Siavash Glolani
 * Description: This file contains the implementation of the Test class constructor.
 * It generates random numbers according to a specified distribution and sorts them.
 */

#include "Test.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename type>
Test<type>::Test(int n = 100, Distribution d = UNIFORM)
{
	int i;
	const type uni_range = 32763;

	srand((unsigned)time(NULL));

	if (d == UNIFORM)
	{
		for (i = 0; i < n; i++)
		{
			type x, r;
			do
			{
				x = rand();
			} while (x > uni_range); //Making sure that every number has an equal chance to be picked up by throwing out some numbers to
			//create a range that is divisible by our number

			r = x / 163 - 100;
			numbers.push_back(r);
		}
	}
	else if (d == NORMAL)
	{
		std::random_device rd{};
		std::mt19937 gen{ rd() };

		// values near the mean are the most likely
		// standard deviation affects the dispersion of generated values from the mean
		std::normal_distribution<double> d(0.0, 10.0);

		// draw a sample from the normal distribution and round it to an integer
		auto random_int = [&d, &gen] { return d(gen); };

		for (i = 0; i < n; i++)
			numbers.push_back((type)random_int());
	}
	else cout << "Not a valid distribution!" << endl;

	sort(numbers.begin(), numbers.end());
}

template class Test<int>;

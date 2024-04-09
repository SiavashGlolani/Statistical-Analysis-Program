/*
 * File: UniformTest.cpp
 * Author: Siavash Glolani
 * Description: This file contains the implementation of the UniformTest class, which is a subclass of Test.
 */

#include "UniformTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

// Constructor implementation for UniformTest.
// Initializes the base Test class with the number of samples and UNIFORM distribution.

template <typename type>
UniformTest<type>::UniformTest(int numSamples) : Test(numSamples, UNIFORM)
{
	// Constructor body (currently empty as initialization is handled in the base class)
}


// getMin implementation for UniformTest.
// Returns the minimum value in the vector.
template <typename type>
type UniformTest<type>::getMin()
{
	return numbers[0];
	// Assumes the vector is sorted
	// Alternative method using min_element:
	//*min_element(numbers.begin(), numbers.end());
}

// getMax implementation for UniformTest.
// Returns the maximum value in the vector.
template <typename type>
type UniformTest<type>::getMax()
{
	return numbers[numbers.size() - 1]; // Assumes the vector is sorted
}


// getMean implementation for UniformTest.
// Calculates and returns the mean (average) of the values in the vector.
template <typename type>
type UniformTest<type>::getMean()
{
	int i;
	double sum = 0.0;
	for (i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	return sum / numbers.size();
}


// getMedian implementation for UniformTest.
// Returns the median value of the vector.
template <typename type>
type UniformTest<type>::getMedian()
{
	return numbers[numbers.size() / 2]; // Assumes the vector is sorted
}

// getHistogram implementation for UniformTest.
// Generates and returns a histogram as a vector, dividing the data into 20 buckets.
template <typename type>
vector <type> UniformTest<type>::getHistogram()
{
	vector <type> histogram(20, 0);
	int count = 0;
	int i;
	double Max = getMax(), Min = getMin(), range = (Max - Min) / 20.0;


	for (i = 0; i < numbers.size(); i++) {
		int ind = (int)((numbers[i] - Min) / range);
		if (ind > 19) ind = 19;
		histogram[ind]++;
	}
	return histogram;
}

// Explicit instantiation of UniformTest for type int.
template class UniformTest<int>;



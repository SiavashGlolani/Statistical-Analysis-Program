/*
 * File: UniformTest.h
 * Author: Siavash Glolani
 * Description: This file contains the declaration of the UniformTest class, which is a subclass of Test.
 */

#pragma once
#include <vector>
#include <iostream>
#include "Test.h"

// UniformTest class: A template class that inherits from the Test class.
// It is used to perform statistical tests on a vector of numbers generated
// using a uniform distribution. The class overrides methods to calculate
// minimum, maximum, mean, median, and histogram of the data.

template <typename type>
class UniformTest : public Test<type> {
public:

   // Constructor: Accepts an integer representing the number of samples
  // to be generated and initializes the Test class with this value and 
  // the UNIFORM distribution type.

	UniformTest(int);
	type getMin();
	type getMax();
	type getMean();
	type getMedian();

	// getHistogram: Generates and returns a histogram of the data set as a vector.
	// The histogram is divided into 20 evenly sized buckets.
	vector<type> getHistogram();
};

// Explicit instantiation of UniformTest for type int.
// This is required since we are defining the class methods in a separate .cpp file
template class UniformTest<int>;

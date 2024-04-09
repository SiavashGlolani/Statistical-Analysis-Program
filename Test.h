/*
 * File: Test.h
 * Author: Siavash Glolani
 * Description: This file defines the Test class, which serves as an abstract base class for statistical tests.
 */

#pragma once
#include <vector>
#include <iostream>


using namespace std;

enum Distribution { UNIFORM, NORMAL };

template <typename type>
class Test {
protected:
	vector <type> numbers;
public:
	Test(int = 100, Distribution = UNIFORM);
	virtual type getMin() = 0;
	virtual type getMax() = 0;
	virtual type getMean() = 0;
	virtual type getMedian() = 0;
	virtual vector <type> getHistogram() = 0;
};



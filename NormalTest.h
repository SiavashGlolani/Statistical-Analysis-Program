/*
 * File: NormalTest.h
 * Author: Siavash Glolani
 * Description: This file contains the declaration of the NormalTest class, which is a subclass of the Test class.
 * It defines methods to perform statistical analysis on a vector of numbers generated from a normal distribution.
 */

#pragma once
#include <vector>
#include <iostream>
#include "Test.h"

template <typename type>
class NormalTest : public Test<type> {
public:
    NormalTest(int);
    type getMin();
    type getMax();
    type getMean();
    type getMedian();
    vector<type> getHistogram();
};

template class NormalTest<int>;

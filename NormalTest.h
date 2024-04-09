
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
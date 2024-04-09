#include "NormalTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>


using namespace std;

template <typename type>
NormalTest<type>::NormalTest(int numSamples) : Test(numSamples, NORMAL)
{

}

template <typename type>
type NormalTest<type>::getMin()
{
	return numbers[0];
	//*min_element(numbers.begin(), numbers.end());
}

template <typename type>
type NormalTest<type>::getMax()
{
	return numbers[numbers.size() - 1];
}

template <typename type>
type NormalTest<type>::getMean()
{
	int i;
	double sum = 0.0;
	for (i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	return sum / numbers.size();
}

template <typename type>
type NormalTest<type>::getMedian()
{
	return numbers[numbers.size() / 2];
}


template <typename type>
vector <type> NormalTest<type>::getHistogram()
{
	vector <type> histogram(20, 0);
	int count = 0;
	int i, Max = getMax(), Min = getMin(), range = (Max - Min) / 20.0;

	for (i = 0; i < numbers.size(); i++) {
		int ind = (int)((numbers[i] - Min) / range);
		if (ind > 19) ind = 19;
		histogram[ind]++;

	}
	return histogram;
}

template class NormalTest<int>;




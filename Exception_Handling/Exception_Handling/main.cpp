#include <iostream>
#include <stdexcept>
#include <vector>
#include "exception_custom.h"
#include <future>

int main() {

	std::vector<int> myVector = { 1, 2, 3, 4, 5 };
	std::future<int> myFuture;

	invalidArgCheck(-5); 
	outOfRangeCheck(myVector); 
	calculateSquareRoot(-3);
	divideCheck(10, 0);
	lengthCheck(myVector);
	futureCheck(myFuture);
	

}
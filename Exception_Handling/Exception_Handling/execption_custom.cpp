#include <iostream>
#include <vector>
#include <future>



//Logic Error: Invaild Argument.
void invalidArgCheck(int age)
{
	try
	{
		std::cout << "Enter Value for Age: " << std::endl;
		std::cin >> age;

		if (age < 0)
		{
			throw std::invalid_argument("Age cannot be negative!");
		}

	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid Argument Exception Caught: " << e.what() << std::endl;
	}
}
//Logic Error: Accessing Out of Bound Element.
void outOfRangeCheck(const std::vector<int> v)
{
	try
	{
		v.at(7); // This will throw an exception
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Caught Out of Range exception: " << e.what() << std::endl;
	}
}
//Logic Error: Domain Error.
double calculateSquareRoot(double number)
{
	if (number < 0)
	{
		throw std::domain_error("Cannot calculate square root of a negative number.");
	}

	//Logic Error: Domain Error.
	try
	{
		double result = sqrt(number);
		std::cout << "Square Root: " << result << std::endl;
	}
	catch (std::domain_error& e)
	{
		std::cout << "Domain Error Caught: " << e.what() << std::endl;
	}
}
double divideCheck(int a, int b)
{
		//Division by Zero.
		try
		{
			if (b == 0)
			{
				throw std::runtime_error("Division by zero is not allowed!");
			}

			std::cout << a / b;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception Caught: " << e.what() << std::endl;
		}
}
//Logic Error: Length Error.
void lengthCheck(std::vector<int>& v)
{
	try
	{
		v.reserve(v.max_size() + 1); // This will throw an exception
	}
	catch (const std::length_error& e)
	{
		std::cout << "Length Error: " << e.what() << std::endl;
	}
}
void futureCheck(std::future<int>& f)
{
	try
	{
		std::cout << "Future Result: " << f.get() << std::endl;
	}
	catch (const std::future_error& e)
	{
		std::cout << "Future Error: " << e.what() << std::endl;
	}
}
//Runtime Error: Overflow Error.
void overflowCheck(int a, int b)
{
	//if B is positive and A is greater than the maximum plus b.
	if (b > 0 && a > std::numeric_limits<int>::max() - b)
	{
		throw std::overflow_error("Integer overflow detected!");
	}
	
	try
	{
		int result = a + b;
		std::cout << "Result: " << result << std::endl;

	}
	catch (const std::overflow_error& e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
}
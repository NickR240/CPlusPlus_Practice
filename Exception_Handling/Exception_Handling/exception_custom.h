#pragma once

class CustomException : public std::runtime_error
{
public:
    CustomException()
        : std::runtime_error("Custom exception occurred.")
    {

    }

    explicit CustomException(const std::string& message)
        : std::runtime_error(message)
    {

    }
};

void invalidArgCheck(int age);
void outOfRangeCheck(const std::vector<int> v);
double calculateSquareRoot(double number);
double divideCheck(int a, int b);
void lengthCheck(std::vector<int>& v);
void futureCheck(std::future<int>& f);
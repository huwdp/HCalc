

#ifndef ISNUMERIC_H
#define ISNUMERIC_H
#include <vector>
#include <stack>
#include <string>
#include <stdexcept>

using namespace std;

static bool isNumeric(string input)
{
    try
    {
        std::stod(input);
    }
    catch (std::invalid_argument& e)
    {
        return false;
    }
    catch (const std::out_of_range e)
    {
        return false;
    }
    return true;
}

#endif // ISNUMERIC_H

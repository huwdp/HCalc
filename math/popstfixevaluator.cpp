/*
 * This file is part of HCalc. This file describes the methods for the Calculator class.
 *
 * Copyright (C) 2016 Huw Pritchard
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "postfixevaluator.h"

PostfixEvaluator::PostfixEvaluator()
{

}

double PostfixEvaluator::evaluate(std::vector<std::string> input)
{
    if (input.empty())
    {
        throw EmptyCalculation();
    }
    std::stack<std::string> operations;
    for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++)
    {
        std::string op = (*it);
        bool isNumber = stringTypeHelper.isNumeric(op);
        if (isNumber && op != "")
        {
            operations.push((*it));
        }
        else if (op == "(")
        {
            operations.push("(");
        }
        else if (operatorsList.getOperator(op) != nullptr)
        {
            if (operations.size() >= 2)
            {
                std::string operation1 = operations.top();
                operations.pop();
                std::string operation2 = operations.top();
                operations.pop();
                double result = calculateOperation(op, std::stod(operation2), std::stod(operation1));
                operations.push(std::to_string(result));
            }
            else
            {
                //throw InvalidCalculation();
            }
        }
    }
    std::string resultString = operations.top();
    double result = 0.0;
    try
    {
        return std::stod(resultString);
    }
    catch (std::exception& e)
    {
        throw e;
    }
    return result;
}

double PostfixEvaluator::calculateOperation(std::string op, double val1, double val2)
{
    if (op == "^")
    {
        return std::pow(val1, val2);
    }
    else if (op == "*")
    {
        return val1 * val2;
    }
    else if (op == "/")
    {
        return val1 / val2;
    }
    else if (op == "%")
    {
        return std::fmod(val1, val2);
    }
    else if (op == "+")
    {
        return val1 + val2;
    }
    else if (op == "-")
    {
        return val1 - val2;
    }
    else
    {
        return 0.0;
    }
}

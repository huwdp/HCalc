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

#include "infixtopostfix.h"

InfixToPostfix::InfixToPostfix(Operators *operatorsList)
{
    this->operatorsList = operatorsList;
}



std::vector<string> InfixToPostfix::convert(vector<string> input)
{
    //Example of what was used to write this code.
    // http://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
    // 2019-05-02

    std::stack<string> opStack;
    std::vector<string> postfix;
    for (vector<string>::iterator it = input.begin(); it != input.end(); it++)
    {
        string token = (*it);
        if (stringTypeHelper.isNumeric(token))
        {
            postfix.push_back(token);
        }
        else if (token == "(")
        {
            opStack.push(token);
        }
        else if (token == ")")
        {
            std::string topToken = opStack.top();
            opStack.pop();
            while (topToken != "(" && !opStack.empty())
            {
                postfix.push_back(topToken);
                topToken = opStack.top();
                opStack.pop();
            }
        }
        else
        {
            while (!opStack.empty() && operatorsList->getOperator(token)->getPrecedence() <= operatorsList->getOperator(opStack.top())->getPrecedence())
            {
               postfix.push_back(opStack.top());
               opStack.pop();
            }
            opStack.push(token);
        }
    }
    while (!opStack.empty())
    {
        postfix.push_back(opStack.top());
        opStack.pop();
    }
    return postfix;
}

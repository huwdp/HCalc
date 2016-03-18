/*
 * This file is part of HCalc. This file represents the method of the calculator class.
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

#include "calculator.h"

Calculator::Calculator()
{

}

string Calculator::calculate(string input)
{
    if (input != "")
    {
        vector<string> tokens = tokenizer(input);
        vector<string> postfix  = infixToPostfix(tokens);
        return postfixEvaluator(postfix);
    }
    return "Error";
}

bool Calculator::isNum(char input)
{
    if (input >= 'a' && input <= 'z')
        return true;
    if (input >= '0' && input <= '9')
        return true;
    if (input == '.')
        return true;
    return false;
}

int Calculator::isOperator(char input)
{
    switch (input)
    {
    case '/':
        return 3;
        break;
    case '*':
        return 3;
    case '-':
        return 2;
        break;
    case '+':
        return 2;
        break;
    case '{':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

vector<string> Calculator::tokenizer(string input)
{
    string token = "";
    vector<string> output;
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        if ((isNum((*it))))
        {
            token.push_back((*it));
        }
        else
        {
            if (token != "")
            {
                output.push_back(token);
            }
            string op = charToString((*it));
            if (op != "")
            {
                output.push_back(op);
            }
            token = "";
        }
    }

    if (token != "")
    {
        output.push_back(token);
    }

    return output;
}

vector<string> Calculator::infixToPostfix(vector<string> input)
{
    stack<char> operators;
    vector<string> postfix;
    for (vector<string>::iterator it = input.begin(); it != input.end(); it++)
    {
        char op = (*it).at(0);
        if ((isNumeric((*it))))
        {
            postfix.push_back((*it));
        }
        else if ((*it) == "(")
        {
            operators.push(op);
        }
        else if ((*it) == ")")
        {
            char operator2 = operators.top();
            operators.pop();
            while (!operators.empty() && operator2 != '(')
            {
                postfix.push_back(charToString(operator2));
                operator2 = operators.top();
                operators.pop();
            }
        }
        else
        {
            while (!operators.empty() && isOperator(operators.top()) >= isOperator(op))
            {
                postfix.push_back(charToString(operators.top()));
                operators.pop();
            }
            operators.push(op);
        }
    }
    while (!operators.empty())
    {
        postfix.push_back(charToString(operators.top()));
        operators.pop();
    }
    return postfix;
}

string Calculator::postfixEvaluator(vector<string> input)
{
    stack<string> operations;
    for (vector<string>::iterator it = input.begin(); it != input.end(); it++)
    {
        string item = (*it);
        char op = (*it).at(0);
        if (isNumeric(item) && item != "")
        {
            operations.push((*it));
        }
        else
        {
            if (operations.size() >= 2)
            {
                string operation1 = operations.top();
                operations.pop();
                string operation2 = operations.top();
                operations.pop();
                double result = calc(op, stod(operation2), stod(operation1));
                operations.push(to_string(result));
            }
            else
            {
                return "Error";
            }
        }
    }
    return operations.top();
}

double Calculator::calc(char op, double val1, double val2)
{
    switch (op)
    {
        case '+':
            return val1 + val2;
        break;
        case '-':
            return val1 - val2;
        break;
        case '*':
            return  val1 * val2;
        break;
        case '/':
            return val1 / val2;
        break;
        default:
            return 0.0;
        break;
    }
}


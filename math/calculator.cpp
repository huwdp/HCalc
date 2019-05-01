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

double Calculator::calculate(string input)
{
    if (input.size() == 0)
    {
        throw "Empty calculation.";
    }
    vector<string> tokens = generateTokens(input);
    InfixToPostfix infixToPostfix(&operatorsList);
    std::vector<string> postfix = infixToPostfix.convert(tokens);
    return postfixEvaluator.evaluate(postfix);
}

vector<string> Calculator::generateTokens(string input)
{
    vector<string> tokens;
    Tokens Tokens(input);
    while (!Tokens.isEnd())
    {
        tokens.push_back(Tokens.next());
    }
    return tokens;
}

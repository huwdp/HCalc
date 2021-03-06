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

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <stack>
#include <string>
#include <stdexcept>
#include <cmath>
#include "tokens.h"

#include "tokens.h"
#include "operators.h"

#include "exceptions.h"
#include "infixtopostfix.h"
#include "postfixevaluator.h"

class Calculator
{
private:
    Operators operatorsList;
    //Variables variables;
    //Functions functions;
    //vector<Instruction*> instructions;
    bool isNum(char input);

    PostfixEvaluator postfixEvaluator;
public:
    Calculator();
    double calculate(string input);
    vector<string> generateTokens(string input);
    double calculateOperation(string op, double val1, double val2);
};

#endif // CALCULATOR_H

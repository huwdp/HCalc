/*
 * This file is part of HCalc. This file represents the method of the mainwindow class.
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
#include "test.h"

Test::Test(std::string expression, double expected)
{
    this->expression = expression;
    this->expected = expected;
}

std::string Test::getExpression()
{
    return expression;
}

void Test::setExpression(std::string value)
{
    expression = value;
}

double Test::getExpected()
{
    return expected;
}

void Test::setExpected(double value)
{
    expected = value;
}

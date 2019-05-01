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
#include "operator.h"

Operator::Operator(std::string op, Direction direction, int precedence)
{
    this->op = op;
    this->direction = direction;
    this->precedence = precedence;
}

std::string Operator::getOperator()
{
    return op;
}

void Operator::setOperator(std::string op)
{
    this->op = op;
}

Direction Operator::getDirection()
{
    return direction;
}

void Operator::setDirection(Direction direction)
{
    this->direction = direction;
}

int Operator::getPrecedence()
{
    return precedence;
}

void Operator::setPrecedence(int precedence)
{
    this->precedence = precedence;
}

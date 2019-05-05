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
#include "operators.h"

Operators::Operators()
{
    operators.push_back(new Operator("^", RIGHT, 5));
    operators.push_back(new Operator("*", LEFT, 3));
    operators.push_back(new Operator("/", LEFT, 3));
    operators.push_back(new Operator("%", LEFT, 3));
    operators.push_back(new Operator("+", LEFT, 2));
    operators.push_back(new Operator("-", LEFT, 2));
    operators.push_back(new Operator("(", LEFT, 1));
}

Operators::~Operators()
{
    for (std::vector<Operator*>::iterator it = operators.begin(); it != operators.end(); ++it)
    {
        delete (*it);
        (*it) = nullptr;
    }
}

Operator *Operators::getOperator(std::string op)
{
    for (std::vector<Operator*>::iterator it = operators.begin(); it != operators.end(); ++it)
    {
        if ((*it)->getOperator() == op)
        {
            return (*it);
        }
    }
    return nullptr;
}

Operator *Operators::getOperator(char op)
{
    for (std::vector<Operator*>::iterator it = operators.begin(); it != operators.end(); ++it)
    {
        std::string operationName = (*it)->getOperator();
        if (!operationName.empty() && operationName.at(0) == op)
        {
            return (*it);
        }
    }
    return nullptr;
}

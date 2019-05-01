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
#include "tokens.h"

Tokens::Tokens(std::string expression)
{
    this->expression = expression;
    it = this->expression.begin();
}

char Tokens::peak()
{
    if (it != expression.end())
    {
        char temp = (*it++);
        it--;
        return temp;
    }
    return 0; // NULL
}

std::string Tokens::next()
{
    std::string output = "";
    while (it != expression.end())
    {
        char current = (*it);

        if (isDigit(current))
        {
            while (isDigit(current) && it != expression.end())
            {
                output.push_back(current);
                it++;
                current = (*it);
            }
            return output;
        }
        it++;
        return std::string(1, current);
    }
    return output;
}

bool Tokens::isEnd()
{
    if (it != expression.end())
    {
        return false;
    }
    return true;
}

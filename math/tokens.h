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
#ifndef Tokens_H
#define Tokens_H
#include <string>
#include "operators.h"

class Tokens
{
private:
    Operators operators;
    std::string::iterator it;
    std::string expression;
public:
    Tokens(std::string expression);
    char peak();
    std::string next();
    bool isEnd();
    bool isDigit(char a)
    {
        if (a >= '0' && a <= '9')
        {
            return true;
        }
        else if (a == '.')
        {
            return true;
        }
        return false;
    }
};

#endif // STRINGBUILDER_H

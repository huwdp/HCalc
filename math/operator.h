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
#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>

enum Direction {LEFT, RIGHT, NONE};

class Operator
{
private:
    std::string op;
    Direction direction;
    int precedence;
public:
    Operator(std::string op, Direction direction, int precedence);
    std::string getOperator();
    void setOperator(std::string op);
    Direction getDirection();
    void setDirection(Direction direction);
    int getPrecedence();
    void setPrecedence(int precedence);
};

#endif // OPERATOR_H

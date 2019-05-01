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
#include "testharness.h"

TestHarness::TestHarness()
{
    tests.push_back(new Test("11+2",13.0));
    tests.push_back(new Test("1*(9*2)",18.0));
    tests.push_back(new Test("1",1.000000));
    tests.push_back(new Test("1+(1+1)",3.0));
    tests.push_back(new Test("((1))",1.000000));
    tests.push_back(new Test("2*6+3-4/2-5+20/5*3+50",70));
    tests.push_back(new Test("(100/(90/2+5)*2+6*3)/2",11));
    tests.push_back(new Test("10^3",1000));
    tests.push_back(new Test("5.3%2",1.300000));
    tests.push_back(new Test("1/0", INFINITY));
}

TestHarness::~TestHarness()
{
    for (vector<Test*>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        delete (*it);
        (*it) = nullptr;
    }
}

vector<string> TestHarness::runAll()
{
    vector<string> results;
    for (vector<Test*>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        Calculator calculator;

        try
        {
            double answer = calculator.calculate((*it)->getExpression());

            if (answer == (*it)->getExpected() || answer == (int)((*it)->getExpected()))
            {
                string temp;
                temp.append("PASSED: ");
                temp.append((*it)->getExpression());
                temp.append(" ");
                temp.append(to_string((*it)->getExpected()));
                results.push_back(temp);
            }
            else
            {
                string temp;
                temp.append("FAILED: ");
                temp.append((*it)->getExpression());
                temp.append(" ");
                temp.append(to_string((*it)->getExpected()));
                temp.append(" , GOT:");
                temp.append(std::to_string(answer));
                results.push_back(temp);
            }
        }
        catch (std::exception &ex)
        {
            string temp;
            temp.append("FAILED: ");
            temp.append((*it)->getExpression());
            temp.append(" ");
            temp.append(to_string((*it)->getExpected()));
            temp.append(" , GOT:");
            temp.append(ex.what());
            results.push_back(temp);
        }

    }
    return results;
}

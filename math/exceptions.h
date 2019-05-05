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


#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

struct EmptyCalculation : public std::exception {
   const char * what () const throw () {
      return "Empty calculation";
   }
};

struct MismatchedParenthesis : public std::exception {
   const char * what () const throw () {
      return "Mismatched parenthesis";
   }
};


struct InvalidCalculation : public std::exception {
   const char * what () const throw () {
      return "Invalid calculation";
   }
};

struct InvalidCharacters : public std::exception {
   const char * what () const throw () {
      return "Invalid characters";
   }
};

#endif // EXCEPTIONS_H

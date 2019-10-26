/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:13:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 13:13:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char *UsageException::what() const noexcept
{
	return "usage:\t./avm [file]";
}

const char *InvalidFile::what() const noexcept
{
	return "Invalid file: ";
}

const char *DoubleSemicolon::what() const noexcept
{
	return "Missing ';;' at the end of input";
}

const char *NoExpressions::what() const noexcept
{
	return "No expressions to analyze";
}

const char *InvalidExpression::what() const noexcept
{
	return "Invalid expression";
}

const char *InvalidInstruction::what() const noexcept
{
	return "Invalid instruction";
}

const char *InvalidInstructionValue::what() const noexcept
{
	return "Invalid instruction value";
}

const char *MissingValue::what() const noexcept
{
	return "Instruction missing value";
}

const char *OverflowValue::what() const noexcept
{
	return "Value overflow";
}

const char *UnderflowValue::what() const noexcept
{
	return "Value underflow";
}

const char *PopEmpty::what() const noexcept
{
	return "Pop on empty stack";
}

const char *DumpEmpty::what() const noexcept
{
	return "Dump on empty stack";
}

const char *AssertEmpty::what() const noexcept
{
	return "Assert on empty stack";
}

const char *AssertFail::what() const noexcept
{
	return "Assert fails";
}

const char *AddEmpty::what() const noexcept
{
	return "Addition operation with empty stack";
}

const char *AddOnlyOne::what() const noexcept
{
	return "Addition operation with one value";
}

const char *SubEmpty::what() const noexcept
{
	return "Subtraction operation with empty stack";
}

const char *SubOnlyOne::what() const noexcept
{
	return "Subtraction operation with one value";
}

const char *MulEmpty::what() const noexcept
{
	return "Multiplication operation with empty stack";
}

const char *MulOnlyOne::what() const noexcept
{
	return "Multiplication operation with one value";
}

const char *DivEmpty::what() const noexcept
{
	return "Division operation with empty stack";
}

const char *DivOnlyOne::what() const noexcept
{
	return "Division operation with one value";
}

const char *ModEmpty::what() const noexcept
{
	return "Modulo operation with empty stack";
}

const char *ModOnlyOne::what() const noexcept
{
	return "Modulo operation with one value";
}

const char *DivZero::what() const noexcept
{
	return "Division by 0";
}

const char *ModZero::what() const noexcept
{
	return "Modulo by 0";
}

const char *PrintEmpty::what() const noexcept
{
	return "Print empty stack";
}

const char *PrintAssert::what() const noexcept
{
	return "Top of the stack is not int8";
}

const char *ExitMultiple::what() const noexcept
{
	return "Multiple exit instructions";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 11:02:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

IOperand const *
OperandFactory::newOperand(eOperandType type, std::string const &value)
{
	static OperandFactory factory;
	return factory.createOperand(type, value);
}

IOperand const *
OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
	static IOperand const *
	(OperandFactory::*create[])(std::string const &) const = {
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble};
	return (this->*(create[type]))(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
	return new Operand<long long>(SCHAR_MIN, SCHAR_MAX, value, Int8);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const
{
	return new Operand<long long>(SHRT_MIN, SHRT_MAX, value, Int16);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const
{
	return new Operand<long long>(INT_MIN, INT_MAX, value, Int32);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const
{
	return new Operand<long double>(-FLT_MAX, FLT_MAX, value, Float);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const
{
	return new Operand<long double>(-DBL_MAX, DBL_MAX, value, Double);
}

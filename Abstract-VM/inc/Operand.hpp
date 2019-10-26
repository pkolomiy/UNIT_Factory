/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:23:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/25 18:23:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "OperandFactory.hpp"

template<typename T>
class Operand : public IOperand
{
public:
	explicit Operand<T>(T min, T max, std::string value, eOperandType type) :
	strValue(std::move(value)), type(type)
	{
		T nbrValue = type < Float ? std::stoll(strValue) : std::stold(strValue);
		if (nbrValue > max)
			throw OverflowValue();
		else if (nbrValue < min)
			throw UnderflowValue();
	}

	Operand() = delete;

	Operand(Operand const &rhs) = delete;

	~Operand() override = default;

	Operand &operator=(Operand const &rhs) = delete;

	eOperandType getType() const override
	{
		return this->type;
	}

	std::string const &toString() const override
	{
		return this->strValue;
	};

	int getPrecision() const override
	{
		return this->type;
	};

	IOperand const *operator+(IOperand const &rhs) const override
	{
		eOperandType newType = type > rhs.getType() ? type : rhs.getType();
		std::string result = newType > Int32 ?
		std::to_string(std::stold(toString()) + std::stold(rhs.toString())) :
		std::to_string(std::stoll(toString()) + std::stoll(rhs.toString()));
		return OperandFactory::newOperand(newType, result);
	};

	IOperand const *operator-(IOperand const &rhs) const override
	{
		eOperandType newType = type > rhs.getType() ? type : rhs.getType();
		std::string result = newType > Int32 ?
		std::to_string(std::stold(toString()) - std::stold(rhs.toString())) :
		std::to_string(std::stoll(toString()) - std::stoll(rhs.toString()));
		return OperandFactory::newOperand(newType, result);
	};

	IOperand const *operator*(IOperand const &rhs) const override
	{
		eOperandType newType = type > rhs.getType() ? type : rhs.getType();
		std::string result = newType > Int32 ?
		std::to_string(std::stold(toString()) * std::stold(rhs.toString())) :
		std::to_string(std::stoll(toString()) * std::stoll(rhs.toString()));
		return OperandFactory::newOperand(newType, result);
	};

	IOperand const *operator/(IOperand const &rhs) const override
	{
		eOperandType newType = type > rhs.getType() ? type : rhs.getType();
		if (checkForZero(newType, rhs.toString()))
			throw DivZero();
		std::string result = newType > Int32 ?
		std::to_string(std::stold(toString()) / std::stold(rhs.toString())) :
		std::to_string(std::stoll(toString()) / std::stoll(rhs.toString()));
		return OperandFactory::newOperand(newType, result);
	};

	IOperand const *operator%(IOperand const &rhs) const override
	{
		eOperandType newType = type > rhs.getType() ? type : rhs.getType();
		if (checkForZero(newType, rhs.toString()))
			throw ModZero();
		std::string result = newType > Int32 ?
		std::to_string(
		fmod(std::stold(toString()), std::stold(rhs.toString()))) :
		std::to_string(std::stoll(toString()) % std::stoll(rhs.toString()));
		return OperandFactory::newOperand(newType, result);
	};

private:
	std::string strValue;
	const eOperandType type;

	bool
	checkForZero(eOperandType const newType, std::string const &value) const
	{
		if (newType > Int32)
			return std::stold(value) == 0.0;
		return std::stoll(value) == 0;
	}
};

#endif

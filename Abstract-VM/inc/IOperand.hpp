/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:00:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/23 20:00:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include "Lexer.hpp"

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double,
};

class IOperand
{
public:
	virtual int getPrecision() const = 0;

	virtual eOperandType getType() const = 0;

	virtual IOperand const *operator+(IOperand const &rhs) const = 0;

	virtual IOperand const *operator-(IOperand const &rhs) const = 0;

	virtual IOperand const *operator*(IOperand const &rhs) const = 0;

	virtual IOperand const *operator/(IOperand const &rhs) const = 0;

	virtual IOperand const *operator%(IOperand const &rhs) const = 0;

	virtual std::string const &toString() const = 0;

	virtual ~IOperand() = default;
};

#endif

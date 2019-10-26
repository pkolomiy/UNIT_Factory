/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:02:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 11:02:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include "IOperand.hpp"

class OperandFactory
{
public:
	static IOperand const *
	newOperand(eOperandType type, std::string const &value);

private:
	IOperand const *
	createOperand(eOperandType type, std::string const &value) const;

	IOperand const *createInt8(std::string const &value) const;

	IOperand const *createInt16(std::string const &value) const;

	IOperand const *createInt32(std::string const &value) const;

	IOperand const *createFloat(std::string const &value) const;

	IOperand const *createDouble(std::string const &value) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:13:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 13:13:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class UsageException : public std::exception
{
public:
	const char *what() const noexcept override;
};

class InvalidFile : public std::exception
{
public:
	const char *what() const noexcept override;
};

class DoubleSemicolon : public std::exception
{
public:
	const char *what() const noexcept override;
};

class NoExpressions : public std::exception
{
public:
	const char *what() const noexcept override;
};

class InvalidExpression : public std::exception
{
public:
	const char *what() const noexcept override;
};

class InvalidInstruction : public std::exception
{
public:
	const char *what() const noexcept override;
};

class InvalidInstructionValue : public std::exception
{
public:
	const char *what() const noexcept override;
};

class MissingValue : public std::exception
{
public:
	const char *what() const noexcept override;
};

class OverflowValue : public std::exception
{
public:
	const char *what() const noexcept override;
};

class UnderflowValue : public std::exception
{
public:
	const char *what() const noexcept override;
};

class PopEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class DumpEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class AssertEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class AssertFail : public std::exception
{
public:
	const char *what() const noexcept override;
};

class AddEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class AddOnlyOne : public std::exception
{
public:
	const char *what() const noexcept override;
};

class SubEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class SubOnlyOne : public std::exception
{
public:
	const char *what() const noexcept override;
};

class MulEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class MulOnlyOne : public std::exception
{
public:
	const char *what() const noexcept override;
};

class DivEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class DivOnlyOne : public std::exception
{
public:
	const char *what() const noexcept override;
};

class ModEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class ModOnlyOne : public std::exception
{
public:
	const char *what() const noexcept override;
};

class DivZero : public std::exception
{
public:
	const char *what() const noexcept override;
};

class ModZero : public std::exception
{
public:
	const char *what() const noexcept override;
};

class PrintEmpty : public std::exception
{
public:
	const char *what() const noexcept override;
};

class PrintAssert : public std::exception
{
public:
	const char *what() const noexcept override;
};

class ExitMultiple : public std::exception
{
public:
	const char *what() const noexcept override;
};

#endif

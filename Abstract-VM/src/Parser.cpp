/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/23 19:53:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

std::map<std::string, eOperandType> Parser::types = {
{"int8",   Int8},
{"int16",  Int16},
{"int32",  Int32},
{"float",  Float},
{"double", Double}};

Parser::Parser(Lexer &lexer) : hasErrors(false), haveExit(false)
{
	if (lexer.hasErrors)
	{
		Lines temp = lexer.getLines();
		for (auto &line : temp)
			if (line.error.empty())
				this->lines.emplace_back(line);
	}
	else
		this->lines = lexer.getLines();

	for (auto &line : this->lines)
		this->parseLine(line);
	if (!this->haveExit)
	{
		this->hasErrors = true;
		Line exitError(0, "");
		exitError.error = "Missing exit instruction";
		this->lines.emplace_back(exitError);
	}
}

Parser::~Parser()
{
	for (auto operand : this->operands)
		delete operand;
	this->operands.clear();
}

Lines Parser::getLines()
{
	return this->lines;
}

std::string Parser::getDump()
{
	return this->dumpAndPrint.str();
}

void Parser::parseLine(Line &line)
{
	static std::map<std::string, void (Parser::*)(Line &)> instructions = {
	{"push",   &Parser::push},
	{"pop",    &Parser::pop},
	{"dump",   &Parser::dump},
	{"assert", &Parser::myAssert},
	{"add",    &Parser::add},
	{"sub",    &Parser::sub},
	{"mul",    &Parser::mul},
	{"div",    &Parser::div},
	{"mod",    &Parser::mod},
	{"print",  &Parser::print},
	{"exit",   &Parser::exit}};

	try
	{
		(this->*(instructions[line.instruction]))(line);
	}
	catch (std::exception &e)
	{
		std::stringstream sstm;
		sstm << "Parser error on line " << line.number << ": " << e.what();
		line.error = sstm.str();
		this->hasErrors = true;
	}
}

void Parser::push(Line &line)
{
	std::size_t start = line.value.find('(');
	std::size_t end = line.value.find(')') - start;
	std::string type = line.value.substr(0, start);
	std::string value = line.value.substr(start + 1, end - 1);

	this->operands.emplace_back(OperandFactory::newOperand(types[type], value));
}

void Parser::pop(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw PopEmpty();
	this->operands.pop_back();
}

void Parser::dump(Line &line)
{
	(void)line;

	if (this->hasErrors)
		return;
	if (this->operands.empty())
		throw DumpEmpty();
	for (auto op = this->operands.rbegin(); op != this->operands.rend(); ++op)
		this->dumpAndPrint << (*op)->toString() << std::endl;
}

void Parser::myAssert(Line &line)
{
	if (this->operands.empty())
		throw AssertEmpty();

	std::size_t start = line.value.find('(');
	std::size_t end = line.value.find(')') - start;
	std::string type = line.value.substr(0, start);
	std::string value = line.value.substr(start + 1, end - 1);

	const IOperand *operand = OperandFactory::newOperand(types[type], value);

	bool assertSuccess =
	operand->getType() == this->operands.back()->getType() &&
	operand->toString() == this->operands.back()->toString();

	delete (operand);

	if (!assertSuccess)
		throw AssertFail();
}

void Parser::add(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw AddEmpty();
	if (this->operands.size() < 2)
		throw AddOnlyOne();
	IOperand const *first = this->operands.back();
	this->operands.pop_back();
	IOperand const *second = this->operands.back();
	this->operands.pop_back();
	this->operands.emplace_back(*second + *first);
	delete (first);
	delete (second);
}

void Parser::sub(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw SubEmpty();
	if (this->operands.size() < 2)
		throw SubOnlyOne();
	IOperand const *first = this->operands.back();
	this->operands.pop_back();
	IOperand const *second = this->operands.back();
	this->operands.pop_back();
	this->operands.emplace_back(*second - *first);
	delete (first);
	delete (second);
}

void Parser::mul(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw MulEmpty();
	if (this->operands.size() < 2)
		throw MulOnlyOne();
	IOperand const *first = this->operands.back();
	this->operands.pop_back();
	IOperand const *second = this->operands.back();
	this->operands.pop_back();
	this->operands.emplace_back(*second * *first);
	delete (first);
	delete (second);
}

void Parser::div(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw DivEmpty();
	if (this->operands.size() < 2)
		throw DivOnlyOne();
	IOperand const *first = this->operands.back();
	this->operands.pop_back();
	IOperand const *second = this->operands.back();
	this->operands.pop_back();
	this->operands.emplace_back(*second / *first);
	delete (first);
	delete (second);
}

void Parser::mod(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw ModEmpty();
	if (this->operands.size() < 2)
		throw ModOnlyOne();
	IOperand const *first = this->operands.back();
	this->operands.pop_back();
	IOperand const *second = this->operands.back();
	this->operands.pop_back();
	this->operands.emplace_back(*second % *first);
	delete (first);
	delete (second);
}

void Parser::print(Line &line)
{
	(void)line;

	if (this->operands.empty())
		throw PrintEmpty();
	if (this->operands.back()->getType() != Int8)
		throw PrintAssert();
	if (this->hasErrors)
		return;
	this->dumpAndPrint
	<< static_cast<char>(std::stoll(this->operands.back()->toString()))
	<< std::endl;
}

void Parser::exit(Line &line)
{
	(void)line;

	if (this->haveExit)
		throw ExitMultiple();
	this->haveExit = true;
}


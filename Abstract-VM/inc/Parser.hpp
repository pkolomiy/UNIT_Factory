/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:53:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/23 19:53:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Operand.hpp"

class Parser
{
public:
	bool hasErrors;
	static std::map<std::string, eOperandType> types;

	explicit Parser(Lexer &lexer);

	~Parser();

	Lines getLines();

	std::string getDump();

	Parser() = delete;

	Parser(Parser const &rhs) = delete;

	Parser &operator=(Parser const &rhs) = delete;

private:
	bool haveExit;
	Lines lines;
	std::stringstream dumpAndPrint;
	std::vector<IOperand const *> operands;

	void parseLine(Line &line);

	void push(Line &line);

	void pop(Line &line);

	void dump(Line &line);

	void myAssert(Line &line);

	void add(Line &line);

	void sub(Line &line);

	void mul(Line &line);

	void div(Line &line);

	void mod(Line &line);

	void print(Line &line);

	void exit(Line &line);
};

#endif

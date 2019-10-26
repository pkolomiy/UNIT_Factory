/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:45:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/23 19:45:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "Reader.hpp"

class Lexer
{
public:
	bool hasErrors;

	explicit Lexer(Reader &reader);

	Lines getLines();

	Lexer() = delete;

	Lexer(Lexer const &rhs) = delete;

	~Lexer() = default;

	Lexer &operator=(Lexer const &rhs) = delete;

private:
	Lines lines;

	static bool isComment(const std::string &line);

	bool validLine(Line &line);

	static void stripFromComment(std::string &line);

	static Strings splitLine(const std::string &line);

	static void validateInstruction(Strings results);

	static bool validInstructionValue(Strings results);
};

#endif

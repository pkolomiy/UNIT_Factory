/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:45:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/23 19:45:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer(Reader &reader) : hasErrors(false)
{
	Lines rawLines = reader.getLines();

	for (auto &rawLine : rawLines)
	{
		if (rawLine.instruction.empty() || isComment(rawLine.instruction))
			continue;
		if (this->validLine(rawLine))
			this->lines.emplace_back(rawLine);
	}
}

bool Lexer::isComment(const std::string &line)
{
	return std::regex_match(line, std::regex("^[ ]*?;.*$"));
}

std::vector<Line> Lexer::getLines()
{
	return this->lines;
}

bool Lexer::validLine(Line &line)
{
	try
	{
		stripFromComment(line.instruction);
		Strings split = splitLine(line.instruction);
		if (split.empty())
			return false;

		validateInstruction(split);
		line.instruction = split[0];

		if (validInstructionValue(split))
			line.value = split[1];
	}
	catch (std::exception &e)
	{
		std::stringstream sstm;
		sstm << "Lexical error on line " << line.number << ": " << e.what();
		line.error = sstm.str();
		this->hasErrors = true;
	}
	return true;
}

void Lexer::stripFromComment(std::string &line)
{
	std::size_t comment = line.find(';');
	if (comment != std::string::npos)
		line.erase(comment);
}

Strings Lexer::splitLine(const std::string &line)
{
	std::istringstream iss(line);
	Strings results(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());
	return results;
}

void Lexer::validateInstruction(Strings results)
{
	if (results.size() > 2)
		throw InvalidExpression();

	std::string expr = "^(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)$";
	if (!std::regex_match(results[0], std::regex(expr)))
		throw InvalidInstruction();
}

bool Lexer::validInstructionValue(Strings results)
{
	if (!std::regex_match(results[0], std::regex("^(push|assert)$")))
		return false;

	if (results.size() == 1)
		throw MissingValue();

	std::string expr = R"(^(int(8|16|32)\((0|[-]?[1-9][0-9]*?)\)|(float|double)\(([-]?0|[-]?[1-9][0-9]*?)\.[0-9]+\))$)";
	if (!std::regex_match(results[1], std::regex(expr)))
		throw InvalidInstructionValue();
	return true;
}

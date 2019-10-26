/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:38:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 20:38:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader(int argc, char **argv)
{
	if (argc > 2)
		throw UsageException();
	if (argc == 1)
		this->read_stdin();
	else
	{
		std::ifstream file(argv[1]);
		if (file.is_open() && file.get() && file.good())
			this->read_file(file);
		else
			throw InvalidFile();
	}
}

Lines Reader::getLines()
{
	return this->lines;
}

void Reader::read_stdin()
{
	std::string str;
	bool doubleSemicolon = false;
	int lineNumber = 1;

	while (!std::cin.eof())
	{
		std::getline(std::cin, str);
		if (str == ";;")
		{
			doubleSemicolon = true;
			break;
		}
		this->lines.emplace_back(Line(lineNumber, str));
		lineNumber++;
	}
	if (!doubleSemicolon)
		throw DoubleSemicolon();
	else if (this->lines.empty())
		throw NoExpressions();
}

void Reader::read_file(std::istream &file)
{
	std::string str;
	int lineNumber = 1;
	file.clear();
	file.seekg(0, std::ios::beg);

	while (!file.eof())
	{
		std::getline(file, str);
		this->lines.emplace_back(Line(lineNumber, str));
		lineNumber++;
	}

	if (this->lines.empty())
		throw NoExpressions();
}


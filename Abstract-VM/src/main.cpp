/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:49:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/26 16:49:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void showErrors(Lines lines)
{
	for (auto &line : lines)
	{
		if (!line.error.empty())
		{
			std::cout << line.error << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	try
	{
		Reader reader(argc, argv);
		Lexer lexer(reader);
		Parser parser(lexer);
		if (lexer.hasErrors || parser.hasErrors)
		{
			showErrors(lexer.getLines());
			showErrors(parser.getLines());
		}
		else if (!parser.getDump().empty())
		{
			std::cout << parser.getDump();
		}
	}
	catch (InvalidFile &e)
	{
		std::cout << e.what() << argv[1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

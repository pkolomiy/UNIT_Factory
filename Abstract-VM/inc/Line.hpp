/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:51:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/25 13:51:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_HPP
#define LINE_HPP

#include "header.h"

class Line
{
public:
	int number;
	std::string instruction;
	std::string value;
	std::string error;

	Line(int lineNumber, std::string content);

	Line() = delete;

	Line(Line const &rhs) = default;

	~Line() = default;

	Line &operator=(Line const &rhs)= default;
};

#endif

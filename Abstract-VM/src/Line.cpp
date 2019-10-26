/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:51:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/25 13:51:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Line.hpp"

Line::Line(int lineNumber, std::string content) :
number(lineNumber), instruction(std::move(content))
{
}

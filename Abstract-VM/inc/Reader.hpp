/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:38:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/10/24 20:38:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
#define READER_HPP

#include "Line.hpp"

class Reader
{
public:
	Reader(int argc, char **argv);

	Lines getLines();

	~Reader() = default;

	Reader() = delete;

	Reader(Reader const &rhs) = delete;

	Reader &operator=(Reader const &rhs) = delete;

private:
	Lines lines;

	void read_stdin();

	void read_file(std::istream &file);
};

#endif

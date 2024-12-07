/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:59 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/07 12:37:16 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{

}

AMateria::~AMateria(void)
{

}

AMateria::AMateria(std::string const &type)
	: _type(type)
{

}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}

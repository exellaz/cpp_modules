/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:39 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 15:15:06 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{

}

Cure::~Cure(void)
{

}

Cure::Cure(Cure &src) : AMateria("cure")
{
	*this = src;
}

Cure	&Cure::operator=(Cure &src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
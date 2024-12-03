/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:52:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:08:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->_type = "Unknown";
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(AAnimal &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << this->_type << ": *unintelligible sounds*" << std::endl;
}

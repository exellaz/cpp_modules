/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:52:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/27 21:49:36 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(Animal &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << ": *unintelligible sounds*" << std::endl;
}

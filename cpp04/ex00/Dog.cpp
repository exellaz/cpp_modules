/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:51:25 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/27 22:06:57 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(Dog &src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": *woof*" << std::endl;
}

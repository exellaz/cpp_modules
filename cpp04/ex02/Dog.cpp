/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:51:25 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:11:34 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete (this->_brain);
}

Dog::Dog(Dog &src) : AAnimal(src), _brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(Dog &src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_type = src.getType();
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": *woof*" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

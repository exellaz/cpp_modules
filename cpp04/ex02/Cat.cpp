/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:55:31 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:11:39 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->_brain);
}

Cat::Cat(Cat &src) : AAnimal(src), _brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(Cat &src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_type = src.getType();
		this->_brain = new Brain(*src.getBrain());
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": *meow*" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

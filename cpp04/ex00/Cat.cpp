/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:55:31 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/27 22:07:15 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(Cat &src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": *meow*" << std::endl;
}

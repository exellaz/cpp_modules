/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:18:00 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/04 15:51:53 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _recipeSlots; i++)
		this->_recipes[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _recipeSlots; i++)
	{
		if (this->_recipes != NULL)
			delete (this->_recipes[i]);
	}
}

MateriaSource::MateriaSource(MateriaSource &src)
{
	*this = src;
}

MateriaSource	&MateriaSource::operator=(MateriaSource &src)
{
	AMateria	**srcRecipes = src.getRecipes();

	if (this != &src)
	{
		for (int i = 0; i < _recipeSlots; i++)
		{
			if (this->_recipes[i] != NULL)
				delete (this->_recipes[i]);
		}
		for (int i = 0; i < _recipeSlots; i++)
		{
			if (srcRecipes[i] != NULL)
				this->_recipes[i] = srcRecipes[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "MateriaSource: Materia does not exist!" << std::endl;
		return ;
	}
	for (int i = 0; i < _recipeSlots; i++)
	{
		if (this->_recipes[i] == NULL)
		{
			this->_recipes[i] = m;
			std::cout << "MateriaSource: " << "Learned the " << m->getType()
					<< " materia recipe" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource: Can't learn any more recipes" << std::endl;
	delete (m);
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < _recipeSlots; i++)
	{
		if (this->_recipes[i] != NULL && this->_recipes[i]->getType() == type)
		{
			std::cout << "MateriaSource: Creating " << type << " materia" << std::endl;
			return (this->_recipes[i]->clone());
		}
	}
	std::cout << "MateriaSource: Recipe of " << type << " not learned yet" << std::endl;
	return (NULL);
}

AMateria	**MateriaSource::getRecipes(void)
{
	return (this->_recipes);
}
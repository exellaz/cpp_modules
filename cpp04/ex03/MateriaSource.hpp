/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:18:06 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 15:55:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		const static int	_recipeSlots = 4;
		AMateria			*_recipes[_recipeSlots];

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource &src);
		MateriaSource	&operator=(MateriaSource &src);
		void			learnMateria(AMateria *m);
		AMateria		*createMateria(const std::string &type);
		AMateria		**getRecipes(void);
};

#endif
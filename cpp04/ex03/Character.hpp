/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:50:18 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 14:59:29 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
	private:
		std::string			_name;
		const static int	_inventorySize = 4;
		AMateria			*_inventory[_inventorySize];

	public:
		Character(std::string name);
		~Character(void);
		Character(Character &src);
		Character &operator=(Character &src);
		const std::string	&getName(void) const;
		AMateria			**getInventory(void);
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
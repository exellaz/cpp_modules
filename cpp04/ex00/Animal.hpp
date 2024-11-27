/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:50:17 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/27 21:46:52 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		~Animal(void);
		Animal(Animal &src);
		Animal		&operator=(Animal &src);
		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif

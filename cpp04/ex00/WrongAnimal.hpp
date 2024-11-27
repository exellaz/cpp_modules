/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:07 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/27 21:58:41 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal &src);
		WrongAnimal		&operator=(WrongAnimal &src);
		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif

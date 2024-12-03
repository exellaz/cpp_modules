/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:50:37 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:10:42 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Dog(void);
		~Dog(void);
		Dog(Dog &src);
		Dog				&operator=(Dog &src);
		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
};

#endif

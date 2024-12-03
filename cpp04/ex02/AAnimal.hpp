/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:50:17 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:14:07 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(AAnimal &src);
		AAnimal		&operator=(AAnimal &src);
		std::string	getType(void) const;
		virtual void		makeSound(void) const = 0;
};

#endif

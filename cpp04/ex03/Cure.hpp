/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:41 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 15:14:12 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(Cure &src);
		Cure			&operator=(Cure &src);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
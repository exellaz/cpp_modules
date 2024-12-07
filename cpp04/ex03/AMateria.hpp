/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:28:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/07 12:37:08 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		virtual	~AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		AMateria			&operator=(AMateria const &src);
		const std::string	&getType(void) const;
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;
};

#endif
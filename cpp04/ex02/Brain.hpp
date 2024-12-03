/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:25:48 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/29 13:18:13 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(Brain &src);
		Brain				&operator=(Brain &src);
		std::string	const	&getIdea(int index) const;
		void				setIdea(std::string idea);
};

#endif

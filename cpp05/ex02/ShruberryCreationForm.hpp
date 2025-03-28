/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:18:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/28 14:23:07 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include <sstream>
# include <fstream>

class ShruberryCreationForm : public AForm
{
	public:
		ShruberryCreationForm();
		ShruberryCreationForm(const std::string &target);
		ShruberryCreationForm(const ShruberryCreationForm &src);
		ShruberryCreationForm	&operator=(const ShruberryCreationForm &src);
		~ShruberryCreationForm();

		virtual void	action() const;
};

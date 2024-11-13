/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:44:09 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/13 16:13:53 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
	private:
		Contact	_contact_array[8];
		int		_index;
		std::string	_truncate(std::string str);

	public:
		PhoneBook(void);
		void	add_contact(void);
		std::string	trim_whitespace(std::string str);
		void	get_input(std::string prompt, std::string &str);
		void	display_contact_table(void);


};

#endif

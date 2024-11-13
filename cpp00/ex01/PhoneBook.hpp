/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:44:09 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/13 20:02:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

# define MAX_CELL_WIDTH 20

class PhoneBook
{
	private:
		Contact	_contact_array[8];
		int		_index;
		std::string	_truncate(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		std::string	trim_whitespace(std::string str);
		void	get_input(std::string prompt, std::string &str);
		void	display_contact_table(void);
		void	search_contact(void);


};

#endif

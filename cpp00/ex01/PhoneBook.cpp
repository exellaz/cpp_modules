/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:43:56 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/14 19:03:41 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::_truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	else
		return(str);
}

std::string	PhoneBook::trim_whitespace(std::string str)
{
	std::string	whitespace	= " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(whitespace);
	end = str.find_last_not_of(whitespace);
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

void	PhoneBook::get_input(std::string prompt, std::string &str)
{
	str = "";
	while (str == "")
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, str);
		str = trim_whitespace(str);
	}
}

void	PhoneBook::add_contact(void)
{
	std::string	input;
	Contact	t_contact;

	// get_input("Enter your first name:", input);
	// _contact_array[this->_index].set_first_name(input);
	// get_input("Enter your last name:", input);
	// _contact_array[this->_index].set_last_name(input);
	// get_input("Enter your nickname:", input);
	// _contact_array[this->_index].set_nickname(input);
	// get_input("Enter your phone number:", input);
	// _contact_array[this->_index].set_phone_number(input);
	// get_input("Enter your darkest secret:", input);
	// _contact_array[this->_index].set_secret(input);
	if (set_contact_details(t_contact) == false)
		return ;
	_contact_array[this->_index] = t_contact;
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	std::cout << "Contact added Successfully" << std::endl;
	wait_for_enter();
}

bool PhoneBook::set_contact_details(Contact &t_contact)
{
	if (parse_and_set_input("Enter first name: ", t_contact, &Contact::set_first_name) == false)
		return (false);
	if (parse_and_set_input("Enter last name: ", t_contact, &Contact::set_last_name) == false)
		return (false);
	if (parse_and_set_input("Enter nick name: ", t_contact, &Contact::set_nickname) == false)
		return (false);
	if (parse_and_set_input("Enter phone number: ", t_contact, &Contact::set_phone_number) == false)
		return (false);
	if (parse_and_set_input("Enter dark secret: ", t_contact, &Contact::set_secret) == false)
		return (false);
	return (true);
}

bool PhoneBook::parse_and_set_input(std::string prompt, Contact &t_contact, void (Contact::*func)(std::string))
{
	std::string input;

	while (1)
	{
		get_input(prompt, input);
		if (std::cin.eof())
			exit(0);
		else if (input == "BACK")
		{
			std::cout << "Contact not added" << std::endl;
			wait_for_enter();
			return (false);
		}
		else
		{
			(t_contact.*func)(input);
			break;
		}
	}
	return (true);
}

void	PhoneBook::display_contact_table(void)
{
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact_array[i].get_first_name() == "")
			break ;
		else
		{
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << i + 1;
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_first_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_last_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_nickname());
			std::cout << std::setw(1) << "|" << std::endl;
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		}
	}
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	size_t		index;

	while (1)
	{
		display_contact_table();
		std::cout << "Enter BACK to return to main menu." << std::endl;
		std::cout << "Enter index to display contact [1 - 8]: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		index = input[0] - '0' - 1;
		system("clear");
		if (input == "BACK")
			return ;
		else if (input.length() != 1 || index > 7)
		{
			std::cout << "Invalid index! Please enter a digit from 1 to 8." << std::endl;
		}
		else if (this->_contact_array[index].get_first_name() == "")
		{
			std::cout << "No record at index [" << index + 1 << "]. ADD a contact and try again." << std::endl;
		}
		else
		{
			std::cout << "----------CONTACT ["<< index + 1 << "]----------" << std::endl;
			std::cout << "First Name    : " << this->_contact_array[index].get_first_name() << std::endl;
			std::cout << "Last Name     : " << this->_contact_array[index].get_last_name() << std::endl;
			std::cout << "Nickname      : " << this->_contact_array[index].get_nickname() << std::endl;
			std::cout << "Phone Number  : " << this->_contact_array[index].get_phone_number() << std::endl;
			std::cout << "Darkest Secret: " << this->_contact_array[index].get_secret() << std::endl << std::endl;
			wait_for_enter();
			return ;
		}
		wait_for_enter();
	}

}

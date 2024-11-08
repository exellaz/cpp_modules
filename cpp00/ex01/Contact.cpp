/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:07 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/08 15:26:04 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_secret(std::string secret)
{
	this->_secret = secret;
}

std::string	Contact::get_first_name(std::string first_name)
{
	return (first_name);
}

std::string	Contact::get_last_name(std::string last_name)
{
	return (last_name);
}

std::string	Contact::get_nickname(std::string nickname)
{
	return (nickname);
}

std::string	Contact::get_phone_number(std::string phone_number)
{
	return (phone_number);
}

std::string	Contact::get_secret(std::string secret)
{
	return (secret);
}

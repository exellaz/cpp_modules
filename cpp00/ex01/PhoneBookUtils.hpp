/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:39 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/15 13:54:49 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_H
# define PHONEBOOK_UTILS_H

void		display_welcome(void);
void		display_menu_and_prompt(std::string &input);
void		wait_for_enter(void);
void		get_input(std::string prompt, std::string &str);
std::string	truncate(std::string str);
std::string	trim_whitespace(std::string str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imoulasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:52:40 by imoulasr          #+#    #+#             */
/*   Updated: 2025/03/29 08:52:41 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     count;
    int     oldest;

    void displayField(const std::string &field) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact &contact);
    
    void displayContacts() const;
    
    void displayContact(int index) const;
    
    int getCount() const;
};

#endif
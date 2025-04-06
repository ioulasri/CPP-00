/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imoulasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:52:45 by imoulasr          #+#    #+#             */
/*   Updated: 2025/03/29 08:52:46 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(const Contact &contact)
{
    this->contacts[this->oldest] = contact;
    this->oldest = (this->oldest + 1) % 8;
    if (this->count < 8)
        this->count++;
}

void PhoneBook::displayField(const std::string &field) const
{
    if (field.length() > 10)
        std::cout << field.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << field;
}

void PhoneBook::displayContacts() const
{
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    
    for (int i = 0; i < this->count; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        this->displayField(this->contacts[i].getFirstName());
        std::cout << "|";
        this->displayField(this->contacts[i].getLastName());
        std::cout << "|";
        this->displayField(this->contacts[i].getNickname());
        std::cout << "|" << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= this->count)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    
    std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getCount() const
{
    return this->count;
}
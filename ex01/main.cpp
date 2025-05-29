/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imoulasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:51:42 by imoulasr          #+#    #+#             */
/*   Updated: 2025/05/29 11:32:00 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int emptyInput(const std::string &input)
{
    return input.empty() || input.find_first_not_of(' ') == std::string::npos;
}

std::string getInputNumber(const std::string &prompt)
{
    std::string input;
    
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (std::cin.eof())
            exit(0);
            
        if (!emptyInput(input) && input.find_first_not_of("0123456789") == std::string::npos)
            return input;
            
        std::cout << "Invalid input. Please enter a valid phone number." << std::endl;
    }
}

std::string getInput(const std::string &prompt)
{
    std::string input;
    
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (std::cin.eof())
            exit(0);
            
        if (!emptyInput(input))
            return input;
            
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

void addContactToPhoneBook(PhoneBook &phone_book)
{
    Contact contact;
    
    contact.setFirstName(getInput("Enter first name: "));
    contact.setLastName(getInput("Enter last name: "));
    contact.setNickname(getInput("Enter nickname: "));
    contact.setPhoneNumber(getInputNumber("Enter phone number: "));
    contact.setDarkestSecret(getInput("Enter darkest secret: "));
    
    phone_book.addContact(contact);
    std::cout << "Contact added successfully!" << std::endl;
}

void searchContacts(PhoneBook &phone_book)
{
    if (phone_book.getCount() == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    
    phone_book.displayContacts();
    
    std::string input;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, input);
    
    if (std::cin.eof())
        exit(0);
        
    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + phone_book.getCount())
        phone_book.displayContact(input[0] - '0');
    else
        std::cout << "Invalid index" << std::endl;
}

int main()
{
    PhoneBook phone_book;
    std::string command;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof() || command == "EXIT")
            break;
        else if (command == "ADD")
            addContactToPhoneBook(phone_book);
        else if (command == "SEARCH")
            searchContacts(phone_book);
    }
    
    return 0;
}
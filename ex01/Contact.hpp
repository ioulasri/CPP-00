/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoulasr <imoulasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:50:53 by imoulasr          #+#    #+#             */
/*   Updated: 2025/03/29 08:51:25 by imoulasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    ~Contact();

    void setFirstName(const std::string &first_name);
    void setLastName(const std::string &last_name);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phone_number);
    void setDarkestSecret(const std::string &darkest_secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    bool isEmpty() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:26:06 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 10:26:07 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

// This class does some Drilling noises then 50%. Use of rand()

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& str, const RobotomyRequestForm& f);

#endif
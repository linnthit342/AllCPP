#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
    //orthodox
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
    //getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
    //exception
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    //members
        void beSigned(const Bureaucrat& buru);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
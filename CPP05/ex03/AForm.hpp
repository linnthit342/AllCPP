#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
    //orthodox
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
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
        class FormNotSign : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    //members
        void beSigned(const Bureaucrat& buru);
        virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
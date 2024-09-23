#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <iomanip>

class Bureaucrat
{
    private:

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& constrCopy);
        Bureaucrat& operator=(const Bureaucrat& constrCopy);
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat& constrCopy);

#endif

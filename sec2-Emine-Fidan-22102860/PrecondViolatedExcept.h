#ifndef PRECONDVIOLATEDEXCEPT_H_INCLUDED
#define PRECONDVIOLATEDEXCEPT_H_INCLUDED

#include <stdexcept>
#include <string>
class PrecondViolatedExcept: public std::runtime_error{
public:
    PrecondViolatedExcept(const std::string& message) : std::runtime_error(message){}
};

#endif // PRECONDVIOLATEDEXCEPT_H_INCLUDED

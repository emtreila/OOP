#ifndef VALIDATOREXCEPTION_H
#define VALIDATOREXCEPTION_H
#include <exception>
#include <string>


class ValidatorException : public std::exception {
private:
    std::string message;

public:
    explicit ValidatorException(const char* msg);

    const char* what() const noexcept override;
};


#endif //VALIDATOREXCEPTION_H

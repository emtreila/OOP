#ifndef SERVICEEXCEPTION_H
#define SERVICEEXCEPTION_H
#include <exception>
#include <string>


class ServiceException : public std::exception {
private:
    std::string message;

public:
    explicit ServiceException(const char *msg);

    const char *what() const noexcept override;
};


#endif //SERVICEEXCEPTION_H

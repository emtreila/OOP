#ifndef REPOSITORYEXCEPTION_H
#define REPOSITORYEXCEPTION_H
#include <exception>
#include <string>


class RepositoryException : public std::exception {
private:
    std::string message;

public:
    explicit RepositoryException(const char* msg);

    const char* what() const noexcept override;
};


#endif //REPOSITORYEXCEPTION_H

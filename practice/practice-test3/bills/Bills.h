#ifndef BILLS_H
#define BILLS_H
#include <string>


class Bills {
private:
    std::string company_name;
    std::string serial_number;
    double sum;
    bool isPaid;

public:
    Bills();

    explicit Bills(const std::string &company_name, const std::string &serial_number, double sum, bool isPaid);

    std::string getCompanyName() const;

    void setCompanyName(const std::string &companyName);

    std::string getSerialNumber() const;

    void setSerialNumber(const std::string &serialNumber);

    double getSum() const;

    void setSum(double sum);

    bool getIsPaid() const;

    void setIsPaid(bool isPaid);

    std::string toString();
};


#endif //BILLS_H

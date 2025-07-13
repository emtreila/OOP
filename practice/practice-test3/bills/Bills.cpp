#include "Bills.h"

Bills::Bills() {
    this->company_name = "";
    this->serial_number = "";
    this->sum = 0;
    this->isPaid = false;
}

Bills::Bills(const std::string &company_name, const std::string &serial_number, double sum, bool isPaid) {
    this->company_name = company_name;
    this->serial_number = serial_number;
    this->sum = sum;
    this->isPaid = isPaid;
}

std::string Bills::getCompanyName() const {
    return this->company_name;
}

void Bills::setCompanyName(const std::string &companyName) {
    this->company_name = companyName;
}

std::string Bills::getSerialNumber() const {
    return this->serial_number;
}

void Bills::setSerialNumber(const std::string &serialNumber) {
    this->serial_number = serialNumber;
}

double Bills::getSum() const {
    return this->sum;
}

void Bills::setSum(double sum) {
    this->sum = sum;
}

bool Bills::getIsPaid() const {
    return this->isPaid;
}

void Bills::setIsPaid(bool isPaid) {
    this->isPaid = isPaid;
}

std::string Bills::toString() {
    return "Company: " + this->company_name + " , Sum: " + std::to_string(this->sum);
}

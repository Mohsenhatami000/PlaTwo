#include "Email.h"
#include <regex>
#include <string>
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
Email::Email(const std::string& value) {
	if (value.empty()) {
		throw Exceptions(DomainError::EmailEmpty);
	}
    static const std::regex gmailPattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
	if (!std::regex_match(value, gmailPattern)) {
		throw Exceptions(DomainError::EmailInvalidFormat);
	}
	email_ = value;
}
const std::string& Email::emailValue() const {
	return email_;
}

#include "PhoneNumber.h"
#include <regex>
#include <string>
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
#include "Shared/Constants/Constants.h"
PhoneNumber::PhoneNumber(const std::string& value) {
	if (value.empty()) {
		throw Exceptions(DomainError::PhoneNumberEmpty);
	}
	static const std::regex mobilePattern(R"(^(09\d{9}|98\d{10})$)");
	if (!std::regex_match(value, mobilePattern)) {
		if (!std::all_of(value.begin(), value.end(), ::isdigit)) {
			throw Exceptions(DomainError::PhoneNumberInvalidCharacter);
		}
		else if (value.length() != PHONE_NUMBER_MAX_LENTH || value.length() != PHONE_NUMBER_MIN_LENTH) {
			throw Exceptions(DomainError::PhoneNumberInvalidLength);
		}
		throw Exceptions(DomainError::PhoneNumberInvalidStart);
	}
	phoneNumber_ = value;
}
const std::string& PhoneNumber::phoneNumerValue() const {
	return phoneNumber_;
}

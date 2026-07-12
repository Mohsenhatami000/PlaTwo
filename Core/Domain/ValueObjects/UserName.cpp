#include "UserName.h"
#include <regex>
#include <string>
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
#include "Shared/Constants/Constants.h"
UserName::UserName(const std::string& value) {
	if (value.empty()) {
		throw Exceptions(DomainError::UserNameEmpty);
	}
	static const std::regex usernamePattern(R"(^(?=[a-zA-Z0-9._]{3,20}$)(?!.*[._]{2})[a-zA-Z][a-zA-Z0-9._]*[a-zA-Z0-9]$)");
	if (!std::regex_match(value, usernamePattern)) {
		if (value.length() > USERNAME_MAX_LENGTH || value.length() < USERNAME_MIN_LENGTH) {
			throw Exceptions(DomainError::UserNameInvalidLength);
		}
		throw Exceptions(DomainError::UserNameInvalidFormat);
	}
	username_ = value;
}
const std::string& UserName::userNameValue() const {
	return username_;
}

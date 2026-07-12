#include "Password.h"
#include <string>
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
#include "Shared/Constants/Constants.h"
#include <algorithm>
#include <cctype>


Password::Password(const std::string& pass) {
	if (pass.empty()) {
		throw Exceptions(DomainError::PasswordEmpty);
	}
	if (pass.length() <= PASSWORD_MIN_LENGTH || pass.length() >= PASSWORD_MAX_LENGTH) {
		throw Exceptions(DomainError::PasswordInvalidLength);
	}
	bool hasUpper = std::ranges::any_of(pass, [](unsigned char c) { return std::isupper(c); });
	bool hasLower = std::ranges::any_of(pass, [](unsigned char c) { return std::islower(c); });
	bool hasNumber = std::ranges::any_of(pass, [](unsigned char c) { return std::isdigit(c); });
	bool hasCharacter = std::ranges::any_of(pass, [](unsigned char c) { return std::ispunct(c); });
	bool hasSpace = std::ranges::any_of(pass, [](unsigned char c) { return std::isspace(c); });
	if (!hasUpper) {
		throw Exceptions(DomainError::PasswordNoUppercase);
	}
	if (!hasLower) {
		throw Exceptions(DomainError::PasswordNoLowercase);
	}
	if (!hasNumber) {
		throw Exceptions(DomainError::PasswordNoNumber);
	}
	if (!hasCharacter) {
		throw Exceptions(DomainError::PasswordNoCharacter);
	}
	if (hasSpace) {
		throw Exceptions(DomainError::PasswordContainSpace);
	}
	password_ = pass;
}
const std::string& Password::passwordValue() const {
	return password_;
}

#include "PasswordHash.h"
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
PasswordHash::PasswordHash(const std::string& passhash){
	if (passhash.empty()) {
		throw Exceptions(DomainError::PasswordEmpty);
	}
	passwordHash_ = passhash;
}
const std::string& PasswordHash::passswordHashValue() const {
	return passwordHash_;
}

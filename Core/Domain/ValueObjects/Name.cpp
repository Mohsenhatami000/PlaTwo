#include "Name.h"
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Enums/Enums.h"
#include "Shared/Constants/Constants.h"
Name::Name(const std::string& name) {
	if (name.empty()) {
		throw Exceptions(DomainError::NameEmpty);
	}
	else if (name.length() > NAME_MAX_LENGTH || name.length() < NAME_MIN_LENGTH) {
		throw Exceptions(DomainError::NameInvalidLength);
	}
	name_ = name;
}
const std::string& Name::nameValue() const {
	return name_;
}


#pragma once
#include <string>
class Email
{
private:
	std::string email_;

public:
	explicit Email(const std::string& value);
	const std::string& emailValue() const;
	bool operator==(const Email&) const = default;

};
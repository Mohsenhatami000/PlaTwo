#pragma once
#include <string>
class PhoneNumber
{
private:
	std::string phoneNumber_;

public:
	explicit PhoneNumber(const std::string& value);
	const std::string& phoneNumerValue() const;
	bool operator==(const PhoneNumber&) const = default;

};
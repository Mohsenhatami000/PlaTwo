#pragma once
#include <string>
class UserName
{
private:
	std::string username_;

public:
	explicit UserName(const std::string& value);
	const std::string& userNameValue() const;
	bool operator==(const UserName&) const = default;

};
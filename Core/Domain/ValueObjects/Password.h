#pragma once
#include <string>
class Password
{
private:
	std::string password_;
public:
	explicit Password(const std::string& pass);
	const std::string& passwordValue() const;
	bool operator==(const Password&) const = default;

};
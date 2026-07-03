#pragma once
#include <string>
class PasswordHash 
{
private:
	std::string passwordHash_;

public:
	explicit PasswordHash(const std::string& passhash);
	const std::string& passswordHashValue() const;
	bool operator==(const PasswordHash&) const = default;

};
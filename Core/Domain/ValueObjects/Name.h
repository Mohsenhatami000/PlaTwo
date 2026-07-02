#pragma once
#include <string>
class Name 
{
private:
	std::string name_;

public:
	explicit Name(const std::string& name);
	const std::string& nameValue() const;
	bool operator==(const Name&) const = default;

};
#pragma once
#include <string>
class IHasher
{
public:
    virtual ~IHasher() = default;
    virtual std::string hash(const std::string& pass) const = 0;
    virtual bool verify(const std::string& pass,const std::string& hash) const = 0;

};
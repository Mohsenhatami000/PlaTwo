#ifndef ARGON2ID_H
#define ARGON2ID_H
#include "Domain/Interfaces/Services/IHasher.h"
#include <argon2.h>
#include <string>
#include <stdexcept>
#include <array>
#include <Windows.h>
#include <bcrypt.h>
#include <vector>

class Argon2ID : public IHasher
{
private:
	static constexpr std::size_t saltLength_ = 16;
	static constexpr std::size_t hashLength_ = 32;
	static constexpr uint32_t timeCost_ = 3;
	static constexpr uint32_t memoryCost_ = 65536;
	static constexpr uint32_t parallelism_ = 1;
	static std::array<uint8_t, 16> generateSalt();

public:
	std::string hash(const std::string& pass) const override;
	bool verify(const std::string& pass, const std::string& hash) const override;

};

#endif // ARGON2ID_H

#include "Argon2ID.h"
#include <Domain/ValueObjects/PasswordHash.h>
std::array<uint8_t, 16> Argon2ID::generateSalt(){
    std::array<uint8_t,16> salt;
    const NTSTATUS res = BCryptGenRandom(nullptr, reinterpret_cast<PUCHAR>(salt.data()), static_cast<ULONG>(salt.size()),
            BCRYPT_USE_SYSTEM_PREFERRED_RNG );
    if (!BCRYPT_SUCCESS(res)){
        throw std::runtime_error("Failed to generate random salt.");
    }
    return salt;
}
std::string Argon2ID::hash(const std::string& pass) const {
    const auto salt = generateSalt();
    const auto encodedlength = argon2_encodedlen(timeCost_,memoryCost_,parallelism_,saltLength_,hashLength_,Argon2_id);
    std::vector<char> encoded(encodedlength);
    const auto result = argon2id_hash_encoded(timeCost_,memoryCost_,parallelism_,pass.data(),pass.size(),salt.data(),
            salt.size(),hashLength_,encoded.data(),encoded.size());
    if (result != ARGON2_OK){
        throw std::runtime_error(argon2_error_message(result));
    }
    return std::string(encoded.data());
}
bool Argon2ID::verify(const std::string& pass, const std::string& hash) const{
    const int result = argon2id_verify(hash.c_str(), pass.data(), pass.size());
    if (result == ARGON2_OK) {
        return true;
    }
    if (result == ARGON2_VERIFY_MISMATCH) {
        return false;
    }
    throw std::runtime_error(argon2_error_message(result));
}

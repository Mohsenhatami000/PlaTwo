#include "authenticateduser.h"

AuthenticatedUser::AuthenticatedUser(std::int64_t id , const Name& name, const UserName& username):u_ID_(id),u_name_(name),u_username_(username){

}
std::int64_t AuthenticatedUser::ID() const noexcept{
    return ID_;
}
const Name& AuthenticatedUser::Name() const noexcept {
    return name_;
}
const UserName& AuthenticatedUser::UserName() const noexcept {
    return username_;
}
bool AuthenticatedUser::changeName(const Name& name) {
    if (name == name_) {
        return false;
    }
    name_ = name;
    return true;
}
bool AuthenticatedUser::changeUserName(const UserName& username) {
    if (username == username_) {
        return false;
    }
    username_ = username;
    return true;
}
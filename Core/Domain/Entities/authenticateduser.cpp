#include "authenticateduser.h"


AuthenticatedUser::AuthenticatedUser(std::int64_t id , const Name& name, const UserName& username):u_ID_(id),u_name_(name),u_username_(username){

}
std::int64_t AuthenticatedUser::id() const noexcept{
    return u_ID_;
}
const Name& AuthenticatedUser::name() const noexcept {
    return u_name_;
}
const UserName& AuthenticatedUser::username() const noexcept {
    return u_username_;
}
bool AuthenticatedUser::changeName(const Name& name) {
    if (name == u_name_) {
        return false;
    }
    u_name_ = name;
    return true;
}
bool AuthenticatedUser::changeUserName(const UserName& username) {
    if (username == u_username_) {
        return false;
    }
    u_username_ = username;
    return true;
}
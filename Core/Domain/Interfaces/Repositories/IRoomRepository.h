#pragma once
#include <optional>
#include "Entities/Room.h"
class IRoomRepository
{
public:
    virtual ~IRoomRepository() = default;
    virtual void save(const Room& room) = 0;
    virtual void update(const Room& room) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<Room> findByID(std::int64_t id) const = 0;

};
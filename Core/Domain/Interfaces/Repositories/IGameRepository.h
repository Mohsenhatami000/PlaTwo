#pragma once
#include <optional>
#include "Entities/GameSession.h"
class IGameSessionRepository
{
public:
    virtual ~IGameSessionRepository() = default;
    virtual bool exists(std::int64_t id) const = 0;
    virtual void save(const GameSession& session) = 0;
    virtual void update(const GameSession& session) = 0;
    virtual void remove(std::int64_t id) = 0;
    virtual std::optional<GameSession> findByID(std::int64_t id) const = 0;

};
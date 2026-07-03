#pragma once
#include <vector>
#include <optional>
#include "Entities/History.h"
class IHistoryRepository
{
public:
    virtual ~IHistoryRepository() = default;
    virtual void save(const History& history) = 0;
    virtual std::optional<History> findByID(std::int64_t id) const = 0;
    virtual std::vector<History> findByUserID(std::int64_t id) const = 0;

};
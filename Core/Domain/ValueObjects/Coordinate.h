#pragma once
class Coordinate
{
private:
	int row_;
	int column_;

public:
	Coordinate(int row, int column);
	int row() const noexcept;
	int column() const noexcept;
	bool operator==(const Coordinate& coordinate) const noexcept;

};
#include "Coordinate.h"
#include "Exceptions/Exceptions.h"
#include "Enums/Enums.h"
Coordinate::Coordinate(int row, int column) {
	if (row < 0 || column < 0) {
		throw Exceptions(DomainError::CoordinateIsNegative);
	}
	row_ = row;
	column_ = column;
}
int Coordinate::row() const noexcept {
	return row_ ;
}
int Coordinate::column() const noexcept {
	return column_;
}
bool Coordinate::operator==(const Coordinate& coordinate) const noexcept {
	return row_ == coordinate.row() && column_ == coordinate.column();
}
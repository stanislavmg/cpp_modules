#include "Fixed.hpp"

Fixed(int point) {
	fixed_point_ = point;
}

Fixed() {
	std::cout << "Default constructor called\n";
}

~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed(const Fixed &num) {
	std::cout << "Copy constructor called\n";
}

Fixed &operator=(const Fixes &num) {
	std::cout << "Copy assignment operator called\n";
}


int getRawBits(void) const {

}

void setRawBits(int const raw) {

}

};

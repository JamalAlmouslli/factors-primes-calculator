# factors-primes-calculator

This implementation, written in C++11, is designed to be more performant, such as by avoiding calls to `std::sqrt()` and avoiding casting. Addition is used instead, along with [`std::lldiv()`][1] to avoid performing division twice.


[1]: http://en.cppreference.com/w/cpp/numeric/math/div

//
// Created by Lucius Schoenbaum on 12/2/22.
//


#include <types/integers.h>

#define N64 N64

N64 operator""_N64(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_N64(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 N32

N64 operator""_N32(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_N32(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 N16

N64 operator""_N16(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_N16(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 Nbyte

N64 operator""_N8(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_N8(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}



#undef N64
#define N64 U64

N64 operator""_U64(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_U64(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 U32

N64 operator""_U32(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_U32(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 U16

N64 operator""_U16(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_U16(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}


#undef N64
#define N64 Ubyte

N64 operator""_U8(const char * lit, std::size_t len) {
    return N64(std::strtol(lit, nullptr, 10));
}

N64 operator""_U8(unsigned long long n) {
    return N64(n);
}

std::ostream& operator<<(std::ostream & os, const N64 & obj) {
    os << obj.str();
    return os;
}

#undef N64



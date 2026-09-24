//
// Created by Lucius Schoenbaum on 3/23/22.
//

/*
 * Integer types
 * 
 * These types can be used as substitutes 
 * for the standard integer types int64_t, uint64_t, 
 * int32_t, uint32_t, etc. 
 * 
 * The advantage of doing so is modularity: 
 * the API for these types is common to other 
 * DGCALC structures. In addition, Tennsix 
 * can be used to build integer type matrices. 
 *
 * NOTE: There is a catch, however.
 * Careful with operator% using these types!
 * For compatibility with Super methods, operator%
 * is given to a linear algebra operation
 * which (in the degenerate case) is multiplication. 
 * The rem() method and mod() method are provided 
 * as a substitute for operator%. 
 * 
 * It shouldn't be a problem
 * as far as building integer matrices (for example)
 * is concerned, because you wouldn't be applying operator%
 * on those in the usual sense (integer remainder), anyway.
 *
 * But as far as having these types be one-to-one drop-in
 * replacements of built-in types,
 * this does throw a wrench in the works. 
 * 
 * This issue is being monitored.
 *
 */

#pragma once

#include <types/machinetype.h>

using N64 = MachineType<int64_t>;
using N32 = MachineType<int32_t>;
using N16 = MachineType<int16_t>;
using Nbyte = MachineType<int8_t>;

using U64 = MachineType<uint64_t>;
using U32 = MachineType<uint32_t>;
using U16 = MachineType<uint16_t>;
using Ubyte = MachineType<uint8_t>;

// size types...just an idea for now
using Nsize = MachineType<int>;
using Usize = MachineType<std::size_t>;



// string stream << and constructors:
// 123_N64
// "123"_N64
// etc. for 8 different types



#define N64 N64

N64 operator""_N64(const char * lit, std::size_t len);

N64 operator""_N64(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 N32

N64 operator""_N32(const char * lit, std::size_t len);

N64 operator""_N32(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 N16

N64 operator""_N16(const char * lit, std::size_t len);

N64 operator""_N16(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 Nbyte

N64 operator""_N8(const char * lit, std::size_t len);

N64 operator""_N8(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);



#undef N64
#define N64 U64

N64 operator""_U64(const char * lit, std::size_t len);

N64 operator""_U64(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 U32

N64 operator""_U32(const char * lit, std::size_t len);

N64 operator""_U32(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 U16

N64 operator""_U16(const char * lit, std::size_t len);

N64 operator""_U16(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);


#undef N64
#define N64 Ubyte

N64 operator""_U8(const char * lit, std::size_t len);

N64 operator""_U8(unsigned long long n);

std::ostream& operator<<(std::ostream & os, const N64 & obj);

#undef N64

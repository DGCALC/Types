//
// Created by Lucius Schoenbaum on 3/23/22.
//

/*
 * machinetype.h
 * 
 * Provides the MachineType<MT> structure. 
 * This sounds very general, but it 
 * does not provide much generality, 
 * and it is not tested on a large number of 
 * architectures. 
 * 
 * At this point, it is a placeholder, more or less, 
 * but it supports the 10 basic, most common types: 
 * uintX_t, intX_t for X = 8, 16, 32, 64; 
 * double, float. 
 * It allows for the creation of Tennsix/Calx 
 * structures composed out of these 10 types. 
 * 
 * It is probably a misnomer to call this code MachineType.
 * The name may change at some point.
 *
 * DEVNOTE:
 * Previous version of this class had virtual methods,
 * which taught me that having virtual methods can
 * modify the size in a surprising, opaque, and irksome manner.
 * See the _T unit test to find a minimal example.
 * 
 */




#pragma once


#include <DGCALC.h>
#include <cmath> // std::sqrt, std::abs, remainder
#include <types/type.h> // type id

template <typename /* machine type */ MT>
struct MachineType {
    template <typename PP, typename T, size_t size, size_t cosize, size_t prosize>
    friend class Super;
public: // static fields:

   using Scalar = MT;
   using Under = MT;

    // static, constant expression-initialized, const:
    static constexpr size_t size = 1;
    static constexpr size_t cosize = 1;
    static constexpr size_t shortsize = 1;
    static constexpr size_t data_size = 1;
    static constexpr size_t dimension = 1;

public: // types:

    using Undertype = MT;

protected: // fields:

    MT data;

public: // ctor:

    explicit MachineType(): data(0) {}

    MachineType(MT in): data(in) {}

    // machine type from string,
    // default base is base 10.
    explicit MachineType(std::string s, int base = 10) {
        if constexpr (CompileTime::id<MT>::value == Type::id::Tfloat) {
            data = std::strtof(s.c_str(), nullptr);
        }
        else if constexpr (CompileTime::id<MT>::value == Type::id::Tdouble) {
            data = std::strtod(s.c_str(), nullptr);
        }
        else if constexpr (CompileTime::id<MT>::value >= Type::id::Tint64
                           && CompileTime::id<MT>::value <= Type::id::Tint8) {
            if constexpr (CompileTime::id<MT>::value == Type::id::Tint8) {
                data = static_cast<int8_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tint16) {
                data = static_cast<int16_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tint32) {
                data = static_cast<int32_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tint64) {
                data = static_cast<int64_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else {
                assert(0 == 1);
            }
        }
        else if constexpr (CompileTime::id<MT>::value >= Type::id::Tuint64
                           && CompileTime::id<MT>::value <= Type::id::Tuint8) {
            if constexpr (CompileTime::id<MT>::value == Type::id::Tuint8) {
                data = static_cast<uint8_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tuint16) {
                data = static_cast<uint16_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tuint32) {
                data = static_cast<uint32_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else if (CompileTime::id<MT>::value == Type::id::Tuint64) {
                data = static_cast<uint64_t>(std::strtol(s.c_str(), nullptr, base));
            }
            else {
                assert(0 == 1);
            }
        }
        else {
            assert(0 == 1);
        }
    }

   // Explicit conversion prevents silent coercion.
   //  Supported since C++11.
   // Note: Implicit conversion is not recommended
   // by the C++ Core Guidlelines.
   explicit operator MT() const {
      return data;
   }

public: // copy:

    MachineType(const MachineType & in) {
        this->data = in.data;
    }

    MachineType & operator=(const MachineType & rhs) {
        if (this == &rhs) return *this;
        this->data = rhs.data;
        return *this;
    }

public: // dtor:

    ~MachineType() = default;

public: // static methods:

    static MachineType zero() {
        return MachineType(0);
    }

    static MachineType unit() {
        return MachineType(1);
    }

    // T::sqrt(x)
    static MachineType sqrt(MachineType ain) {
        return MachineType(static_cast<MT>(std::sqrt(ain.data)));
    }

    // T::abs(x)
    static MachineType abs(MachineType ain) {
        return MachineType(static_cast<MT>(std::abs(ain.data)));
    }

    // T::neg(x)
    static MachineType neg(MachineType ain) {
        return MachineType(-ain.data);
    }

    // T::rem(x, y)
    static MachineType rem(MachineType ain, MachineType bin) {
        if constexpr ( /* if MT is an integer built-in type */
                CompileTime::id<MT>::value >= 0
                && CompileTime::id<MT>::value < 8
        ) {
            return (ain % bin);
        }
        else {
            return MachineType(remainder(ain.data, bin.data));
        }
    }

    // T::mod(x, y)
    static MachineType mod(MachineType ain, MachineType bin) {
        return rem(ain, bin);
    }

public: // API:

    MachineType sqrt() const {
        return MachineType(static_cast<MT>(std::sqrt(data)));
    }

    MachineType abs() const {
        return MachineType(static_cast<MT>(std::abs(data)));
    }

    MachineType neg() const {
        return MachineType(-data);
    }

    MachineType rem(MachineType bin) {
        return MachineType(remainder(data, bin.data));
    }

    MachineType mod(MachineType bin) {
        return this->rem(bin);
    }

private: // Super-only:

    // used by Super for l2-norm
    friend MachineType operator^(const MachineType & ain, int pow) {
        return ain*ain;
    }

    [[nodiscard]] MachineType max() const {
        return *this;
    }

    [[nodiscard]] MachineType min() const {
        return *this;
    }

public: // Super-related:

    // multiplication T x T --> T
    // trivial dot product.
    friend MachineType operator%(const MachineType & lhs, const MachineType & rhs) {
        return lhs*rhs;
    }

    // Bracket notation
    MachineType & operator[](size_t index) {
        return *this;
    }

    const MachineType & operator[](size_t index) const {
        return *this;
    }

    template <size_t sz>
    MachineType & operator[](DGCALC::IPoint<sz> index) {
        return *this;
    }

    template <size_t sz>
    const MachineType & operator[](DGCALC::IPoint<sz> index) const {
        return *this;
    }

public: // artifacts:

    bool operator==(const MachineType & rhs) const {
        if (this == &rhs) return true;
        return (data == rhs.data);
    };

    bool operator!=(const MachineType & rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const MachineType & rhs) const {
        return (data < rhs.data);
    }

    bool operator>(const MachineType & rhs) const {
        return (rhs < *this);
    }

    bool operator<=(const MachineType & rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const MachineType & rhs) const {
        return !(*this < rhs);
    }

    // compound +
    MachineType & operator+=(const MachineType & rhs) {
        data += rhs.data;
        return *this;
    }
    // compound -
    MachineType & operator-=(const MachineType & rhs) {
        data -= rhs.data;
        return *this;
    }
    // compound *
    MachineType & operator*=(const MachineType & rhs) {
        data *= rhs.data;
        return *this;
    }
    // compound /
    MachineType & operator/=(const MachineType & rhs) {
        data /= rhs.data;
        return *this;
    }
    /*
     * Reminder: when you get to the binary operators,
     * stop returning references.
     * Adding "friend" makes them ordinary functions,
     * which can nevertheless modify private members.
     */
    friend MachineType operator+(const MachineType & lhs, const MachineType & rhs) {
        MachineType out = lhs;
        out += rhs;
        return out;
    }
    friend MachineType operator-(const MachineType & lhs, const MachineType & rhs) {
        MachineType out = lhs;
        out -= rhs;
        return out;
    }
    friend MachineType operator*(const MachineType & lhs, const MachineType & rhs) {
        MachineType out = lhs;
        out *= rhs;
        return out;
    }
    friend MachineType operator/(const MachineType & lhs, const MachineType & rhs) {
        MachineType out = lhs;
        out /= rhs;
        return out;
    }

    // undertype - useful for interoperability
    [[nodiscard]]
    Undertype under() const {
        return data;
    }

public: // printing

    // print in digest form
    [[nodiscard]]
    std::string str_di() const
    {
        return std::to_string(data);
    }

    // print in >= 94% precision
    [[nodiscard]]
    std::string str_dat() const
    {
        return std::to_string(data);
    }

    [[nodiscard]]
    std::string str() const
    {
        return str_dat();
    }

};

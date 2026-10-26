//
// Created by Lucius Schoenbaum on 3/24/22.
//

/*
 *
 * Type
 *
 * Type-level compile time reasoning -
 * helpers, printing, etc. - encapsulated
 * in a structure called Type.
 *
 * It is a companion with MachineType
 * and the scalar types that are the
 * main functionality.
 * The three ...well, "types"... of
 * classes Type, MachineType,
 * and the scalar types (double754 and the rest),
 * all share a printing API in common,
 * and the numeric types also share
 * much in common.
 * In addition, the CompileTime functionality
 * of Type (see below) is used
 * in the implementation of MachineType.
 *
 * todo I haven't looked at this in a while, it was originally supposed to be useful for some Phantich code.
 *
 */

#pragma once

#include <string>
#include <cstring>

struct Type {

    enum class id {
        Tint64 = 0,
        Tint32 = 1,
        Tint16 = 2,
        Tint8 = 3,
        Tuint64 = 4,
        Tuint32 = 5,
        Tuint16 = 6,
        Tuint8 = 7,
        Tfloat = 8,
        Tdouble = 9,
        Type = 10,
        Custom = 11,
    };

    id t;

    Type() = default;

    Type(id t): t(t) {}

    Type(std::string s) {
        if (s == "float") {
            t = id::Tfloat;
        }
        else if (s == "double") {
            t = id::Tdouble;
        }
        else if (std::strncmp(s.c_str(), "int", 3) == 0) {
            if (s == "int8") {
                t = id::Tint8;
            }
            else if (s == "int16") {
                t = id::Tint16;
            }
            else if (s == "int32") {
                t = id::Tint32;
            }
            else if (s == "int64") {
                t = id::Tint64;
            }
        }
        else if (std::strncmp(s.c_str(), "uint", 4) == 0) {
            if (s == "uint8") {
                t = id::Tuint8;
            }
            else if (s == "uint16") {
                t = id::Tuint16;
            }
            else if (s == "uint32") {
                t = id::Tuint32;
            }
            else if (s == "uint64") {
                t = id::Tuint64;
            }
        }
        else if (s == "Type") {
            t = id::Type;
        }
        else t = id::Custom;
    }

    // print in digest form
    std::string str_dat() const {
        return str();
    }

    // print in >= 94% precision
    std::string str_di() const {
        return str();
    }

    std::string str() const {
        std::string out;
        switch (t) {
            case (id::Tfloat):
                out += "float";
                break;
            case (id::Tdouble):
                out += "double";
                break;
            case (id::Tint8):
                out += "int8";
                break;
            case (id::Tint16):
                out += "int16";
                break;
            case (id::Tint32):
                out += "int32";
                break;
            case (id::Tint64):
                out += "int64";
                break;
            case (id::Tuint8):
                out += "uint8";
                break;
            case (id::Tuint16):
                out += "uint16";
                break;
            case (id::Tuint32):
                out += "uint32";
                break;
            case (id::Tuint64):
                out += "uint64";
                break;
            case (id::Type):
                out += "Type";
                break;
            case (id::Custom):
                out += "Custom";
                break;
        }
        return out;
    }

};


namespace CompileTime {

        // id That We Can Use During Compile-Time

        template<typename T>
        struct id;

        template<>
        struct id<float> {
            static const Type::id value = Type::id::Tfloat;
        };
        template<>
        struct id<double> {
            static const Type::id value = Type::id::Tdouble;
        };
        template<>
        struct id<int8_t> {
            static const Type::id value = Type::id::Tint8;
        };
        template<>
        struct id<int16_t> {
            static const Type::id value = Type::id::Tint16;
        };
        template<>
        struct id<int32_t> {
            static const Type::id value = Type::id::Tint32;
        };
        template<>
        struct id<int64_t> {
            static const Type::id value = Type::id::Tint64;
        };
        template<>
        struct id<uint8_t> {
            static const Type::id value = Type::id::Tuint8;
        };
        template<>
        struct id<uint16_t> {
            static const Type::id value = Type::id::Tuint16;
        };
        template<>
        struct id<uint32_t> {
            static const Type::id value = Type::id::Tuint32;
        };
        template<>
        struct id<uint64_t> {
            static const Type::id value = Type::id::Tuint64;
        };
        template<>
        struct id<Type> {
            static const Type::id value = Type::id::Type;
        };
        // ...The Custom case must always be the "constexpr else" branch.

}

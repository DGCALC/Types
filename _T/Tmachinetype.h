//
// Created by Lucius Schoenbaum on 3/24/22.
//

#pragma once

#include <Tbasis.h>

//#include <types/machinetype.h>

class TMachineType {

    /*
     * You would be surprised to learn
     * that (apparently) having a virtual
     * method changes the size of the type.
     *
     * ....(!!!)
     *
     * The following is a minimal example.
     *
     */

    template <typename MT>
    struct MType1 {

        MT mt;

        MType1(MT mt): mt(mt) {}

    };

    template <typename MT>
    struct MType2 {

        MT mt;

        MType2(MT mt): mt(mt) {}

        virtual int func(int x) {
            return x + 123;
        }

    };



public: // API:

    static void Tsize() {
        cout << "minimal example of effect of virtual method on size.\n";
        cout << "size of double = " << sizeof(double) << endl;
        cout << "size of MType1<double> = " << sizeof(MType1<double>) << endl;
        cout << "size of MType2<double> = " << sizeof(MType2<double>) << endl;
        double test = 1.234e16;
        cout << "test = " << test << endl;
        MType1<double> foo(test);
        MType2<double> bar(test);
        // This is an extra step so we can look at bytes.
        double foob[1];
        double barb[2];
        std::memcpy(foob, (void*)&foo, 8);
        std::memcpy(barb, (void*)&bar, 16);
        cout << "foo's bytes = " << foob[0] << endl;
        cout << "bar's bytes = " << static_cast<int64_t>(barb[0]) << ", " << barb[1] << endl;
    }


};

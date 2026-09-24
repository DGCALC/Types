//
// Created by Lucius Schoenbaum on 3/24/22.
//

#pragma once

#include <Tbasis.h>

#include <types/integers.h>

class Tintegers {

public: // API:

    static void Tdryrun() {
        N64 x = N64(12345);
        cout << x.str() << endl;
        cout << "bye" << endl;
    }

    static void Tstr_methods() {
        N64 x = N64(87654);
        cout << "standard:\n";
        cout << x.str() << endl;
        cout << "digest:\n";
        cout << x.str_di() << endl;
        cout << "dat:\n";
        cout << x.str_dat() << endl;
        cout << "bye" << endl;
    }

    static void Toperations() {
        N64 a = N64(12);
        N64 b = N64(33);
        N64 a2 = N64(987);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "equality" << endl;
        cout << (a == b) << endl;
        cout << (a == a) << endl;
        cout << (a == a2) << endl;
        cout << "operator+" << endl;
        N64 c = a;
        c += b;
        cout << "a + b = " << c << endl;
        cout << "friend operator+" << endl;
        cout << (a + b) << endl;
        cout << "static method" << endl;
        cout << N64::sqrt(a) << endl;
        cout << a.sqrt() << endl;
        cout << "static field" << endl;
        cout << N64::size << endl;
        cout << N64::cosize << endl;
    }


};

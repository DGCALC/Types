//
// Created by Lucius Schoenbaum on 12/2/22.
//

#pragma once


#include <Tbasis.h>

#include <types/viz.h>

using namespace DGCALC;

class Tviz_t {


public: // API:

    static void Tdryrun() {
        viz_t x = viz_t(12345);
        cout << x.str() << endl;
        cout << "bye" << endl;
    }

    static void Tstr_methods() {
        viz_t x = viz_t(87654);
        cout << "standard:\n";
        cout << x.str() << endl;
        cout << "digest:\n";
        cout << x.str_di() << endl;
        cout << "dat:\n";
        cout << x.str_dat() << endl;
        cout << "bye" << endl;
    }

    static void Toperations() {
        viz_t a = viz_t(12);
        viz_t b = viz_t(33);
        viz_t a2 = viz_t(987);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "equality" << endl;
        cout << (a == b) << endl;
        cout << (a == a) << endl;
        cout << (a == a2) << endl;
        cout << "operator+" << endl;
        viz_t c = a;
        c += b;
        cout << "a + b = " << c << endl;
        cout << "friend operator+" << endl;
        cout << (a + b) << endl;
        cout << "static method" << endl;
        cout << viz_t::sqrt(a) << endl;
        cout << a.sqrt() << endl;
        cout << "static field" << endl;
        cout << viz_t::size << endl;
        cout << viz_t::cosize << endl;
    }

    static void Toperatorquote() {
        cout << "operator quote and literals" << endl;
        cout << 1_viz << endl;
        cout << 2.345_viz << endl;
        cout << "bye" << endl;
    }

};



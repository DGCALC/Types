//
// Created by Lucius Schoenbaum on 12/2/22.
//

/*
 * viz_t
 *
 * Type for visualization.
 *
 * The principle applied here is the following:
 * Any visualization routine should be built around
 * the expectation of a certain consistent scalar precision,
 * whether the scalars native to the computation
 * to be visualized are very high precision, very low precision,
 * or in between. This is for the convenience of
 * coding for visualizations, which naturally becomes
 * a sort of boutique affair.
 * The approach of DGCALC is to have such a
 * target type for visualizations, viz_t.
 * It should be a machine type (native to the machine's architecture).
 * Double precision is unnecessary once the
 * values to be represented visually are converted to
 * the visualization type.
 *
 *
 */

#pragma once

#include <types/machinetype.h>

using viz_t = MachineType<float>;

inline viz_t operator""_viz(const char * lit, size_t) {
   return viz_t(strtof(lit, nullptr));
}

inline viz_t operator""_viz(unsigned long long int i) {
   return viz_t(i);
}

inline viz_t operator""_viz(long double ain) {
   return viz_t(static_cast<float>(ain));
}

inline std::ostream& operator<<(std::ostream & os, const viz_t & obj) {
   os << obj.str();
   return os;
}


namespace Viz {

enum Dim {
   one = 1,
   two = 2,
   three = 3
};

inline viz_t tiny() {
   return 1e-12_viz;
}

}





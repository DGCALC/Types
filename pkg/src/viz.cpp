//
// Created by Lucius Schoenbaum on 12/2/22.
//

#include <types/viz.h>


viz_t operator""_viz(const char * lit, size_t) {
    return viz_t(strtof(lit, nullptr));
}

viz_t operator""_viz(unsigned long long int i) {
    return viz_t(i);
}

viz_t operator""_viz(long double ain) {
    return viz_t(static_cast<float>(ain));
}

std::ostream& operator<<(std::ostream & os, const viz_t & obj) {
    os << obj.str();
    return os;
}

namespace Viz {
    viz_t tiny() {
        return 1e-12_viz;
    }
}


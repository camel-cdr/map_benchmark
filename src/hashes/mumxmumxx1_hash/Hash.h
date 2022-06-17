#pragma once

#include "mixer.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <type_traits>
#include <utility>

static const char* HashName = "mumxmumxx1";

#include <cstdint>

// very fast high quality mixer. From https://github.com/martinus/better-faster-stronger-mixer
template <typename T>
struct Hash {
    size_t operator()(T const& v) const {
        return ankerl::mixer::mumxmumxx1(v);
    }
};

// default hash
template <>
struct Hash<std::string> {
    size_t operator()(std::string const& key) const {
        return std::hash<std::string>{}(key);
    }
};
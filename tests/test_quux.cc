#include <stdexcept>

#include "quux/quux.h"

namespace {
bool
test_construct()
{
    Quux quux;
    return true;
}

bool
test_quuxifier()
{
    Quux quux;
    return (quux.quuxifier() == quux.get_version());
}
}

int
main(int argc, char* argv[])
{
    if (!test_construct()) {
        throw std::runtime_error("test_construct failed");
    }
    if (!test_quuxifier()) {
        throw std::runtime_error("test_quuxifier failed");
    }

    return 0;
}

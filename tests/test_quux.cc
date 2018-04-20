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
    return (quux.quuxify() == quux.get_version());
}
} // namespace

int
main(int argc, char* argv[])
{
    if (!test_construct()) {
        throw std::runtime_error("test_construct failed");
    }
    if (!test_quuxifier()) {
        throw std::runtime_error("test_quuxify failed");
    }

    return 0;
}

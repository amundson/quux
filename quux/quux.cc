#include <iostream>
#include "quux.h"
#include "quux_version.h"

const int Quux::version_major = quux_version_major;
const int Quux::version_minor = quux_version_minor;

Quux::Quux()
{
}

int
Quux::get_version() const
{
    return 10 * version_major + version_minor;
}

int
Quux::quuxifier() const
{
    std::cout << "Quux::quuxifier version " << get_version()
              << " invoked\n";
    return get_version();
}

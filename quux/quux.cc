#include <iostream>
#include "quux.h"
#include "quux_version.h"
#include "garply/garply.h"

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
Quux::quuxify() const
{
    int quux_version = get_version();
    std::cout << "Quux::quuxifier version " << quux_version
              << " invoked\n";

    Garply garply;
    int garply_version = garply.garplinate();

    if(garply_version != quux_version) {
        throw std::runtime_error("Quux found an incompatible version of Garply.");
    }

    return quux_version;
}

#include <iostream>
#include <map>
#include <resource.hpp>

bool Resource::setStatus(const int in) noexcept
{
    if (in > 0)
    {
        status_ = in;
        return true;
    }

    return false;
}

void Resource::printStatus() noexcept
{
    std::cout << status_ << std::endl;
}
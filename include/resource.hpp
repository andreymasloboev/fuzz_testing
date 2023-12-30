#include <string>

class Resource
{
public:
    /// @brief Function for change status of resource
    /// @param[in] in status for change
    /// @return none.
    bool setStatus(const int in) noexcept;

    /// @brief Function for print status of resource
    /// @return none.
    void printStatus() noexcept;

    /// @brief Function for get status of resource
    /// @return status of resource
    [[nodiscard("You can not ignore status")]] int getStatus() const
    {
        return status_;
    }

private:
    /// @brief Status of resource
    int status_ = 0;
};
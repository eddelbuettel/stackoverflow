#include <chrono>
#include <fmt/format.h>
#include <fmt/chrono.h>

int main() {
    fmt::print("{:%S}\n", std::chrono::system_clock::now().time_since_epoch());
    exit(0);
}

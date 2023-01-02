#include <chrono>
#include <fmt/format.h>
#include <fmt/chrono.h>

int main() {
    auto now = std::chrono::system_clock::now();
    auto sse = now.time_since_epoch();
    fmt::print("{:%FT%H:%M:}{:%S}\n", now, sse);
    exit(0);
}

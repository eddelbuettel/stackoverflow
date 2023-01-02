library(RcppSpdlog)
RcppSpdlog::log_set_pattern("[%Y-%m-%d %H:%M:%S.%f] [%L] %v")
RcppSpdlog::log_warn("Hello")
# [2023-01-02 15:00:49.746031] [W] Hello
RcppSpdlog::log_set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v")
RcppSpdlog::log_warn("World")
# [2023-01-02 15:01:02.137] [W] World

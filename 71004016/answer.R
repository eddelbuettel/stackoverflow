## df from other answer
df <- structure(list(date = structure(c(19023, 19023, 19023, 19023,
                                        19024, 19024, 19024, 19024, 19023, 19023, 19023, 19023, 19024,
                                        19024, 19024, 19024, 19023, 19023, 19023, 19023, 19024, 19024,
                                        19024, 19024), class = "Date"),
                     city = c("Birmingham", "Huntsville", "Mobile", "Montgomery", "Birmingham", "Huntsville", "Mobile",
                              "Montgomery", "New York", "Buffalo", "Ithaca", "Long Island",
                              "New York", "Buffalo", "Ithaca", "Long Island", "Seattle", "Olympia",
                              "Ellensburg", "Spokane", "Seattle", "Olympia", "Ellensburg",
                              "Spokane"),
                     state = c("Alabama", "Alabama", "Alabama", "Alabama", "Alabama", "Alabama", "Alabama", "Alabama", "New York", "New York",
                               "New York", "New York", "New York", "New York", "New York", "New York",
                               "Washington", "Washington", "Washington", "Washington", "Washington",
                               "Washington", "Washington", "Washington"),
                     active_cases = c(1567L, 2340L, 1039L, 1294L, 1567L, 2340L, 1039L, 1294L, 3980L, 2390L, 2133L, 1501L, 3980L, 2390L, 2133L, 1501L, 567L, 1340L, 384L,
                                      1093L, 567L, 1340L, 384L, 1093L)), row.names = c(NA, -24L), class = "data.frame")

## one-liner
aggregate(active_cases ~ date + state, df, sum)

#!/usr/bin/r

for (i in seq_along(argv)) {
    cat("Argument", i, "is", argv[i], "\n")
}

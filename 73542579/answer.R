
now <- Sys.time()
for (p in seq(1, 7)) {
    then <- now + 10^(-p)
    if (then == now)
        cat("** Indifferent at 10^-p for p=", p, "\n", sep="")
    else
        cat("Different at 10^-p for p=", p, "\n", sep="")
}

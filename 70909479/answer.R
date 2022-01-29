
d1 <- as.POSIXct("2021/03/04 11:15:19.000")
d2 <- as.POSIXct("2021/03/04 11:15:19.999")
d1 == d2
trunc(d1) == trunc(d2)

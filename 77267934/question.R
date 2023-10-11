
suppressMessages({
    library(data.table)
    library(dplyr)
})

dates1 <-  as.POSIXct(c("2015-10-26 12:00:00","2015-10-26 13:00:00","2015-10-26 14:00:00"))
values1 <- c("a","b","c")

dates2 <- as.POSIXct(c("2015-10-26 11:59:00","2015-10-26 12:00:10"))
values2 <- c("A","C")

df1 <- data.table(dates1, values1)
df2 <- data.table(dates2, values2)

## r2evans
df1[df2, c("values2", "dates2") := .(i.values2, i.dates2), on = .(dates1 >= dates2)][]


df1 <- data.frame(dates1, values1)
df2 <- data.frame(dates2, values2)

left_join(df1, df2, join_by(closest(y$dates2 <= x$dates1)))

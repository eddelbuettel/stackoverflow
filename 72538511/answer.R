
df <- data.frame(time = as.POSIXct(c("1899-12-31 00:00:00 UTC", "1899-12-31 00:15:00 UTC",
                                     "1899-12-31 00:30:00 UTC", "1899-12-31 00:45:00 UTC",
                                     "1899-12-31 01:00:00 UTC", "1899-12-31 01:15:00 UTC")))

df$mltime <- strftime(df$time, "%H%M")
print(df)

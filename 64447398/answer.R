
Date <- c("2010-01-04" , "2010-01-04")
Time <- c("04:00:00", "06:00:00")
value <- c(1, 2)

df <- data.frame(Date=Date, Time=Time, value=value)

df[,"pt"] <- as.POSIXct(paste(Date, Time))

library(xts)
x <- xts(df[,"value"], order.by=df[,"pt"])
x

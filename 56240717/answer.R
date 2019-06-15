library(nanotime)
library(data.table)

DT <- data.table(ts =  c(nanotime('2011-12-05 08:30:00.000',format ="%Y-%m-%d %H:%M:%E9S",  tz ="GMT"),
                         nanotime('2011-12-05 08:30:00.700',format ="%Y-%m-%d %H:%M:%E9S",  tz ="GMT"),
                         nanotime('2011-12-05 08:30:00.825',format ="%Y-%m-%d %H:%M:%E9S",  tz ="GMT")))
DT[, pt := as.POSIXct(ts)]
DT[, millis := as.numeric(pt - trunc(pt)) * 1e6]

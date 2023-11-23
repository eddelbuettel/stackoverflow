
startTxt <- "2023-11-22 22:23:24"   # some time last eve
endTxt <- "2023-11-23 07:08:09"     # some time this morning

## parse
startT <- as.POSIXct(startTxt)
endT <- as.POSIXct(endTxt)

## difftime
difftime(endT, startT)
## difftime in hours (explicitly selected)
difftime(endT, startT, unit="hour")
## difftime in min
difftime(endT, startT, unit="min")
## difftime in sec
difftime(endT, startT, unit="sec")

sprintf("Numerically %f %f %f\n",
        as.numeric(difftime(endT, startT, unit="hour")),
        as.numeric(difftime(endT, startT, unit="min")),
        as.numeric(difftime(endT, startT, unit="sec")))

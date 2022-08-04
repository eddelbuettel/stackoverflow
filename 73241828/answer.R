
mydat <- data.frame(time_stamp=c("2022-08-01 05:00:00 UTC","2022-08-01 17:00:00 UTC","2022-08-02 22:30:00 UTC",
                                 "2022-08-04 05:00:00 UTC","2022-08-05 02:00:00 UTC"),
                    timezone=c("America/Chicago","America/New_York","America/Los_Angeles","America/Denver","America/New_York"))

mydat$utc <- anytime::utctime(mydat$time_stamp, tz="UTC")
mydat$format <- ""
for (i in seq_len(nrow(mydat)))
    mydat[i, "format"] <- strftime(mydat[i,"utc"], "%Y-%m-%d %H:%M:%S", tz=mydat[i,"timezone"])

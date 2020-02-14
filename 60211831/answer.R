

dates <- c("2/12/2020", "2/11/2020", "2/10/2020", "2/7/2020", "2/6/2020", "2/5/2020")
Dates <- anytime::anydate(dates)
dow   <- weekdays(Dates)
cnt   <- (as.integer(format(Dates, "%d")) - 1)  %/% 7 + 1

res <- data.frame(dt=Dates, dow=dow, cnt=cnt)
res

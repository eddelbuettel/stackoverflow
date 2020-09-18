
yearyearday <- function(yr, yd) {
    base <- as.Date(paste0(yr, "-01-01")) # take Jan 1 of year
    day <- base + yd - 1
}

set.seed(42)  # make it reproducible
sample <- data.frame(year=1980:2020, doy=as.integer(rnorm(41, mean=91.1, sd=9.65)))

sample$date <- yearyearday(sample$year, sample$doy)

head(sample)

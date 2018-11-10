
set.seed(1234)
x <- rnorm(120)
d <-.07
y <- cumsum(x+d)*-1

my.ts <- ts(y, start=c(2007, 1), end=c(2017, 12), frequency=12)
tsp <- attributes(my.ts)$tsp
dates <- seq(as.Date("2007-01-01"), by = "month", along = my.ts)
plot(my.ts, xaxt = "n", main= "Plotting outcome over time",
     ylab="outcome", xlab="time")
axis(1, at = seq(tsp[1], tsp[2], along = my.ts), labels = format(dates, "%Y-%m"))
abline(v=2012, col="blue", lty=2, lwd=2)

## alternative
library(rtsplot)
library(xts)
xx <- as.xts(my.ts)
rtsplot(xx, main= "Plotting outcome over time")
rtsplot.x.highlight(xx, which(index(xx)=="Jan 2012"), 1)

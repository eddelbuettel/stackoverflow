
## data
create_t <- c(1489527029, 1533734197, 1533734197)

## as datetime
as.POSIXct(create_t, origin="1970-01-01")

## extract year
format(as.POSIXct(create_t, origin="1970-01-01"), "%Y")

## extract year as integer
as.integer(format(as.POSIXct(create_t, origin="1970-01-01"), "%Y"))

## alternate via data.table
library(data.table)
D <- data.table(create_t = create_t)
D[, pt := as.POSIXct(create_t, origin="1970-01-01")][, y := year(pt)]
D

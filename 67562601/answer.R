
date2 <- c('01/01/2000','08/08/2000','16/03/2001','25/12/2000','29/02/2000')
dd <- as.Date(date2, "%d/%m/%Y")
yd <- format(dd, "%Y-01-01")
dt <- as.Date(yd)
D <- data.frame(date2=date2, date=dd, y=yd, d=dt)
D

## second answer
date2 <- c('01/01/2000','08/08/2000','16/03/2001','25/12/2000','29/02/2000')
pd <- as.Date(date2, "%d/%m/%Y")
td <- as.Date(trunc(as.POSIXlt(pd), "years"))
D <- data.frame(input = date2,
                parsed = pd,
                output = td)
D

## one-liner
as.Date(trunc(as.POSIXlt( as.Date(date2, "%d/%m/%Y") ), "years"))

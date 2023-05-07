
ts <- xts(x = x,  order.by = as.Date(rownames(x), "%m/%d/%Y"))
ts

m <- matrix(rep(coredata(ts)[1,], nrow(ts)), ncol = 2, byrow = TRUE)
m

coredata(ts) <- coredata(ts) / m
ts


library(data.table)
mat1 <- data.table(x=1:5, y1=2:6)  ## an example
mat2 <- data.table(x=3:7, y2=3:7)  ## an example
mat1[mat2, on="x", nomatch=NULL]

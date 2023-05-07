library(xts)

file <- "http://s3.amazonaws.com/assets.datacamp.com/production/course_1127/datasets/tmp_file.csv"
x <- read.csv(file = file)
ts <- xts(x = x,  order.by = as.Date(rownames(x), "%m/%d/%Y"))
cd=coredata(ts)
for (j in 1:length(names(ts)))  cd[,j]<-cd[,j]/cd[1,j]
for (j in 1:length(names(ts))) ts[,j]<-cd[,j]

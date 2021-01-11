library(data.table)
df <- data.frame(Gender = c("F", "M", "F", "M", "M", "M", "M", "F", "M", "M"),
                 Young = c("Y", "N", "Y", "N", "Y", "N", "Y", "N", "Y", "N"),
                 Age = c("14", "25", "13", "24", "14", "25", "13", "24", "10", "26"),
                 Location = c("Suburb", "Rural", "Suburb", "Rural","Suburb", "Rural","Suburb", "Rural","Suburb", "Rural"))
setDT(df)                        # make it a data.table
df[,Age:=as.integer(Age)]        # correct age column
df[,.(mean=mean(Age), median=median(Age), max=max(Age), min=min(Age)), by=.(Gender,Location)]
df[,.(mean=mean(Age), median=median(Age), max=max(Age), min=min(Age)), by=.(Gender)]
df[,.(mean=mean(Age), median=median(Age), max=max(Age), min=min(Age)), by=.(Location)]

melt(df, id.vars="Age")[, .(mean=mean(Age),
                            median=median(Age),
                            min=min(Age),
                            max=max(Age)), by=.(variable,value)]

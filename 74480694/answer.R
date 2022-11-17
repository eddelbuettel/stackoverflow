library(datasets)
data(EuStockMarkets)
head(EuStockMarkets)

DF <- data.frame(DAX_level=EuStockMarkets[,"DAX"], SMI_level=EuStockMarkets[,"SMI"])
DF <- within(DF, DAX_SMI_spread <- DAX_level - SMI_level)
head(DF)

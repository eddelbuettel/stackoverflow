library(httr)
library(jsonlite)
library(RcppSimdJson)
library(rbenchmark)
data <- GET("https://finnhub.io/api/v1/stock/candle?symbol=AAPL&resolution=1&from=1572651390&to=1572910590&token=btj392748v6p9f1po5vg")
benchmark(value1 <- fromJSON(rawToChar(data$content)),
          value2 <- RcppSimdJson::fparse(data$content), replications=1000)[,1:4]

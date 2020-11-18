library(DBI)
suppressMessages(library(RPostgreSQL))
drv <- dbDriver("PostgreSQL")
conn <- dbConnect(drv, dbname="beancounter")

#conn <- dbConnect(drv = RPostgreSQL::PostgreSQL(), dbname = "my_db", host = "localhost")
mydf <- data.frame(column_1 = c("A", "B", "C"), column_2 = c(1, Inf, 3))
dbWriteTable(conn, "mytable", mydf, row.names = FALSE)
from_df <- dbReadTable(conn, "mytable")
from_df

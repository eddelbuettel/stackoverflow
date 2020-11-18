library(DBI)
suppressMessages(library(RPostgreSQL))
drv <- dbDriver("PostgreSQL")
conn <- dbConnect(drv, dbname="my_local_db_name_here")

mydf <- data.frame(column_1 = c("A", "B", "C"), column_2 = c(1, Inf, 3))
dbWriteTable(conn, "mytable", mydf, row.names = FALSE)
from_df <- dbReadTable(conn, "mytable")
from_df

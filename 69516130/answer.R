text <- "Mon May 11 22:51:27 2013
Mon May 11 22:58:34 2013
Wed May 13 23:15:27 2013
Thu May 14 04:11:22 2013
Sat May 16 19:46:55 2013
Sat May 16 22:29:54 2013
Sun May 17 02:08:45 2013
Sun May 17 23:55:15 2013
Mon May 18 00:42:07 2013"

data <- read.table(text=text, sep='\n', col.names="dates")
data$parse <- anytime::anytime(data$dates)
data$week <- as.integer(format(data$parse, "%V"))

data

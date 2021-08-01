url <- "https://www.cboe.com/available_weeklys/get_csv_download/"
download.file(url, "weeklysmf.csv", quiet=TRUE)
## awk -F, 'NF==2 {print $0}' weeklysmf.csv |head
dat <- data.table::fread(cmd="awk -F, 'NF==2 {print $0}' weeklysmf.csv")
dat

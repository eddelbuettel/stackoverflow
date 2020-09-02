
df <- data.frame(my_date = c("03-05-2020", "04-05-2020", "05-05-2020", "06-05-2020"))

df$parsed <- strptime(df$my_date, "%d-%m-%Y")

df$nice_dates <- format(df$parsed, "%d/%m/%Y")

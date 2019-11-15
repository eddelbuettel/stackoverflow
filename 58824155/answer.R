

df <- data.frame(DateOfBirth=c("4/4/1967 12:00:00 AM", "4/4/1967 12:00:00 AM",
                               "11/1/2001 12:00:00 AM"))

df$date <- anytime::anydate(df$DateOfBirth)

df

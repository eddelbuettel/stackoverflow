
df <- data.frame(t=ISOdatetime(2019, 1, 1, 10, 0, 0) + 0:9*60, v=LETTERS[1:10])
df
df[ df$t > ISOdatetime(2019, 1, 1, 10, 2, 0) & df$t < ISOdatetime(2019, 1, 1, 10, 9, 0), ]

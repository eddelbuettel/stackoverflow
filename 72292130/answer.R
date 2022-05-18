
## re-create your data
dat <- read.table(text="ID  Timestamp               X_mean      X_min   X_max
1   2021-06-30T08:00:00Z    -0.4313333  -5.914  4.129
2   2021-06-30T08:00:01Z    -0.3817667  -5.641  4.082
3   2021-06-30T08:00:02Z    -0.2770667  -0.484  -0.109
4   2021-06-30T08:00:03Z    -0.3686667  -0.863  -0.148
5   2021-06-30T08:00:04Z    -0.2696667  -0.41   -0.102
6   2021-06-30T08:00:05Z    -0.4150000  -0.734  -0.145", header=TRUE)

## add a Datetime column
dat$datetime <- anytime::anytime(dat$Timestamp)

## look at dat
dat

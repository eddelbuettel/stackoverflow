
## lookup

dow <- 1:7
names(dow) <- c("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",  "Friday", "Saturday")

dow["Thursday"]

unname(dow["Thursday"])

## switch
dow <- function(d) {
    switch(d,
    Sunday    = 1,
    Monday    = 2,
    Tuesday   = 3,
    Wednesday = 4,
    Thursday  = 5,
    Friday    = 6,
    Saturday  = 7)
}

dow("Monday")
dow("Friday")

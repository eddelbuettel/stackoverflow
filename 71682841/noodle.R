
library(dplyr)
library(stringr)

set.seed(1)

data_set_A <- tibble(name =  unique(replicate(2000, paste(sample(letters, runif(1, 3, 10), replace = T), collapse = "")))) %>%
  mutate(ID_A = 1:n())

set.seed(2)

data_set_B <- tibble(name_2 =  unique(replicate(2000, paste(sample(letters, runif(1, 3, 10), replace = T), collapse = "")))) %>%
  mutate(ID_B = 1:n())


library(data.table)
da <- data.table(data_set_A)
db <- data.table(data_set_B)

## no good idea

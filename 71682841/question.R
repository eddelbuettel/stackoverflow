
library(dplyr)
library(stringr)

set.seed(1)

data_set_A <- tibble(name =  unique(replicate(2000, paste(sample(letters, runif(1, 3, 10), replace = T), collapse = "")))) %>% 
  mutate(ID_A = 1:n())
                    
set.seed(2)

data_set_B <- tibble(name_2 =  unique(replicate(2000, paste(sample(letters, runif(1, 3, 10), replace = T), collapse = "")))) %>% 
  mutate(ID_B = 1:n())


## This is almost instant
data_set_A %>%
  rowwise() %>%
  filter(any(name %in% data_set_B$name_2) | any(data_set_B$name_2 %in% name)) %>%
  ungroup()

## This takes way too long
data_set_A %>%
  rowwise() %>%
  filter(any(str_detect(name, data_set_B$name_2)) | any(str_detect(data_set_B$name_2, name))) %>%
  ungroup()
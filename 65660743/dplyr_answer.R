library(dplyr)
library(tidyr)

df <- type.convert(df, as.is = TRUE)

df %>%
  pivot_longer(cols = -Age) %>%
  group_by(name, value) %>%
  summarise(min_age = min(Age),
            max_age = max(Age),
            median_age = median(Age),
            mean_age = mean(Age))

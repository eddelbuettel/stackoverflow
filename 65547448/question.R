library(plotly)
library(ggplot2)

set.seed(42)
var_1 <- rnorm(100,10,5)
var_2 <- sample( LETTERS[1:4], 100, replace=TRUE, prob=c(0.1, 0.2, 0.65, 0.05) )

df <- data.frame(var_1, as.factor(var_2))

p5 <- plot_ly(df, y = ~var_1, color = ~var_2, type = "box") %>%
    layout(title = "Income by career stage",
           xaxis = list(title = "Stage", zeroline = FALSE),
           yaxis = list(title = "Income", zeroline = FALSE))
p5

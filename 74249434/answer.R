
set.seed(42)
d <- data.frame(Date=as.Date("2022-01-01")+0:29,
                Proportion=cumsum(rnorm(30)),
                Group=sample(1:2, 30, TRUE))0, TRUE))
head(d)

library(ggplot2)
ggplot(data = d, mapping = aes(x = Date, y = Proportion, group = 1 )) +
    geom_col(group = 1) + facet_grid(rows=vars(Group)) +
    labs(x = "Date", y = "Read proportion (%)") + theme_light() +
    theme(axis.text.x = element_text(colour = "grey20",
                                     size = 6, angle = 45,
                                     hjust = 0.5, vjust = 0.5),
          axis.text.y = element_text(colour = "grey20", size = 6),
          text = element_text(size = 8))

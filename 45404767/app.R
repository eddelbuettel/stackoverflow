library(shiny)

addResourcePath("img", "www")
print(resourcePaths())

ui <- fluidPage(
    tags$img(src='/img/photo.png')
)

server <- function(input, output) {}

shinyApp(ui=ui, server=server)

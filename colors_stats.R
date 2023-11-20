
red <- c(1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36)
black <- c(2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35)

roulette_numbers <- scan("roulette_numbers.txt")

color_category <- function(roulette_numbers) {
  if(roulette_numbers %in% red) {
    return("Red")
  } else if (roulette_numbers %in% black) {
    return("Black")
  } else{
    return("other")
  }
}

categories <- sapply(roulette_numbers, color_category)

library(ggplot2) #importing the ggplot library to use

# Creating the data frame to use
data <- data.frame(Number = roulette_numbers, Category = categories)

# Making the bar chart
data2 <- (ggplot(data, aes(x = Category, fill = Category)) + geom_bar() + labs(title = "Red and Black Table Numbers") + scale_fill_manual(values = c("Red" = "red", "Black" = "black", "Other" = "other")))

# Saving the file to the images folder in the M3OEP
ggsave("red_black.pdf", plot = data2, path = "/Users/mckenziekelley/CLionProjects/M3OEP-mkelle20/images")

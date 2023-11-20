# This code makes charts showing high and low numbers pulled using Python

import matplotlib.pyplot as plt

# Text file to use to create the graph
file_name = "roulette_numbers.txt"

# Defining the ranges for the numbers (low numbers are 1-18, high numbers are 19-36)
low_range = (1,18)
high_range = (19,36)

# Making empty lists to separate the low and high numbers
low_val = []
high_val = []

with open(file_name, "r") as file:
    for line in file:
        value = int(line.strip())
        if low_range[0] <= value <= low_range[1]:
            low_val.append(value)
        elif high_range[0] <= value <= high_range[1]:
            high_val.append(value)

# You can un-comment these to see the values in their respective categories printed out
#print("Low values: ",low_val)
#print("High values: ",high_val)

# Creating graphs from the low and high values
categories = ['Low (1 - 18)', 'High (19 - 36)']
counts = [len(low_val), len(high_val)]

# Creating the bar chart with matplotlib
plt.bar(categories, counts, color=['blue','green'])
plt.xlabel('Category')
plt.ylabel('Count')
plt.title('Low and High Table Numbers')
plt.show()


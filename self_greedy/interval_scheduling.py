# List of intervals
intervals = [(1, 3), (2, 5), (7, 12), (9, 13),(14, 16), (6, 18)]

# Sort intervals based on finish times
intervals.sort(key=lambda x: x[1])

# Initialize variables
count = 0
end = 0
selected_intervals = []

# Iterate through sorted intervals
for interval in intervals:
    if end <= interval[0]:  # Check for compatibility
        selected_intervals.append(interval)
        
        count += 1
        end = interval[1]  
        print("selected", interval[1])
    else:
        print("conflict at", interval)# Update end to current interval's finish time

print("Maximum number of non-conflicting intervals:", count)
print("Selected intervals:", selected_intervals)

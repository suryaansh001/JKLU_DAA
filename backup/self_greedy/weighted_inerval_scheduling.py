weighted_inervals=[(0, 6, 60), (1, 4, 30), (3, 5, 10), (5, 7, 30), (5, 9, 50), (7, 8, 10)]
# Sort intervals based on finish times
weighted_inervals.sort(key=lambda x: x[1])

# Initialize variables
count = 0
end = 0
selected_intervals = []

# Iterate through sorted intervals
for interval in weighted_inervals:
    if end <= interval[0]:  # Check for compatibility
        selected_intervals.append(interval)
        
        count += interval[2]
        end = interval[1]  
        print("selected", interval[1])
    else:
        print("conflict at", interval)

print("Maximum number of non-conflicting intervals:", count)
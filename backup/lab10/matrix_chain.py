def chain_multi(lis, i, j, split_points):
    if i + 1 == j:
        return 0
    min_cost = float('inf')
    for k in range(i + 1, j):
        cost = (chain_multi(lis, i, k, split_points) +
                chain_multi(lis, k, j, split_points) +
                lis[i] * lis[k] * lis[j])
        if cost < min_cost:
            min_cost = cost
            split_points[i][j] = k  
    return min_cost


def print_parentheses(split_points, i, j):
    if i + 1 == j:
        return f"M{i+1}"
    k = split_points[i][j]
    left = print_parentheses(split_points, i, k)
    right = print_parentheses(split_points, k, j)
    return f"({left} x {right})"


# Example usage
lis = [2, 2, 3, 4]
n = len(lis) - 1
split_points = [[0] * (n + 1) for _ in range(n + 1)]  # To store split points

min_cost = chain_multi(lis, 0, n, split_points)
parentheses = print_parentheses(split_points, 0, n)

print("Minimum multiplications:", min_cost)
print("Optimal parenthesization:", parentheses)
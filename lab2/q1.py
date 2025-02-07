import random as rand

def mod_exp(base, exponent, p):
    result = 1
    while exponent > 0:
        if exponent % 2 == 1:  # If exponent is odd
            result = (result * base) % p
        base = (base * base) % p  # Square the base
        exponent //= 2  # Divide the exponent by 2
    return result

def fermat_little_theorem(a, p):
    # Ensure that a is less than p and not divisible by p
    if a >= p or a % p == 0:
        return False
    # Using Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p)
    res = mod_exp(a, p - 1, p)
    return res == 1

# Example usage
# Choose a random value for a that is less than p and not divisible by p
p = rand.choice([2, 3, 5, 7, 11, 13, 17, 19, 23, 29])
a = rand.randint(1, p - 1)  # a should be less than p
while a % p == 0:  # Ensure a is not divisible by p
    a = rand.randint(1, p - 1)

print(f"Testing Fermat's Little Theorem with a={a} and p={p}: {fermat_little_theorem(a, p)}")

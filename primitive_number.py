# p = 2q+1 - формула надёжного простого числа, где q - также простое число
# a^[(p-1)/2] != 1 && a^[(p-1)/5] != 1 => a - первообразный корень

p = 11 # p - надёжное простое число

print(f"(a^i) mod (p={p})\n")

print(end="\t")
for i in range(1, p):
    print(f"i={i}", end="\t")
print()

for a in range(1, p):
    print(f"a={a}", end="\t")
    for i in range(1, p):
        print((a**i)%p, end="\t")
    print()

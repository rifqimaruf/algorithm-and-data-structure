import math

physics = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]

mx = sum(physics) / len(physics)
my = sum(history) / len(history)

num = sum((x - mx) * (y - my) for x, y in zip(physics, history))
den = math.sqrt(
    sum((x - mx) ** 2 for x in physics) * sum((y - my) ** 2 for y in history)
)

r = num / den
print(f"{r:.3f}")

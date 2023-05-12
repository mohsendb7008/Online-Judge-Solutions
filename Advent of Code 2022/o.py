# data = [
#     (2, 18, -2, 15),
#     (9, 16, 10, 16),
#     (13, 2, 15, 3),
#     (12, 14, 10, 16),
#     (10, 20, 10, 16),
#     (14, 17, 10, 16),
#     (8, 7, 2, 10),
#     (2, 0, 2, 10),
#     (0, 11, 2, 10),
#     (20, 14, 25, 17),
#     (17, 20, 21, 22),
#     (16, 7, 15, 3),
#     (14, 3, 15, 3),
#     (20, 1, 15, 3)
# ]
# searchY = 10
# searchXRange = range(-100, 100)

data = [
    (2692921, 2988627, 2453611, 3029623),
    (1557973, 1620482, 1908435, 2403457),
    (278431, 3878878, -1050422, 3218536),
    (1432037, 3317707, 2453611, 3029623),
    (3191434, 3564121, 3420256, 2939344),
    (3080887, 2781756, 3420256, 2939344),
    (3543287, 3060807, 3420256, 2939344),
    (2476158, 3949016, 2453611, 3029623),
    (3999769, 3985671, 3420256, 2939344),
    (2435331, 2200565, 1908435, 2403457),
    (3970047, 2036397, 3691788, 1874066),
    (2232167, 2750817, 2453611, 3029623),
    (157988, 333826, -1236383, 477990),
    (1035254, 2261267, 1908435, 2403457),
    (1154009, 888885, 1070922, -543463),
    (2704724, 257848, 3428489, -741777),
    (3672526, 2651153, 3420256, 2939344),
    (2030614, 2603134, 1908435, 2403457),
    (2550448, 2781018, 2453611, 3029623),
    (3162759, 2196461, 3691788, 1874066),
    (463834, 1709480, -208427, 2000000),
    (217427, 2725325, -208427, 2000000),
    (3903198, 945190, 3691788, 1874066)
]
searchY = 2000000
searchXRange = range(-10000000, 10000000)

points = set()
for sx, sy, bx, by in data:
    points.add((sx, sy))
    points.add((bx, by))

ans = 0

for searchX in searchXRange:
    if (searchX, searchY) in points:
        continue
    for sx, sy, bx, by in data:
        if abs(searchX - sx) + abs(searchY - sy) <= abs(bx - sx) + abs(by - sy):
            ans += 1
            break

print(ans)
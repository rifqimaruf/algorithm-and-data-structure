from PIL import Image

image = Image.open("./images/Info jam buka pelayanan.png")
pixels = image.load()

width, height = image.size
print(width)
print(height)

for y in range(height):
    for x in range(width):
        r, g, b, a = pixels[x, y]
        print(f"Pixel at ({x}, {y}): RGB =({r}, {g}, {b}, {a})")

        

    
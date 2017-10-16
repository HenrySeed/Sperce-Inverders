from PIL import Image

img = Image.open('test.bmp')


img.load()
width, height = img.size
lines = [] * height

for row in range(height):
    line = []
    for col in range(width):
        a = img.getpixel((col,row))
        line.append(a)

    lines.append(line)

output_str = ""

for row in lines:
    row_str = "{"
    for col in row:
        row_str += str(col) + ", "

    row_str = row_str[0:-2]
    row_str += "},\n"

    output_str += row_str

output_str = output_str[:-2]

output_str += "};"

output_str = output_str.replace('(', '{')
output_str = output_str.replace(')', '}')

print(output_str)

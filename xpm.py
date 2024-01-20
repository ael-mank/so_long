from PIL import Image
import re

def resize_xpm(xpm_path, new_size):
    # Read the XPM file
    with open(xpm_path, 'r') as file:
        xpm_data = file.readlines()

    # Find the header line index
    header_index = 0
    for i, line in enumerate(xpm_data):
        if re.match(r'"\d+ \d+ \d+ \d+ "', line):
            header_index = i
            break

    # Parse the XPM header
    header = re.findall(r'\d+', xpm_data[header_index])
    width, height, colors, chars_per_pixel = map(int, header[:4])

    # Extract color definitions
    color_defs = {}
    color_defs_reversed = {}
    color_regex = re.compile(r'"(.{1,' + str(chars_per_pixel) + '}) c (#\S+)"')
    for i in range(header_index + 1, header_index + 1 + colors):
        match = color_regex.match(xpm_data[i])
        if match:
            pixel, color = match.groups()
            color_defs[pixel] = color
            color_defs_reversed[color] = pixel

    # Create a new image
    image = Image.new('RGB', (width, height))
    for y in range(height):
        row = xpm_data[header_index + colors + y + 1].strip().strip('"')
        for x in range(width):
            pixel = row[x * chars_per_pixel: (x + 1) * chars_per_pixel]
            if pixel in color_defs:
                image.putpixel((x, y), tuple(int(color_defs[pixel][i:i+2], 16) for i in (1, 3, 5)))

    # Resize the image
    resized_image = image.resize((new_size, new_size), Image.NEAREST)

    # Convert the resized image to XPM format
    resized_xpm_data = []
    for y in range(new_size):
        row = ''
        for x in range(new_size):
            pixel = resized_image.getpixel((x, y))
            hex_color = '#' + ''.join([f'{c:02x}' for c in pixel])
            row += color_defs_reversed.get(hex_color, ' ')
        resized_xpm_data.append('"' + row + '"')

    # Save the resized image as XPM
    resized_xpm_path = xpm_path.replace('.xpm', f'_{new_size}x{new_size}.xpm')
    with open(resized_xpm_path, 'w') as file:
        file.write('/* XPM */\n')
        file.write('static char *xpm_data[] = {\n')
        file.write(f'"{new_size} {new_size} {colors} {chars_per_pixel}",\n')
        for line in xpm_data[header_index + 1: header_index + 1 + colors]:
            file.write(line)
        for line in resized_xpm_data:
            file.write(line + ',\n')
        file.write('};')

    print(f'Resized XPM saved as {resized_xpm_path}')
# Example usage
resize_xpm('assets/rock.xpm', 50)
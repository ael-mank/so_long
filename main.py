from PIL import Image

# Load the image
with Image.open('assets/borders.png') as img:
    # Scale the image to 250x250
    img_resized = img.resize((100, 100), resample=Image.NEAREST)

    # Save the resized image
    output_path = 'assets/borders_resized.png'
    img_resized.save(output_path)

output_path

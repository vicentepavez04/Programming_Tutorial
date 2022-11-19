from PIL import Image

def get_concat_h(im1, im2):
    dst = Image.new('RGB', (im1.width + im2.width, im1.height))
    dst.paste(im1, (0, 0))
    dst.paste(im2, (im1.width, 0))
    return dst

def get_concat_v(im1, im2):
    dst = Image.new('RGB', (im1.width, im1.height + im2.height))
    dst.paste(im1, (0, 0))
    dst.paste(im2, (0, im1.height))
    return dst


if __name__ == "__main__":

    im1_path = "./image1.jpg"
    im2_path = "./image2.jpg"
    dst_path= "./result.jpg"
    
    im1 = Image.open(im1_path)
    im2 = Image.open(im2_path)

    # HORIZONTAL
    get_concat_h(im1, im1).save(dst_path)
    # VERTICAL
    get_concat_v(im1, im1).save(dst_path)
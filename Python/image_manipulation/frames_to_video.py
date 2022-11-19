import cv2
import os

def videomaker(folder_path, dst_path, FPS):

    print("Making Video from plots")
    img_array = []
    lista = os.listdir(folder_path)
    lista.sort()

    for filename in lista:
        if not filename.endswith((".jpg", ".png" )):
            continue

        img_path = os.path.join(folder_path, filename)
        print(filename)
        img = cv2.imread(img_path)
        height, width, layers = img.shape
        size = (width,height)
        img_array.append(img)

    out = cv2.VideoWriter(dst_path, cv2.VideoWriter_fourcc(*'DIVX'), FPS, size)

    for i in range(len(img_array)):
        out.write(img_array[i])
    out.release()
    print("Video made successfully")

if __name__ == "__main__":

    FPS = 5
    folder_path = "/frames_for_the_video/"
    dst_path = 'result_final_v2_hd_3.mp4'
    
    videomaker(folder_path, dst_path, FPS)

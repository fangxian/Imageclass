import cv2

img=cv2.imread('testimg.JPG')
cv2.imshow('img',img)
rows,cols,channels=img.shape
dst=img.copy()

a=2.45
b=100
for i in range(rows):
    for j in range(cols):
        for c in range(3):
            color=img[i,j][c]*a+b
            if color>255:
                dst[i,j][c]=255
            elif color<0:
                dst[i,j][c]=0
cv2.imshow('dst',dst)
cv2.imwrite('incimg.jpg', dst)


cv2.waitKey(0)
cv2.destroyAllWindows()
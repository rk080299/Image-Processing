import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",help = "path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])

hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
lower_red = np.array([110,50,50])
upper_red = np.array([130,255,255])

# lower_red = np.array([110,50,50])
# upper_ = np.array([130,255,255])


#this is for red, blue green ad gray respectively
# boundaries = [
# 	([17, 15, 100], [50, 56, 200]),
# 	([86, 31, 4], [220, 88, 50]),
# 	([25, 146, 190], [62, 174, 250]),
# 	([103, 86, 65], [145, 133, 128])
# ]

# for (lower,upper) in boundaries:
# lower = np.array(lower,dtype = 'uint8')
# upper = np.array(upper, dtype = 'uint8')
mask = cv2.inRange(image,lower,upper)
output = cv2.bitwise_and(image, image, mask = mask)
cv2.imshow("images", np.hstack([image, output]))
cv2.waitKey(0)

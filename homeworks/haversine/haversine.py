import time
import json 
from math import radians, sin, cos, sqrt, asin

JSON_FILE = open("_points.json")

START_TIME = time.time()
INPUT = json.load(JSON_FILE)
MID_TIME = time.time()
R = 6371

def HaversineOfDegrees(x0, y0, x1, y1):
    dY = radians(y1 - y0)
    dX = radians(x1 - x0)
    y0 = radians(y0)
    y1 = radians(y1)
    RootTerm = (sin(dY/2)**2)*cos(y0)*cos(y1)*(sin(dX/2)**2)
    Result = 2*R*asin(sqrt(RootTerm))
    return Result 

Sum = 0
Count = 0
for Pair in INPUT['pairs']:
    Sum += HaversineOfDegrees(Pair['x0'], Pair['y0'], Pair['x1'], Pair['y1'])
    Count += 1
Average = Sum / Count
END_TIME = time.time()


print("Result: " + str(Average))
print("Input: " + str(MID_TIME - START_TIME) + " seconds")
print("Math: " + str(END_TIME - MID_TIME) + " seconds")
print("Total: " + str(END_TIME - START_TIME) + " seconds")
print("Throughtput: " + str(Count/(END_TIME-START_TIME)) + " haversines/second")

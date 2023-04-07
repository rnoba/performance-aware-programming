import fs from "node:fs" 

JSON_FILE = await fs.readFileSync("./_points.json", "utf8") 

START_TIME = Date.now()
INPUT = JSON.parse(JSON_FILE)
MID_TIME = Date.now()

function radians(deg) {
    return deg * (Math.PI/180);
}

function HaversineOfDegrees(x0, y0, x1, y1, R) {
    dY = radians(y1 - y0)
    dX = radians(x1 - x0)
    y0 = radians(y0)
    y1 = radians(y1)
    RootTerm = (Math.sin(dY/2)**2)*Math.cos(y0)*Math.cos(y1)*(Math.sin(dX/2)**2)
    Result = 2*R*Math.asin(Math.sqrt(RootTerm))
    return Result
}

EarthRadiusKm = 6371
Sum = 0
Count = 0

for(const value of INPUT['pairs']) {
    Sum += HaversineOfDegrees(Pair['y0'], Pair['x0'], Pair['y1'], Pair['x1'], EarthRadiusKm)
    Count += 1
}

Average = Sum / Count
END_TIME = Date.now()

console.log("Result: " + str(Average))
console.log("Input: " + str(MID_TIME - START_TIME) + " seconds")
console.log("Math: " + str(END_TIME - MID_TIME) + " seconds")
console.log("Total: " + str(END_TIME - START_TIME) + " seconds")
console.log("Throughtput: " + str(Count/(END_TIME-START_TIME)) + " haversines/second")

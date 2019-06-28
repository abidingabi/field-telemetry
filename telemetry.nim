import math
import stats

type 
    Row = seq[char]

type 
    Telemetry* = seq[Row] 

type 
    Point* = object
        x*: int
        y*: int 

proc createTelemetry*(xSize: int, ySize: int): Telemetry = 
    var row: Row
    for i in 0..<xSize:
        row.add('0')
    
    for i in 0..<ySize:
        result.add(row)

proc `$`*(telemetry: Telemetry): string = 
    for x in 0..<telemetry.len:
        for y in 0..<telemetry[x].len:
            result.add(telemetry[x][y])
        result.add("\n")

proc `$`*(point: Point): string =
    result = "x: " & $point.x & ", y: " & $point.y 

proc set*(telemetry: Telemetry, x: int, y: int, character: char): Telemetry =
    result = telemetry
    result[y][x] = character

proc xSize(telemetry: Telemetry): int =
    result = telemetry[0].len

proc ySize(telemetry: Telemetry): int =
    result = telemetry.len

proc drawLineAbsolute*(telemetry: Telemetry, point1: Point, point2: Point, character: char): Telemetry = 
    let firstPoint = if (point1.x < point2.x): point1 else: point2
    let secondPoint = if (point1.x > point2.x): point1 else: point2
    
    let slope = if point2.x - point1.x != 0: 
                    (point2.y - point1.y).float / (point2.x - point1.x).float 
                else: 500000000.0 
                # If x is the same, their will be a divide by zero; instead we just substitute a high number



    let intercept = firstPoint.y.float - (slope*firstPoint.x.float) 

    echo "Slope: " & $slope
    echo "Intercept: " & $intercept

    result = telemetry

    for x in firstPoint.x..secondPoint.x:
        let y = round(x.float*slope+intercept).int

        echo "x: " & $x
        echo "y: " & $y

        result = result.set(x, y, character)

#takes percentages as inputs
proc drawLineScaled*(telemetry: Telemetry, x1: float, y1: float, x2: float, y2: float, center: Point, zoom: float, character: char): Telemetry = 
    let adjustedX1 = x1 * telemetry.xSize.float
    let adjustedX2 = x2 * telemetry.xSize.float
    let adjustedY1 = (1 - y1) * telemetry.xSize.float * 0.53
    let adjustedY2 = (1 - y2) * telemetry.xSize.float * 0.53
    
    let centerX = (-center.x.float) * telemetry.xSize.float
    let centerY = (-center.y.float*0.53) * telemetry.xSize.float
        
    var realX1 = (x1 - centerX) * zoom + telemetry.xSize / 2
    var realX2 = (x2 - centerX) * zoom + telemetry.xSize / 2
    var realY1 = ((y1-centerY) * zoom) + telemetry.xSize / 2
    var realY2 = ((y2-centerY) * zoom) + telemetry.xSize / 2
    
    # rewrite this in nim then you finish this method drawLine((int) real_x1,(int) real_y1,(int) real_x2,(int) real_y2, r,g,b, myChar);
    

proc drawField(center: Point, zoom: float): Telemetry = createTelemetry(1, 1) # finish this idiot

when isMainModule:
    discard ""
    #echo $(createTelemetry(12, 12).drawLineScaled(
    #   Point(x: 7, y: 2), Point(x: 4, y: 7), '|'
    #))
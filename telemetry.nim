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

proc `set`*(telemetry: Telemetry, x: int, y: int, character: char): Telemetry =
    result = telemetry
    result[y][x] = character

proc drawLineAbsolute(telemetry: Telemetry, point1: Point, point2: Point, character: char): Telemetry = 
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

when isMainModule:
    echo $(createTelemetry(12, 12).drawLineAbsolute(
       Point(x: 7, y: 2), Point(x: 4, y: 7), '|'
    ))
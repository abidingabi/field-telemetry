import math
from strutils import replace


type 
    Row = seq[char]

type 
    Telemetry* = seq[Row] 

type 
    Point* = object
        x*: int
        y*: int 

proc createTelemetry*(xSize: int, ySize: int): Telemetry = 
    var row: Row = @[]
    for i in 0..<xSize:
        row.add(' ')
    
    result = @[]
    for i in 0..<ySize:
        result.add(row)

proc `$` (telemetry: Telemetry): string = 
    var myString = ""
    for x in 0..<telemetry.len:
        for y in 0..<telemetry[x].len:
            myString.add(telemetry[x][y])
        myString.add("\n")
    result = myString

proc `$`*(point: Point): string =
    result = "x: " & $point.x & ", y: " & $point.y 

proc set*(telemetry: Telemetry, x: int, y: int, character: char): Telemetry =
    result = telemetry
    result[y][x] = character

proc xSize(telemetry: Telemetry): int =
    result = telemetry[0].len

proc ySize(telemetry: Telemetry): int =
    result = telemetry.len

iterator lines(telemetry: Telemetry): string =
    for i in 0..<telemetry.ySize:
        let row = telemetry[i]
        yield cast[string](row)

proc drawLineAbsolute*(telemetry: Telemetry, point1: Point, point2: Point, character: char): Telemetry = 
    result = telemetry
    let startPoint = Point(x: min(point1.x, point2.x), y: min(point1.y, point2.y))
    let endPoint = Point(x: max(point1.x, point2.x), y: max(point1.y, point2.y))

    let slope = if endPoint.x - startPoint.x != 0: (endPoint.y-startPoint.y) / (endPoint.x-startPoint.x) else: 5000000

    for y in 0..<endPoint.y: #BIG BUG HERE
        for x in 0..<endPoint.x:
            let idealX = round((y-startPoint.y).float * slope + startPoint.x.float)
            let idealY = round((x-startPoint.x).float * slope + startPoint.y.float)

            if abs(idealY - y) < 1 or abs(idealX - x) < 1:
                echo "X: " & $x & " , Y: " & $y
                result = result.set(x,y,character)


#takes percentages as inputs
proc drawLineScaled*(telemetry: Telemetry, x1: float, y1: float, x2: float, y2: float, centerX: float, centerY: float, zoom: float, character: char): Telemetry = 
    let adjustedX1 = x1 * telemetry.xSize.float
    let adjustedX2 = x2 * telemetry.xSize.float
    let adjustedY1 = (1 - y1) * telemetry.xSize.float
    let adjustedY2 = (1 - y2) * telemetry.xSize.float
    
    let centerX = (-centerX.float) * telemetry.xSize.float
    let centerY = (-centerY.float) * telemetry.xSize.float
    
    let realX1 = (adjustedX1 - centerX) * zoom - (telemetry.xSize / 2).float
    let realX2 = (adjustedX2 - centerX) * zoom - (telemetry.xSize / 2).float 
    let realY1 = ((adjustedY1-centerY) * zoom) - (telemetry.xSize / 2).float 
    let realY2 = ((adjustedY2-centerY) * zoom) - (telemetry.xSize / 2).float 

    let point1 = Point(x: realX1.int, y: realY1.int) 
    let point2 = Point(x: realX2.int, y: realY2.int)

    echo "point 1: " & $point1    
    echo "point 2: " & $point2


    result = telemetry.drawLineAbsolute(point1, point2, character)

proc drawWalls(telemetry: Telemetry, zoom: float): Telemetry =
    const wallChar = '#'
    result = telemetry.drawLineScaled(0,0, 1, 0, 0.5,0.5, zoom, wallChar)
    result = result.drawLineScaled(1,1, 1, 0, 0.5,0.5, zoom, wallChar)
    result = result.drawLineScaled(0,0, 0, 1, 0.5,0.5, zoom, wallChar)
    result = result.drawLineScaled(0,1, 1, 1, 0.5,0.5, zoom, wallChar)
    result = result.drawLineScaled(0,1, 1, 1, 0.5,0.5, zoom, wallChar)


proc drawField(centerX: float, centerY: float, zoom: float, xSize: int, ySize: int): Telemetry = 
    result = createTelemetry(xSize,ySize).drawWalls(zoom)    

when isMainModule:
    let field = drawField(0.1,0.2, 1.0, 30, 30)  #createTelemetry(50,50)..drawLineAbsolute(Point(x:0,y:0),Point(x:50,y:50),'|')
    for i in field.lines:
        echo i

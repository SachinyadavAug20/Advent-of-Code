import fs from "fs/promises"


const text = await fs.readFile("input.txt", "utf-8")
let lines = text.split("\n");
let cords = [];
for (let i = 0; i < lines.length; i++) {
    cords[i] = lines[i].split(",")
}
cords.pop()
console.log(cords, cords.length)
let lowest = 0;
let distance = 0, min;
let ckts = []
for (let k = 0; k < 10; k++) {

    for (let i = 0; i < cords.length; i++) {
        for (let j = 0; j < cords.length; j++) {
            if (i == j) {
                continue;
            }

            distance = Math.sqrt((cords[i][0] - cords[j][0]) ** 2 + (cords[i][1] - cords[j][1]) ** 2 + (cords[i][2] - cords[j][2]) ** 2)
            if (i == 0 && j == 1) {
                min = distance;
            }
            if (min > distance) {
                min = distance
                ckts[k] = { p1: cords[i], p2: cords[j], points: 2 }
            }
        }
    }
    cords = cords.filter((e) => {
        return e != ckts[k].p1 && e != ckts.p2
    })
}
let no_of_connections = [];
for (let i = 0; i < ckts.length; i++) {
    for (let j = 0; j < ckts.length; j++) {
        if (i == j) {
            continue;
        }
        if (ckts[i].p1.join(",") == ckts[j].p2.join(",")) {
            ckts[i].points++;
            ckts[i].p2 = ckts[j].p1
            ckts = ckts.filter((e) => {
                return e.p1.join(",") != ckts[j].p1.join(",")
            })
        }
        else if (ckts[i].p2.join(",") == ckts[j].p1.join(",")) {
            ckts[i].points++;
            ckts[i].p1 = ckts[j].p2
            ckts = ckts.filter((e) => {
                return e.p2.join(",") != ckts[j].p2.join(",")
            })
        }
    }
}

console.log(ckts)
//stuck

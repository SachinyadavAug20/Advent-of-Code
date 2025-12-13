// --- Day 9: Movie Theater ---
//
// You slide down the firepole in the corner of the playground and land in the
// North Pole base movie theater!
//
// The movie theater has a big tile floor with an interesting pattern. Elves
// here are redecorating the theater by switching out some of the square tiles
// in the big grid they form. Some of the tiles are red; the Elves would like to
// find the largest rectangle that uses red tiles for two of its opposite
// corners. They even have a list of where the red tiles are located in the grid
// (your puzzle input).
//
// For example:
//
// 7,1
// 11,1
// 11,7
// 9,7
// 9,5
// 2,5
// 2,3
// 7,3
//
// Showing red tiles as # and other tiles as ., the above arrangement of red
// tiles would look like this:
//

import fs from "fs/promises"

const text = await fs.readFile("input.txt", "utf-8")
let lines = text.split("\n");
let cords = [];
for (let i = 0; i < lines.length; i++) {
    cords[i] = lines[i].split(",")
}
cords.pop()
cords.pop()
console.log(cords, cords.length)
let area_max = 0;
for (let i = 0; i < cords.length; i++) {
    for (let j = 0; j < cords.length && cords[i][1] < cords[j][1]; j++) {
        if (i == j) {
            continue;
        }
        let area = (Math.abs(cords[i][0] - cords[j][0]) + 1) * (Math.abs(cords[i][1] - cords[j][1]) + 1)
        let diagonal = (cords[i][0] - cords[j][0]) ** 2 + (cords[i][1] - cords[j][1]) ** 2;
        if (area > area_max) {
            area_max = area;
        }
    }
}
// let area = (Math.abs(longest_diagonal[0][0] - longest_diagonal[1][0]) + 1)* (Math.abs(longest_diagonal[0][1] - longest_diagonal[1][1]) + 1)
console.log(area_max)

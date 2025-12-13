// --- Part Two ---
//
// The Elves just remembered: they can only switch out tiles that are red or green. So, your rectangle can only include red or green tiles.
//
// In your list, every red tile is connected to the red tile before and after it by a straight line of green tiles. The list wraps, so the first red tile is also connected to the last red tile. Tiles that are adjacent in your list will always be on either the same row or the same column.
//
// Using the same example as before, the tiles marked X would be green:

import fs from "fs/promises"

const text = await fs.readFile("input.txt", "utf-8")
let lines = text.split("\n");
let cordsRedtile = [];
for (let i = 0; i < lines.length; i++) {
    if (lines[i].length <= 0) {

    } else {
        cordsRedtile[i] = lines[i].split(",")
    }
}
//for green tiles
let cordsGreentile = []
for (let i = 0; i < cordsRedtile.length; i++) {
    for (let j = 0; j < cordsRedtile[0].length; j++) {

    }
}
console.log(cordsRedtile)


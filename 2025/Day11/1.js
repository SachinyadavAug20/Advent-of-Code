import fs from "fs/promises";

const text = await fs.readFile("input.txt", "utf-8");

let lines = text
  .split("\n")
  .map(l => l.trim())
  .filter(l => l.length > 0);

let graph = {};

for (let line of lines) {
  let [from, to] = line.split(":");
  graph[from] = to.trim().split(" ");
}

function countWays(node) {
  if (node === "out") {//base case
    return 1; // one complete path found
  }

  let ways = 0;

  for (let next of graph[node]) {
    ways += countWays(next);
  }

  return ways;
}

let no_of_ways = countWays("you");

console.log(graph,"Number of ways:", no_of_ways);


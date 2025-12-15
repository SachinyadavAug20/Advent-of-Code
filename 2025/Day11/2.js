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


// let fft = 0, dac = 0;
function countWays(node, isfft, dac) {
    if (node === "out") {//base case
        if (isfft && dac) {
            return 1;
        }
        return 0;
    }

    let ways = 0;
    for (let next of graph[node] || []) {
        if (next == "fft") {
            isfft = 1;
        }
        if (next == "dac") {
            dac = 1;
        }
        ways += countWays(next, isfft, dac);
    }

    return ways;
}

let no_of_ways = countWays("svr", 0, 0);

console.log(graph, "Number of ways:", no_of_ways);

//This works on sample but it never completes execution in for real input
//I think sample loops around srv many times


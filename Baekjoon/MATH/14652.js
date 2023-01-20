let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "/Users/rua/Documents/javascript/input.txt";

let input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map((v) => + v));

const [[N, M, K]] = input;

let n = Math.floor(K / M);
let m = K % M;

console.log(n, m);
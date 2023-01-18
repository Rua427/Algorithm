const filePath = process.platform === "linux" ? "/dev/stdin" : "/Users/rua/Documents/javascript/input.txt";
const input = require('fs').readFileSync(filePath).toString().trim().split('\n');

const [N, M] = [+input[0], +input[2]];
const [hasCards, cards] = [new Set(input[1].split(' ').map(Number)), input[3].split(' ').map(Number)]

let answer = '';
for(let i = 0; i < M; i++) {
    if(hasCards.has(cards[i])) answer += 1 + ' '
    else answer += 0 + ' ';
}

console.log(answer);
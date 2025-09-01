const fs = require('fs');
const input = fs.readFileSync(0, 'utf8').trim().split('\n');

const [N, M, A, B] = input[0].split(' ').map(Number);
let x = Math.max(0, 3*N - M);
let res = 0;
if(x){
    res += A * x + B;
}
console.log(res);
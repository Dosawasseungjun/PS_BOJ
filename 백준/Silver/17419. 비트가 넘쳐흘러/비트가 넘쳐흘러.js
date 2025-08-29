const fs = require('fs');
const lines = fs.readFileSync(0, 'utf8').trim().split('\n');

const N = Number(lines[0]);
const S = lines[1].toString();

let res = 0;
for(let i=0;i<N;i++){
    if(S[i] === '1') res += 1;
}
console.log(res);
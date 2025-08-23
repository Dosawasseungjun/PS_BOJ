const fs = require('fs')
const lines = fs.readFileSync(0, 'utf8').trim().split(/\r?\n/);

let N = Number(lines[0])
const A = lines[1].trim().split(' ').map(Number);
const mod = 998244353;
let res = 1;

for(let i=0;i<N;i++){
    if(A[i] === i+1){
        res *= (N-1);
        res %= mod;
    }else{
        res *= (N-2);
        res %= mod;
    }
}

console.log(res);
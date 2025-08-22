const fs = require('fs');
const lines = fs.readFileSync(0, 'utf8').trim().split(/\r?\n/);
let N = Number(lines[0]);
const X = lines[1].trim().split(' ').map(Number);
let [now, res] = [0, 0];
for(let i=0;i<N;i++){
    let d = X[i] - now;
    if(i+1 < N && X[i+1]-X[i] === 1){
        res = -1;
        break;
    }
    if(d & 1) res += Math.ceil(d / 2);
    else res += 1 + Math.ceil(d / 2);
    now = X[i]+1;
}
console.log(res);

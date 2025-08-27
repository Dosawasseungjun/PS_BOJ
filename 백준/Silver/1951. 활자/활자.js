const fs = require('fs');
let N = Number(fs.readFileSync(0, 'utf8').trim());
let mod = 1234567;
let [x, y, z] = [0, 1, 0];
let res = 0;
for(let i=0;i<N.toString().length-1;i++){
    if(x === 0) x = 9;
    else x *= 10;
    res += x * y;
    res %= mod;
    z += x;
    y += 1;
}
res += (N-z)*y%mod;
res %= mod;
console.log(res);
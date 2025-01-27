const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').toString().split('\n');
const [h, w, x, y] = input[0].split(' ').map(Number);
const B = [];
for(let i=0;i<h+x;i++){
    const tmp = input[1+i].split(' ').map(Number);
    B.push(tmp);
}

const A = Array(h).fill().map(() => Array(w).fill(0));
for(let i=0;i<h;i++){
    for(let j=0;j<w;j++){
        if(i < x || j < y) A[i][j] = B[i][j];
        else A[i][j] = B[i][j] - A[i-x][j-y];
    }
}

A.map((list) => console.log(list.join(' ')));
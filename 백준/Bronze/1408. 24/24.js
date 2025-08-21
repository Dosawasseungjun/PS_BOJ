const fs = require('fs');

const lines = fs.readFileSync(0, 'utf8').trim().split(/\r?\n/);

const A = lines[0].trim();
const B = lines[1].trim();

const [h1, m1, s1] = A.split(':').map(Number);
const [h2, m2, s2] = B.split(':').map(Number);

let h = h2 - h1;
let m = m2 - m1;
let s = s2 - s1;

if (s < 0) { s += 60; m -= 1; }
if (m < 0) { m += 60; h -= 1; }
if (h < 0) { h += 24; }

const pad = (x) => x.toString().padStart(2, '0');
console.log(`${pad(h)}:${pad(m)}:${pad(s)}`);
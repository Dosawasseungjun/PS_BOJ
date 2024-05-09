use std::{io::{stdin, Read}};

fn main() {
    let mut buf = String::new();
    let mut out = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = buf.next().unwrap();
    let r1 = buf.next().unwrap();
    let c1 = buf.next().unwrap();
    let r2 = buf.next().unwrap();
    let c2 = buf.next().unwrap();
    
    for i in r1..r2+1 {
        for j in c1..c2+1{
            let y = i % (2*n - 1);
            let x = j % (2*n - 1);
            let k = i32::abs(y - n + 1) + i32::abs(x - n + 1);
            if k <= n-1 {
                out += &(('a' as i32 + (k % 26)) as u8 as char).to_string();
            }else{
                out += ".";
            }
        }
        out += "\n";
    }
    println!("{out}")
}

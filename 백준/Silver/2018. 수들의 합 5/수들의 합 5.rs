use std::{io::{stdin, Read}, vec};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let mut n = buf.next().unwrap();
    
    let mut res = 0 as i64;
    let mut d = 1;
    while n > (d - 1) * d / 2 {
        let k = n - (d-1) * d / 2;
        if k % d == 0 {
            res += 1;
        }
        d += 1;
    }
    
    println!("{}", res);
}
 
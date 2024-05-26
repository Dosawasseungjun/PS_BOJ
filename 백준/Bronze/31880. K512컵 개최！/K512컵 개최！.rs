use std::{io::{stdin, Read}, vec};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let n = buf.next().unwrap();
    let m = buf.next().unwrap();
    let mut res = 0;
    for i in 0..n{
        let a = buf.next().unwrap();
        res += a;
    }
    for i in 0..m{
        let b = buf.next().unwrap();
        if b != 0 {res *= b;}
    }
    println!("{}", res);
}

use std::{io::{stdin, Read}};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = buf.next().unwrap();
    let x = buf.next().unwrap();
    let s = buf.next().unwrap();
    let mut ok = false;
    for _ in 0..n{
        let kx = buf.next().unwrap();
        let ks = buf.next().unwrap();
        if kx <= x && ks > s{
            ok = true;
        }
    }
    if ok {
        println!("YES")
    }else{
        println!("NO")
    }
}

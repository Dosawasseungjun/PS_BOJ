use std::{io::{stdin, Read}, vec};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = buf.next().unwrap() as usize;
    let mut a = vec![0 ; n];
    for i in 0..n{
        a[i] = buf.next().unwrap();
    }
    if n <= 2 {
        if n == 2 && a[0] == a[1]{
            println!("{}", a[0]);
        }else{println!("A");}
    }else {
        let mut ok : bool = true;
        // a[1] = p * a[0] + q
        // a[2] = p * a[1] + q
        // a[2] - a[1] = p(a[1] - a[0])
        let mut p = 0;
        let mut q = 0;
        if a[1] != a[0] {
            p = if (a[2] - a[1]) % (a[1] - a[0]) == 0 {(a[2] - a[1]) / (a[1] - a[0])} else {1001};
        }
        if p == 1001 {ok = false}
        else {q = a[1] - p * a[0]} 
        if ok {
            for i in 2..n{
                if a[i] != p * a[i-1] + q {
                    ok = false;
                }
            }
        }

        if ok {
            println!("{}", p * a[n-1] + q);
        }else{
            println!("B");
        }
    }
}
 
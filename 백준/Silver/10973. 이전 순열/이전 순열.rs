use std::{collections::btree_map::Keys, io::{stdin, Read}, vec};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = buf.next().unwrap();
    let mut a = vec![0; n];
    for i in 0..n{
        a[i] = buf.next().unwrap();
    }
    let mut idx = 0;
    for i in (1..n).rev(){
        if a[i-1] > a[i] {
            idx = i;
            break;
        }
    }
    if idx != 0 {
        let mut swap_idx = 0;
        let mut mx = 0;
        for i in (idx..n).rev(){
            if mx < a[i] && a[i] < a[idx-1]{
                mx = a[i];
                swap_idx = i;
            }
        }
        let mut tmp = a[idx-1];
        a[idx - 1] = a[swap_idx];
        a[swap_idx] = tmp;
        let mut rng = idx..n;
        a[rng].sort_by(|p, q| q.cmp(p));
        let mut res = String::new();
        for j in 0..n{
            res += &a[j].to_string();
            res += " "
        }
        println!("{}", res)
    }else {
        println!("-1");
    }
}
 
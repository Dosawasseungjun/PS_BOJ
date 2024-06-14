use std::{io::{stdin, Read}, vec};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut n = buf.next().unwrap();
    let mut a = vec![0;(n+1) as usize];
    for i  in 1..(n+1) as usize {a[i] = buf.next().unwrap();}
    let INF = 1E9 as i32+1;
    let mut dp = vec![vec![-INF; 2];(n+1) as usize];
    dp[1][0] = a[1];
    dp[1][1] = 0;
    let mut res = dp[1][0];
    for i in 2..(n+1) as usize{
        dp[i][0] = std::cmp::max(a[i], dp[i-1][0]+a[i]);
        dp[i][1] = std::cmp::max(std::cmp::max(a[i], dp[i-1][1] + a[i]), dp[i-1][0]);
        res = std::cmp::max(res, std::cmp::max(dp[i][0], dp[i][1]));
    }
    println!("{}", res);
}
 